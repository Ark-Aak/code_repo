#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 35;
int n, m, x[MAXN], y[MAXN];
int seq[MAXN], Ans;

void dfs(int step, int mxn, int mxm, int n, int m, vector <int> &a, vector <int> &b) {
	/* cerr << step << " " << mxn << " " << mxm << " " << n << " " << m << " " << a.size() << " " << b.size() << endl; */
	if (step > mxn + mxm) {
		vector <int> c;
		rep (i, 1, mxn + mxm) c.push_back(seq[i]);
		int ans = 2;
		int pt = 2, lstans = 2;
		bool flg = c[0] > c[1];
		while (pt < c.size()) {
			if ((c[pt - 1] > c[pt]) == flg) lstans++, ans = max(ans, lstans);
			else lstans = 2, flg ^= 1;
			pt++;
		}
		Ans = min(ans, Ans);
		return;
	}
	if (n <= mxn) {
		seq[step] = a[n - 1];
		dfs(step + 1, mxn, mxm, n + 1, m, a, b);
	}
	if (m <= mxm) {
		seq[step] = b[m - 1];
		dfs(step + 1, mxn, mxm, n, m + 1, a, b);
	}
}

int f(vector <int> a, vector <int> b) {
	Ans = 1e9;
	dfs(1, a.size(), b.size(), 1, 1, a, b);
	return Ans % 1000000007;
}

int ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("merge.in", "r", stdin);
	freopen("merge.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) x[i] = read();
	rep (i, 1, m) y[i] = read();
	rep (l1, 1, n) {
		rep (r1, l1, n) {
			rep (l2, 1, m) {
				rep (r2, l2, m) {
					vector <int> a, b;
					rep (i, l1, r1) a.push_back(x[i]);
					rep (i, l2, r2) b.push_back(y[i]);
					/* cerr << l1 << " " << r1 << " " << l2 << " " << r2 << endl; */
					ans[f(a, b)]++;
				}
			}
		}
	}
	/* cerr << "1" << endl; */
	rep (i, 1, n + m) print(ans[i]), putchar(32);
	return 0;
}
