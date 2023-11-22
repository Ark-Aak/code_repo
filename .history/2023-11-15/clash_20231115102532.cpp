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
int n, m, p, Q, val[MAXN], bel[MAXN];
vector <int> G[MAXN];

queue <int> q;

void bfs(int st, int dis, int id) {
	while (q.size()) q.pop();
	if (val[st] >= dis) return;
	q.push(st);
	int d = dis;
	while (q.size()) {
		int tp = q.front(); q.pop();
		val[tp] = max(val[tp], dis);
		if (!bel[tp]) bel[tp] = id;
		for (auto v : G[tp]) {
			q.push(v);
		}
		dis--;
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("clash.in", "r", stdin);
	freopen("clash.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(p), read(q);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	return 0;
}