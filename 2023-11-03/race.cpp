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

const int MAXN = 5e5 + 5;

int n, _dfn;
vector <int> G[MAXN];
int dfn[MAXN], dep[MAXN], hSon[MAXN], fa[MAXN], siz[MAXN], top[MAXN];

void getDep(int u, int step, int fa) {
	::fa[u] = fa;
	dep[u] = step;
	siz[u] = 1;
	for (auto x : G[u]) {
		if (x == fa) continue;
		getDep(x, step + 1, u);
		if (siz[hSon[u]] < siz[x]) hSon[u] = x;
		siz[u] = max(siz[u], siz[x] + 1);
	}
}

void getDFN(int u, int h) {
	dfn[u] = ++_dfn;
	top[u] = h;
	if (!hSon[u]) return;
	getDFN(hSon[u], h);
	for (auto x : G[u]) {
		if (x == fa[u] || x == hSon[u]) continue;
		getDFN(x, x);
	}
}

int _id;

vector <int> chains[MAXN];

void getChain(int u, int id) {
	chains[id].emplace_back(u);
	if (!hSon[u]) return;
	getChain(hSon[u], id);
	for (auto x : G[u]) {
		if (x == fa[u] || x == hSon[u]) continue;
		getChain(x, ++_id);
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getDep(1, 1, 1);
	getDFN(1, 1);
	getChain(1, ++_id);
	sort(chains + 1, chains + 1 + _id, [](vector <int> a, vector <int> b) {
		return a.size() > b.size();
	});
	ll ans = 0;
	rep (i, 1, _id) {
		ans += chains[i].size() * (_id - i + 1);
	}
	print(ans);
	return 0;
}
