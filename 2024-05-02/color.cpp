#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

const int MAXN = 1005;
int n, p[MAXN];
vector <int> G[MAXN];
int ans[MAXN][MAXN];
int col[MAXN], vis[MAXN];

bool dfs(int u, int mxc) {
	map <int, int> buc;
	vis[u] = 1;
	for (auto v : G[u]) {
		if (!vis[v]) continue;
		buc[col[v]] = 1;
	}
	if (buc.size() < mxc) {
		rep (i, 1, mxc) if (!buc[i]) { col[u] = i; break; }
		for (auto v : G[u]) {
			if (vis[v]) continue;
			if (!dfs(v, mxc)) return false;
		}
		return true;
	}
	else return false;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) p[i] = read();
	rep (l, 1, n) {
		rep (r, l, n) {
			rep (i, 1, n) G[i].clear();
			rep (i, l, r) {
				_rep (j, i - 1, l) if (p[j] < p[i]) {
					G[i].push_back(j);
					G[j].push_back(i);
					break;
				}
				_rep (j, i - 1, l) if (p[j] > p[i]) {
					G[i].push_back(j);
					G[j].push_back(i);
					break;
				}
				rep (j, i + 1, r) if (p[j] < p[i]) {
					G[i].push_back(j);
					G[j].push_back(i);
					break;
				}
				rep (j, i + 1, r) if (p[j] > p[i]) {
					G[i].push_back(j);
					G[j].push_back(i);
					break;
				}
			}
			memset(vis, 0, sizeof vis);
			memset(col, 0, sizeof col);
			rep (i, 1, n) {
				bool flg = 1;
				rep (j, 1, n) {
					if (!vis[j]) {
						if (!dfs(j, i)) {
							flg = 0;
							break;
						}
					}
				}
				if (flg) {
					ans[l][r] = i;
					break;
				}
			}
		}
	}
	print(ans[1][n]), puts("");
	int q = read();
	rep (i, 1, q) {
		int l = read(), r = read();
		int mx = 0, cnt = 0;
		rep (j, l, r) {
			rep (k, j, r) {
				if (ans[j][k] > mx) mx = ans[j][k], cnt = 0;;
				if (ans[j][k] == mx) cnt++;
			}
		}
		print(mx), putchar(32), print(cnt), puts("");
	}
	return 0;
}
