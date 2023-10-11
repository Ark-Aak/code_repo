#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

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

const int MAXN = 1e5 + 5;
int n;

struct node {
	int p1, p2, p3, p4, c;
	bool operator < (const node &t) const {
		return c < t.c;
	}
} m[MAXN];

int color[MAXN << 2], col;
int fa[MAXN << 2];
vector <int> G[MAXN << 2];
map <pair <int, int>, int> id;

#define mp make_pair

void dfs(int x, int _col) {
	color[x] = _col;
	for (auto v : G[x]) {
		if (!color[v]) dfs(v, _col);
	}
}

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(y)] = find(x);
}

int cnt;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) {
		read(m[i].c), read(m[i].p1), read(m[i].p2);
		read(m[i].p3), read(m[i].p4);
		id[mp(i, m[i].p1)] = ++cnt;
		id[mp(i, m[i].p2)] = ++cnt;
		id[mp(i, m[i].p3)] = ++cnt;
		id[mp(i, m[i].p4)] = ++cnt;
	}
	sort(m + 1, m + 1 + n);
	rep (i, 1, cnt) if (!color[i]) dfs(i, ++col);
	rep (i, 1, col) fa[i] = i;
	int cnt = 0;
	rep (i, 1, n) {
		if (cnt == col - 1) break;
		if (find(color[m[i].p1]) != find(color[m[i].p3])) {
		
		}
	}
	return 0; 
}
