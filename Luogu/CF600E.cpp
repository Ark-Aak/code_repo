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
int n, c[MAXN], siz[MAXN], hSon[MAXN];

vector <int> G[MAXN];

void getSiz(int u, int fa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		getSiz(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[hSon[u]]) hSon[u] = v;
	}
}

void dfs(int u, int fa, int p) {

}

int main() {
	read(n);
	rep (i, 1, n) read(c[i]);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	return 0;
}
