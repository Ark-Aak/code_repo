#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MOD = 998244353;
const int MAXN = 90005;
vector <int> G[MAXN];
int n, m, ans, svash[MAXN], aak[MAXN];
int f[2][MAXN];
string str;

void dfs(int u, int fa) {
	if (svash[u] != -1) return;
	svash[u] = 0;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		if (str[u] == 'W') svash[u] = max(svash[u], svash[v] + 1);
		else svash[u] = min(svash[u], svash[v] - 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	cin >> str;
	str = ' ' + str;
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].push_back(v);
	}
	rep (i, 1, n) svash[i] = -1;
	rep (i, 1, n) {
		if (svash[i] == -1) dfs(i, 0);
	}
	sort(svash + 1, svash + 1 + n);
	reverse(svash + 1, svash + 1 + n);
	f[0][0] = 1;
	rep (i, 1, n) {
        memset(f[i & 1], 0, sizeof(f[i & 1]));
		rep (j, 0, n * n) {
			f[i & 1][j] = f[(i & 1) ^ 1][j];
			if (j - svash[i] >= 0 && j - svash[i] <= n * n)
				(f[i & 1][j] += f[(i & 1) ^ 1][j - svash[i]]) %= MOD;
        }
    }
    rep (i, 1, n * n) (ans += f[n & 1][i]) %= MOD;
	print(ans);
	return 0;
}
