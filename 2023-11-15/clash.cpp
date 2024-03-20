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

const int MAXN = 1e5 + 5;
int n, m, p, Q, val[MAXN], bel[MAXN], dis[MAXN];
vector <int> G[MAXN];

queue <int> q;

void bfs(int st, int d, int id) {
	while (q.size()) q.pop();
	if (val[st] >= d) return;
	q.push(st);
	dis[st] = 0;
	val[st] = d;
	while (q.size()) {
		int tp = q.front(); q.pop();
		if (!bel[tp]) bel[tp] = id;
		if (dis[tp] >= d) continue;
		for (auto v : G[tp]) {
			if (val[tp] - 1 > val[v]) {
				dis[v] = dis[tp] + 1, val[v] = val[tp] - 1, q.push(v);
			}
		}
	}
}

int b[MAXN], c[MAXN], d[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("clash.in", "r", stdin);
	freopen("clash.out", "w", stdout);
#endif
#endif
	memset(val, -1, sizeof val);
	read(n), read(m), read(p), read(Q);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, Q) {
		read(b[i]), read(c[i]), read(d[i]);
	}
	_rep (i, Q, 1) {
		bfs(c[i], d[i], b[i]);
	}
	rep (i, 1, n) {
		print(bel[i]), putchar(10);
	}
	return 0;
}