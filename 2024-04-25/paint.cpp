#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

const int MOD = 1e9 + 7;
int N;

struct Mat {
	int mat[50][50];

	Mat() {
		rep (i, 0, N - 1) rep (j, 0, N - 1) mat[i][j] = 0;
		rep (i, 0, N - 1) mat[i][i] = 1;
	}

	Mat operator * (Mat t) const {
		Mat res;
		rep (i, 0, N - 1) {
			rep (j, 0, N - 1) {
				res.mat[i][j] = 0;
				rep (k, 0, N - 1) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * t.mat[k][j] % MOD) % MOD;
				}
			}
		}
		return res;
	}
};

int n, t, k;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

Mat qpow(Mat a, int b) {
	Mat res;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

vector <vector <int> > stats;

void dfs(vector <int> &stat, int sum) {
	if (sum == n) {
		stats.push_back(stat);
		return;
	}
	if (stat.size() && sum + (int) stat.size() <= n) {
		vector <int> nstat = stat;
		for (auto &v : nstat) v++;
		dfs(nstat, sum + stat.size());
	}
	vector <int> nstat = stat;
	nstat.push_back(1);
	sort(nstat.begin(), nstat.end());
	dfs(nstat, sum + 1);
}

map <vector <int>, int> id;
map <int, vector <int> > tid;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
#endif
#endif
	n = read(), t = read(), k = read();
	const int inv = qpow(n * n, MOD - 2);
	vector <int> stat;
	dfs(stat, 0);
	int cnt = 0;
	for (auto i : stats) id[i] = cnt, tid[cnt] = i, cnt++;
	N = stats.size();
	Mat S;
	rep (i, 0, N - 1) {
		rep (j, 0, N - 1) {
			S.mat[i][j] = 0;
		}
	}
	for (auto i : stats) {
		vector <int> nv;
		int cnt = 0;
		for (auto v : i) {
			rep (j, 1, v) nv.push_back(cnt);
			cnt++;
		}
		rep (j, 0, nv.size() - 1) {
			rep (k, 0, nv.size() - 1) {
				vector <int> nt = nv;
				nt[j] = nt[k];
				vector <int> nb(n);
				for (auto v : nt) nb[v]++;
				sort(nb.begin(), nb.end());
				while (nb.size() && (*nb.begin() == 0)) {
					nb.erase(nb.begin());
				}
				int ID1 = id[i];
				int ID2 = id[nb];
				S.mat[ID1][ID2] += inv;
				S.mat[ID1][ID2] %= MOD;
			}
		}
	}
	S = qpow(S, t);
	int ans = 0;
	vector <int> fir;
	rep (i, 1, n) fir.push_back(1);
	rep (i, 0, N - 1) {
		if ((int) tid[i].size() >= k) ans = (ans + S.mat[id[fir]][i]) % MOD;
	}
	print(ans);
	return 0;
}
