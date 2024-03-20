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

const int MAXN = 5e4 + 5, MAXM = 505;
int n, m, fa[MAXM], vis[MAXM], cnt;
string str[MAXN];

struct node {
	int p, x, y;
};

vector <node> p, v;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void insert(node e) {
	if (!(~e.y)) {
		if (!vis[e.x]) vis[e.x] = 1, cnt++, v.push_back(e);
		return;
	}
	int x, y;
	if ((x = find(e.x)) == (y = find(e.y))) return;
	cnt--, fa[x] = y, v.push_back(e);
}

int ans = 0;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	rep (i, 1, n) cin >> str[i], str[i] = ' ' + str[i];
	rep (i, 1, n) {
		rep (j, 1, m) fa[j] = j, vis[j] = 0;
		for (int j = 1, lst = -1; j <= m; j++) {
			if (str[i][j] == '1') {
				insert({i, j, -1});
				if (~lst) insert({i, lst, j});
				lst = j;
			}
		}
		p.push_back({-1, 0, 0});
		for (int j = 0; j <= (int) p.size() - 2;) {
			do insert(p[j++]); while (p[j].p == 1);
			if (cnt == 1) ans = max(ans, i - (p[j].p == -1 ? 0 : p[j].p));
		}
		p.swap(v), v.clear(), cnt = 0;
	}
	print(ans);
	return 0;
}
