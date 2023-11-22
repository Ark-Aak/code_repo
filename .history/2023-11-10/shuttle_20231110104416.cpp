#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 1e5 + 5;
int n, m;
int x[MAXN], h[MAXN];

priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q;
vector <pair <int, int> > G[MAXN];
int dis[MAXN];
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

int cnt;
int lst[MAXN], lsh[MAXN];

struct bridge {
	int l, r, y;
} b[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("shuttle.in", "r", stdin);
    freopen("shuttle.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	cnt = n;
	rep (i, 1, n) {
		read(x[i]), read(h[i]);
		lst[i] = i; lsh[i] = 0;
	}
	rep (i, 1, m) {
		read(b[i].l), read(b[i].r), read(b[i].y);
		b[i].l = x[b[i].l + 1], b[i].r = x[b[i].r + 1];
	}
	sort(b + 1, b + 1 + m, [](bridge a, bridge b) {
		return a.y < b.y;
	});
	rep (i, 1, m) {
		rep (j, 1, n) {
			int lid = 0, lx = 0;
			if (b[i].l <= x[j] && x[j] <= b[i].r) {
				//交点 (x[j], y[i])
				++cnt;
				G[cnt].emplace_back(make_pair(lst[j], b[i].y - lsh[j]));
				G[lst[j]].emplace_back(make_pair(cnt, b[i].y - lsh[j]));
				lst[j] = cnt;
				lsh[j] = b[i].y;
				if (lid != 0 && lx != 0) {
					G[lid].emplace_back(make_pair(cnt, x[j] - lx));
					G[cnt].emplace_back(make_pair(lid, x[j] - lx));
				}
				lid = cnt, lx = x[j];
			}
		}
	}
	int s, t;
	read(s), read(t);
	dijkstra(s);
	rep (i, 1, cnt) cout << dis[i] << " ";
	cout << endl;
	if (dis[t] >= 0x3f3f3f3f3f3f3f3f) print(-1);
	else print(dis[t]);
	return 0;
}