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
int stk[MAXN];

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
int mn[MAXN], lst[MAXN];

void sieve() {
	mn[1] = 1;
	rep (i, 2, 1e6) {
		if (!mn[i]) mn[i] = i, p.emplace_back(i);
		for (auto j : p) {
			if (i * j > 1e6) break;
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
	sieve();
	rep (i, 1, n) fa[i] = i;
	rep (i, 1, n) cin >> v[i];
	rep (i, 1, n) {
		int tp = v[i];
		while (tp > 1) {
			merge(lst[mn[tp]], i);
			lst[mn[tp]] = i;
			int k = mn[tp];
			while (tp % k == 0) tp /= k;
		}
	}
	rep (i, 1, n) {
		int top = 0;
		int x = v[i] + 1;
		while (x > 1) {
			if (lst[mn[x]]) stk[++top] = lst[mn[x]];
			int k = mn[x];
			while (x % k == 0) x /= k;
		}
		if (v[i] > 1) stk[++top] = i;
		rep (j, 2, top) {
			rep (k, 1, j - 1) {
				insert(stk[k], stk[j]);
			}
		}
	}
	while (q --> 0) {
		int x, y;
		cin >> x >> y;
		if (x == y) {
			cout << "0\n";
			continue;
		}
		if (v[x] == 1 || v[y] == 1) {
			cout << "-1\n";
			continue;
		}
		x = find(x), y = find(y);
		if (x == y) {
			cout << "0\n";
		}
		else if (g[x][y]) {
			cout << "1\n";
		}
		else {
			cout << "2\n";
		}
	}
	return 0;
}