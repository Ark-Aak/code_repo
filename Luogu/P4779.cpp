#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e5 + 5;
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
vector <pair <int, int> > G[MAXN];
int n, m, s, dis[MAXN];
bitset <MAXN> vis;

void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0; q.push(make_pair(0, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : G[u]) {
			int t = v.first, val = v.second;
			if (dis[t] > dis[u] + val) {
				dis[t] = dis[u] + val;
				if (!vis[t]) q.push(make_pair(dis[t], t));
			}
		}
	}
}

int main() {
	cin >> n >> m >> s;
	rep (i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		G[u].emplace_back(make_pair(v, w));
	}
	dijkstra(s);
	rep (i, 1, n) cout << dis[i] << " ";
	return 0; 
}
