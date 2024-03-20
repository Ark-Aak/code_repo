#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 355;
const int INF = 1e18;
int n, m, C;
vector <int> G[MAXN];
int dis[MAXN][MAXN];
vector <int> a;
bool mk[MAXN];
int ans = INF;

void dfs(int step) {
	if (step > n) {
		int sum = 0;
		rep (i, 1, n) sum += mk[i];
		if (sum < 1) return;
		int cost = sum * C;
		for (auto i : a) {
			int minn = INF;
			rep (j, 1, n) if (mk[j]) minn = min(minn, dis[i][j]);
			cost += minn;
		}
		ans = min(ans, cost);
		return;
	}
	mk[step] = 0;
	dfs(step + 1);
	mk[step] = 1;
	dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("post.in", "r", stdin);
	freopen("post.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), C = read();
	memset(dis, 0x3f, sizeof dis);
	rep (i, 1, n - 1) {
		int u = read(), v = read(), w = read();
		dis[u][v] = dis[v][u] = w;
	}
	rep (i, 1, n) dis[i][i] = 0;
	rep (i, 1, m) {
		int x = read();
		a.push_back(x);
	}
	rep (k, 1, n)
		rep (i, 1, n)
			rep (j, 1, n)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	dfs(1);
	print(ans);
	return 0;
}
