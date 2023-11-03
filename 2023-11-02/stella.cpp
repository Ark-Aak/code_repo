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

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 1e6 + 5;
pair <int, int> querys[MAXN];
int pos[MAXN], st[MAXN][21];

int n, m;

void init() {
	rep (i, 1, n) st[i][0] = pos[i];
	rep (j, 1, 20)
		for (int i = 1; i <= n - (1 << j) + 1; i++)
			st[i][j] = 1e18;
	rep (j, 1, 20) {
		rep (i, 1, (n - (1 << j) + 1)) {
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int l, int r) {
	int lg = log2(r - l + 1);
	return min(st[l][lg], st[r - (1 << lg) + 1][lg]);
}

int sum[MAXN << 2];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int val) {
	if (!x) return;
	while (x <= n) {
		sum[x] += val;
		x += lowbit(x);
	}
}

int getsum(int x) {
	int ans = 0;
	while (x) {
		ans += sum[x];
		x -= lowbit(x);
	}
	return ans;
}

int Q(int l, int r) {
	return getsum(r) - getsum(l - 1);
}

vector <int> mdf[MAXN];

signed main() {
	read(n), read(m);
	memset(pos, 0x7f, sizeof pos);
	rep (i, 1, m) {
		int op, l, r = -1;
		read(op);
		if (op == 1) read(l), pos[l] = min(pos[l], (int) i);
		else read(l), read(r);
		querys[i] = make_pair(l, r);
	}
	init();
	rep (i, 1, n) {
		add(i, 1);
		int last = 0;
		for (int j = 1; j <= n; j += i) {
			last = max(last, min(query(j, min(j + i - 1, n)), m + 1));
			mdf[last].emplace_back(i);
		}
	}
	rep (i, 1, m) {
		if (querys[i].second == -1) for (auto x : mdf[i]) add(x, 1);
		else {
			print(Q(querys[i].first, querys[i].second));
			putchar(10);
		}
	}
	return 0;
}
