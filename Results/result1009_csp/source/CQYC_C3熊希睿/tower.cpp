#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

typedef long long ll;
typedef pair <int, int> pii;

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

const int MAXN = 505;
int e[MAXN][MAXN], a[500005];
int n, k, f[500005];
int rgt[55], lft[55];
vector <int> G[500005];

namespace Dijkstra {
	int vis[500005], dis[500005];
	priority_queue <pii, vector <pii>, greater <pii> > q;

	void dijkstra(int s) {
		memset(dis, 0x3f, sizeof dis);
		dis[s] = 0;
		q.push({0, s});
		while (!q.empty()) {
			int id = q.top().second;
			q.pop();
			if (vis[id]) continue;
			vis[id] = 1;
			for (auto x : G[id]) {
				int val = abs(x - id);
				if (dis[x] > dis[id] + val) {
					dis[x] = dis[id] + val;
					if (!vis[x]) q.push({dis[x], x});
				}
			}
		}
	}
}

using Dijkstra::dijkstra;
using Dijkstra::dis;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
#endif
#endif
	memset(lft, 0x3f, sizeof lft);
	read(n), read(k);
	rep (i, 1, n) read(a[i]), rgt[a[i]] = max(rgt[a[i]], 1ll * i), lft[a[i]] = min(lft[a[i]], 1ll * i);
	rep (i, 1, k) {
		string s;
		cin >> s;
		rep (j, 1, k) {
			e[i][j] = (s[j - 1] == '1');
			//if (e[i][j] == 0) e[i][j] = INT_MAX;
		}
	}
	rep (i, 1, n) {
		rep (j, 1, k) {
			if (!e[a[i]][j]) continue;
			else G[i].emplace_back(rgt[j]), G[i].emplace_back(lft[j]);
		}
	}
	dijkstra(1);
	if (dis[n] == 0x3f3f3f3f3f3f3f3f) {
		cout << -1;
	}
	else cout << dis[n];
	return 0; 
}
