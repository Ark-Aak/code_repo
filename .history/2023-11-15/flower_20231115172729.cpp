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

const int MAXN = 1e6 + 5;
int fa[MAXN], v[MAXN], n, q;

unordered_map <int, bool> g[MAXN];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	if (!x || !y) return;
	fa[find(y)] = find(x);
}

void insert(int x, int y) {
	if (!x || !y) return;
	if (find(x) == find(y)) return;
	g[find(x)][find(y)] = g[find(y)][find(x)] = 1;
}

vector <int> p;
int mn[MAXN];

void sieve() {
	mn[1] = 1;
	rep (i, 2, m) {
		if (!mn[i]) mn[i] = i, p.emplace_back(i);
		for (auto j : p) {
			if (i * j > n) break;
			mn[i * j] = j;
			if (i % j == 0) break;
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
#endif
#endif
	int n, q;
	cin >> n >> q;
	rep (i, 1, n) fa[i] = i;
	rep (i, 1, n) cin >> v[i];
	rep (i, 1, n) {
		int tp = v[i];
		while (tp > 1) {

		}
	}
	return 0;
}