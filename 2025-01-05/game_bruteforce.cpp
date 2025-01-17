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

const int MAXN = 1e5 + 5;
int n, w[MAXN], ans[MAXN];
vector <int> G[MAXN];
vector <int> val[MAXN];
mt19937 rnd(time(0));

void dfs(int u, int fa) {
	val[u].push_back(w[u]);
	int fans = -1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		for (auto i : val[v]) {
			val[u].push_back(i);
		}
		vector <int>().swap(val[v]);
	}
	if (G[u].size() > 1 || fa == 0) {
		rep (i, 0, (int) val[u].size() - 1) {
			int tans = 1e9;
			rep (j, i + 1, (int) val[u].size() - 1) {
				if (i == j) continue;
				tans = min(tans, val[u][i] ^ val[u][j]);
			}
			fans = max(fans, tans);
		}
	}
	ans[u] = fans;
}

signed main() {
	n = read();
	rep (i, 1, n) w[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, 0);
	rep (i, 1, n) print(ans[i]), puts("");
	return 0;
}
