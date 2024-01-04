#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

#define int ll

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e3 + 5;

struct node {
	int x, y, u, v, k, id;
};

node Q[MAXN * 1000];

int n, q, a[MAXN][MAXN];

int sum[MAXN][MAXN], len;

int lowbit(int x) {
	return x & -x;
}

void add(int x, int y, int val) {
	if (x == 0 || y == 0) return;
	for (int i = x; i <= n; i += lowbit(i))
		for (int j = y; j <= n; j += lowbit(j))
			sum[i][j] += val;
}

int query(int x, int y) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i))
		for (int j = y; j; j -= lowbit(j))
			res += sum[i][j];
	return res;
}

int ans[MAXN * 1000];
node Q1[MAXN * 1000], Q2[MAXN * 1000];

#define mid ((L + R) >> 1)

void solve(int qL, int qR, int L, int R) {
	if (qL > qR) return;
	if (L == R) {
		rep (i, qL, qR) if (Q[i].id != 0) ans[Q[i].id] = L;
		return;
	}
	int len1 = 0, len2 = 0;
	rep (i, qL, qR) {
		if (Q[i].id == 0) {
			if (Q[i].k <= mid) add(Q[i].x, Q[i].y, 1), Q1[++len1] = Q[i];
			else Q2[++len2] = Q[i];
		}
		else {
			int sum = query(Q[i].u, Q[i].v)
				- query(Q[i].x - 1, Q[i].v)
				- query(Q[i].u, Q[i].y - 1)
				+ query(Q[i].x - 1, Q[i].y - 1);
			if (sum >= Q[i].k) Q1[++len1] = Q[i];
			else Q[i].k -= sum, Q2[++len2] = Q[i];
		}
	}
	rep (i, 1, len1) Q[qL + i - 1] = Q1[i];
	rep (i, 1, len2) Q[qL + len1 + i - 1] = Q2[i];
	rep (i, qL, qL + len1 - 1) {
		if (Q[i].id == 0 && Q[i].k <= mid) add(Q[i].x, Q[i].y, -1);
	}
	solve(qL, qL + len1 - 1, L, mid);
	solve(qL + len1, qR, mid + 1, R);
}

#undef mid

signed main() {
	read(n), read(q);
	rep (i, 1, n) {
		rep (j, 1, n) {
			read(a[i][j]);
			Q[++len] = {i, j, 0, 0, a[i][j], 0};
		}
	}
	rep (i, 1, q) {
		int x, y, u, v, k;
		read(x), read(y), read(u), read(v), read(k);
		Q[++len] = {x, y, u, v, k, i};
	}
	solve(1, len, INT_MIN, INT_MAX);
	rep (i, 1, q) print(ans[i]), putchar(10);
	return 0;
}
