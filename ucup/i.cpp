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

const int MAXN = 2e5 + 5;
int T, n;
vector <int> G[MAXN];
int col[MAXN], vis[MAXN];
int canEdit0[MAXN], canEdit1[MAXN];

void bfs(int st) {
	col[st] = 0;
	vis[st] = 1;
	queue <int> q;
	q.push(st);
	while (q.size()) {
		int u = q.front();
		q.pop();
		bool flg = 0;
		for (auto v : G[u]) {
			if (!vis[v]) flg = 1, vis[v] = 1, col[v] = col[u] ^ 1, q.push(v);
		}
		if (!flg) {
			if (col[u] == 0) canEdit1[u] = 1;
			else canEdit0[u] = 1;
		}
	}
}

void solve() {
	n = read() * 2;
	rep (i, 1, n) G[i].clear();
	rep (i, 1, n) canEdit0[i] = 0;
	rep (i, 1, n) canEdit1[i] = 0;
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) col[i] = 0, vis[i] = 0;
	bfs(1);
	int sum0 = count(col + 1, col + 1 + n, 0);
	int sum1 = count(col + 1, col + 1 + n, 1);
	if (sum0 == sum1) {
		rep (i, 1, n) print(col[i]), putchar(32);
		puts("");
		return;
	}
	if (sum0 > sum1) {
		int cnt = 0;
		rep (i, 1, n) {
			if (!canEdit1[i]) continue;
			col[i] = 1;
			cnt++;
			if (sum0 - cnt == sum1 + cnt) break;
		}
		if (sum0 - cnt == sum1 + cnt) {
			rep (i, 1, n) print(col[i]), putchar(32);
			puts("");
			return;
		}
		else puts("-1");
	}
	else {
		int cnt = 0;
		rep (i, 1, n) {
			if (!canEdit0[i]) continue;
			col[i] = 0;
			cnt++;
			if (sum0 + cnt == sum1 - cnt) break;
		}
		if (sum0 + cnt == sum1 - cnt) {
			rep (i, 1, n) print(col[i]), putchar(32);
			puts("");
			return;
		}
		else puts("-1");
	}
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
