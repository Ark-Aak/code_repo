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

const int MAXN =  3e6 + 5;
int n, m, q;

struct BITMX {
	int sum[MAXN];

	void modify(int x, int val) {
		for (int o = x; o <= n; o += o & -o)
			sum[o] = max(sum[o], val);
	}

	int query(int x) {
		int res = 0;
		for (int o = x; o; o -= o & -o)
			res = max(res, sum[o]);
		return res;
	}
} tx;

struct BITMN {
	int sum[MAXN];

	BITMN() {memset(sum, 0x3f, sizeof sum);}

	void modify(int x, int val) {
		for (int o = x; o; o -= o & -o)
			sum[o] = min(sum[o], val);
	}

	int query(int x) {
		int res = 1e9;
		for (int o = x; o <= n; o += o & -o)
			res = min(res, sum[o]);
		return res;
	}
} ty;

set <int> s1[MAXN], s2[MAXN];

void updL(int x, int y)  {
	tx.modify(x - 1, y + 1);
	s1[x].erase(y), s2[y].erase(x);
	auto iter = s1[x - 1].upper_bound(y + 1);
	if (iter != s1[x - 1].begin()) updL(x - 1, *--iter);
	iter = s2[y + 1].lower_bound(x - 1);
	if (iter != s2[y + 1].end()) updL(*iter, y + 1);
}

void updR(int x, int y) {
	ty.modify(x + 1, y - 1);
	s1[x].erase(y), s2[y].erase(x);
	auto iter = s1[x + 1].lower_bound(y - 1);
	if (iter != s1[x + 1].end()) updR(x + 1, *iter);
	iter = s2[y - 1].upper_bound(x + 1);
	if (iter != s2[y - 1].begin()) updR(*--iter, y - 1);
}

void solve(int x, int y) {
	bool onU = tx.query(x - 1) <= y && y <= tx.query(x);
	bool onB = ty.query(x + 1) >= y && y >= ty.query(x);
	if (onU && onB) {
		putchar('0');
		return;
	}
	putchar('1');
	s1[x].insert(y);
	s2[y].insert(x);
	if (onU) updL(x, y);
	if (onB) updR(x, y);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tmp.in", "r", stdin);
	freopen("tmp.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(q);
	tx.modify(1, 1), ty.modify(1, 1);
	tx.modify(n, m), ty.modify(n, m);
	while (q --> 0) {
		int x, y;
		read(x), read(y);
		solve(x, y);
	}
	return 0;
}
