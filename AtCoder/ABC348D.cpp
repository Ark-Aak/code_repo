#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 205;
int n, m, v[MAXN][MAXN], maxx[MAXN][MAXN];
int mx[4] = {1, 0, -1, 0}, my[4] = {0, 1, 0, -1};
char ch[MAXN][MAXN];

signed main() {
	cin >> n >> m;
	int sx = 0, sy = 0, tx = 0, ty = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			cin >> ch[i][j];
			if (ch[i][j] == 'S')
				sx = i, sy = j;
			if (ch[i][j] == 'T')
				tx = i, ty = j;
		}
	}
	memset(maxx, -1, sizeof maxx);
	int k, x, y, z;
	cin >> k;
	while (k--) cin >> x >> y >> z, v[x][y] = z;
	if (!v[sx][sy]) return cout << "No", 0;
	priority_queue <pair <int, pair <int, int> > > q;
	maxx[sx][sy] = v[sx][sy];
	q.push({maxx[sx][sy], {sx, sy}});
	while (!q.empty()) {
		int ux = q.top().second.first, uy = q.top().second.second;
		q.pop();
		int w = maxx[ux][uy];
		if (ux == tx && uy == ty) return cout << "Yes", 0;
		rep (i, 0, 3) {
			int vx = ux + mx[i], vy = uy + my[i];
			if (vx < 1 || vx > n || vy < 1 || vy > m || ch[vx][vy] == '#' || w == 0 || maxx[vx][vy] >= max(v[vx][vy], w - 1))
				continue;
			maxx[vx][vy] = max(v[vx][vy], w - 1);
			q.push({maxx[vx][vy], {vx, vy}});
		}
	}
	cout << "No";
	return 0;
}
