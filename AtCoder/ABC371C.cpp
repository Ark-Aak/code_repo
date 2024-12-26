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
#define de(val) cerr << #val << " = " << (val) << endl

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

#define int ll
const int MAXN = 1e6 + 5;
int n, m1, m2, e1[9][9], e2[9][9], a[9][9];
bool vis[MAXN];
int perm[MAXN], ans = 1e16;

void dfs(int x) {
	if (x == n + 1) {
		int res = 0;
		rep (i, 1, n) {
			rep (j, 1, n) {
				if (e1[i][j] + e2[perm[i]][perm[j]] == 1) {
					res += a[perm[i]][perm[j]];
				}
			}
		}
		ans = min(ans, res);
		return;
	}
	rep (i, 1, n) {
		if (!vis[i]) {
			vis[i] = 1;
			perm[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

signed main(){
	n = read(), m1 = read();
	rep (i, 1, m1) {
		int u = read(), v = read();
		e1[u][v] = e1[v][u] = 1;
	}
	m2 = read();
	rep (i, 1, m2) {
		int u = read(), v = read();
		e2[u][v] = e2[v][u] = 1;
	}
	rep (i, 1, n) rep (j, i + 1, n) a[i][j] = read();
	dfs(1);
	print(ans), puts("");
	return 0;
}
