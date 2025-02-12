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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1.5e6 + 5;
const int MOD = 1e9 + 7;
vector <int> G[MAXN];
int n, k, ch[MAXN], flg;
bool sol;
int ans = 0;

void dfs0(int dep, int u, int fa, int tot) {
	if (dep == k) {
		if (tot != 1) flg = 1;
		return;
	}
	for (auto v : G[u]) {
		if (v ^ fa) dfs0(dep + 1, v, u, tot + ch[v]);
	}
}

void dfs1(int step) {
	if (step > n) {
		flg = 0;
		rep (i, 1, n) {
			dfs0(1, i, 0, ch[i]);
			if (flg) return;
		}
		ans++;
		sol = 1;
		ans %= MOD;
		return;
	}
	ch[step] = 0;
	dfs1(step + 1);
	ch[step] = 1;
	dfs1(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("life.in", "r", stdin);
	freopen("life.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (n <= 18) {
		dfs1(1);
		if (sol) puts("YES");
		else puts("NO");
		print(ans), puts("");
	}
	else {
		puts("YES");
		print(k), puts("");
	}
	return 0;
}
