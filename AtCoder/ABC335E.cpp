#include <bits/stdc++.h>

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

const int MAXN = 2e5 + 5;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
vector <int> G[MAXN];
int n, m, s, dis[MAXN], a[MAXN];
bitset <MAXN> vis;

void dijkstra(int s) {
	dis[s] = 1; q.push(make_pair(a[1], s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		vis[u] = 0;
		for (auto v : G[u]) {
			if (a[v] >= a[u] && dis[v] < dis[u] + (a[u] != a[v])) {
				dis[v] = dis[u] + (a[u] != a[v]);
				if (!vis[v]) q.push(make_pair(a[v], v)), vis[v] = 1;
			}
		}
	}
}

int main() {
	n = read(), m = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dijkstra(1);
	print(dis[n]);
	return 0;
}
