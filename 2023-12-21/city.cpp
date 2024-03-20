#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5 + 5;

int n, m, X, q, now;
int fa[MAXN], cnt, tot;
int ans[MAXN][2];
vector <int> p[MAXN], _g[MAXN];

int find(int x) {
	if (x == fa[x]) return fa[x];
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fy] = fx;
}

map <int, map <int, int> > vis;

void Print() {
	rep (i, 1, now) print(ans[i][0]), putchar(32), print(ans[i][1]), putchar(10);
}

struct node {
	int v, w;
} g[500005];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), X = read(), q = read();
	rep (i, 1, n) fa[i] = i;
	while (q --> 0) merge(read(), read());
	rep (i, 1, n) p[find(i)].emplace_back(i);
	rep (i, 1, n) if (p[i].size() > 0) g[++cnt].w = p[i].size(), g[cnt].v = i;
	sort(g + 1, g + 1 + cnt, [](node a, node b){
		return a.w > b.w;
	});
	if (cnt < X) {
		puts("-1");
		return 0;
	}
	tot = 1;
	rep (i, 1, cnt - X + 1)
		for (auto v : p[g[i].v])
			_g[1].emplace_back(v);
	rep (i, cnt - X + 2, cnt) {
		++tot;
		for (auto v : p[g[i].v]) _g[tot].emplace_back(v);
	}
	rep (i, 1, tot) {
		if (_g[i].size() == 1) continue;
		rep (j, 0, _g[i].size() - 1) {
			now++;
			ans[now][0] = _g[i][j];
			ans[now][1] = _g[i][(j + 1) % _g[i].size()];
			vis[ans[now][0]][ans[now][1]] = 1;
		}
	}
	if (now > m) {
		puts("-1");
		return 0;
	}
	if (now < m) {
		rep (i, 1, tot) {
			for (auto x : _g[i]) {
				for (auto y : _g[i]) {
					if (x == y || vis[x][y] == 1) continue;
					if (now + 1 <= m) {
						now++;
						ans[now][0] = x;
						ans[now][1] = y;
						vis[x][y] = 1;
					}
					else return Print(), 0;
				}
			}
		}
	}
	if (now < m) {
		rep (i, 1, tot - 1) {
			rep (j, i + 1, tot) {
				for (auto x : _g[i]) {
					for (auto y : _g[j]) {
						if (now + 1 <= m) {
							now++;
							ans[now][0] = x;
							ans[now][1] = y;
							vis[x][y] = 1;
						}
						else return Print(), 0;
					}
				}
			}
		}
	}
	if (now < m) puts("-1");
	else Print();
	return 0;
}
