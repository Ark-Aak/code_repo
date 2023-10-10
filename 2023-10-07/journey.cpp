#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

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

const int MAXN = 1e6 + 5;
int n, m, q, ans[MAXN], dis[1005][1005];
vector <pair <int, int> > G;
vector <int> a[MAXN];

struct query {
	int l, r, s, t;
} que[MAXN];

int main() {
	read(n), read(m), read(q);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G.emplace_back(make_pair(u, v));
	}
	rep (i, 1, q) read(que[i].l), read(que[i].r),
				  read(que[i].s), read(que[i].t);
	rep (i, 1, q) ans[i] = (que[i].s == que[i].t);
	rep (i, 1, q) a[que[i].l].emplace_back(i);
	rep (i, 1, n) rep (j, 1, n) dis[i][j] = m + 1;
	_rep (i, m, 1) {
		int u = G[i - 1].first, v = G[i - 1].second;
		dis[u][v] = dis[v][u] = i;
		rep (w, 1, n) dis[u][w] = dis[v][w] =
						min(dis[u][w], dis[v][w]);
		for (auto x : a[i]) {
			ans[x] |= (dis[que[x].s][que[x].t] <= que[x].r);
		}
	}
	rep (i, 1, q) if (ans[i]) puts("Yes"); else puts("No");
	return 0; 
}
