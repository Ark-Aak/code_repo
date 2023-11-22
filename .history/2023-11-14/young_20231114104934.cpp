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
int euler_order[MAXN];
vector <int> G[MAXN];
int n, st[MAXN], ed[MAXN], md[MAXN];

void dfs(int u, int fa) {
	euler_order[++euler_order[0]] = u;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
	euler_order[++euler_order[0]] = u;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("young.in", "r", stdin);
	freopen("young.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 0);
	rep (i, 1, 2 * n) {
		if (!st[euler_order[i]]) st[euler_order[i]] = i;
		ed[euler_order[i]] = i;
		md[euler_order[i]] = (st[euler_order[i]] + ed[euler_order[i]]) >> 1 + 1;
	}

	return 0;
}