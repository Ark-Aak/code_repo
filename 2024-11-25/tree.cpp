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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e3;
int prufer[MAXN], deg[MAXN], fa[MAXN];
int n;

void gen_fa() {
	rep (i, 1, n) deg[i] = 0;
	rep (i, 1, n - 2) deg[prufer[i]]++;
	prufer[n - 1] = n;
	int pos = 1;
	rep (i, 1, n - 1) {
		while (deg[pos]) pos++;
		fa[pos] = prufer[i];
		while (i <= n - 1 && !--deg[prufer[i]] && prufer[i] < pos)
			fa[prufer[i]] = prufer[i + 1], i++;
		pos++;
	}
}

int ans[MAXN];
vector <int> G[MAXN];
int dis[MAXN];

void dfs(int step, int u, int fa, int o) {
	dis[o] += step;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(step + 1, v, u, o);
	}
}

void dfs(int step) {
	if (step > n - 2) {
		gen_fa();
		rep (i, 1, n) G[i].clear();
		// cout << n << "tree:" << endl;
		rep (i, 1, n - 1) {
			// cerr << i << " <-> " << fa[i] << endl;
			G[i].push_back(fa[i]), G[fa[i]].push_back(i);
		}
		rep (i, 1, n) dis[i] = 0;
		rep (i, 1, n) dfs(0, i, 0, i);
		rep (i, 1, n) {
			rep (j, 1, n) {
				ans[abs(dis[i] - dis[j])] = min(ans[abs(dis[i] - dis[j])], n);
			}
		}
		return;
	}
	rep (i, 1, n) prufer[step] = i, dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	int T = read();
	while (T --> 0) {
		int x = read();
		if (x == 0) {
			puts("2");
			continue;
		}
		int eCnt = ceil(sqrt(x));
		int ans = 1 + 2 * eCnt;
		if (x % 2 == 0) {
			int l = 1, r = 2e9;
			int oCnt = 2e9;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if ((mid * mid + mid) >= x) oCnt = min(oCnt, mid), r = mid - 1;
				else l = mid + 1;
			}
			ans = min(ans, 2 + 2 * oCnt);
		}
		print(ans), puts("");
	}
	return 0;
}
