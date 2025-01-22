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

const int MAXN = 605;
int n, q;
int e[MAXN][MAXN], dis[MAXN][MAXN], vis[MAXN];

void dijkstra(int s) {
	priority_queue <pii, vector <pii>, greater <pii> > q;
	memset(dis[s], 0x3f, sizeof dis[s]);
	memset(vis, 0, sizeof vis);
	dis[s][s] = 0; q.push(make_pair(0, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		rep (i, 1, n) {
			if (i == u || e[u][i] == 2) continue;
			int t = i, val = e[u][i];
			if (dis[s][t] > dis[s][u] + val) {
				dis[s][t] = dis[s][u] + val;
				if (!vis[t]) q.push(make_pair(dis[s][t], t));
			}
		}
	}
}

namespace subtask1 {

	void solve() {
		bool flg = 0;
		rep (i, 1, n) dijkstra(i);
		while (q --> 0) {
			int op = read();
			if (op == 2) {
				int a = read(), b = read();
				int c = read();
				e[a][b] = c;
				flg = 1;
			}
			else {
				if (flg) {
					rep (i, 1, n) dijkstra(i);
					flg = 0;
				}
				int a = read(), b = read();
				print(min(2, dis[a][b])), puts("");
			}
		}
	}
} // namespace subtask1

namespace subtask2 {

	void solve() {

	}
} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w" , stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n) rep (j, 1, n) e[i][j] = read();
	if (n <= 100) return subtask1::solve(), 0;
	else return subtask2::solve(), 0;
	return 0;
}
