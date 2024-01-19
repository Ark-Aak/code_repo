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

const int MAXN = 1e6 + 5, MOD = 998244353;
int C[6][6], T, t[MAXN][26], ch[MAXN][26], fail[MAXN], tot;
int fav[MAXN], fa[MAXN], a[MAXN], b[MAXN], e[MAXN], bfs[MAXN];
int f[MAXN][6], g[MAXN][6], c[MAXN], d[MAXN];

void insert(string s, int w) {
	int u = 0;
	for (auto i : s) {
		int c = i - 'a';
		if (!ch[u][c]) ch[u][c] = ++tot, fav[tot] = c, fa[tot] = u;
		u = ch[u][c];
	}
	a[u] += w, e[u] += w;
	a[u] %= MOD, e[u] %= MOD;
}

signed main() {
	rep (i, 0, 5) C[i][0] = 1;
	rep (i, 0, 5) rep (j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	cin >> T;
	while (T --> 0) {
		memset(ch, 0, sizeof ch);
		memset(fail, 0, sizeof fail);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(e, 0, sizeof e);
		tot = 0;
		string s;
		cin >> s;
		insert(s, 0);
		int m;
		cin >> m;
		rep (i, 1, m) {
			string t;
			int w;
			cin >> t >> w;
			insert(t, w);
		}
		rep (i, 0, tot) {
			rep (j, 0, 25) {
				t[i][j] = ch[i][j];
			}
		}
		int head = 1, tail = 0;
		rep (i, 0, 25) {
			if (ch[0][i]) bfs[++tail] = ch[0][i];
		}
		while (head != tail + 1) {
			int u = bfs[head++];
			rep (i, 0, 25) {
				if (ch[u][i]) {
					fail[ch[u][i]] = ch[fail[u]][i];
					bfs[++tail] = ch[u][i];
				}
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		rep (i, 1, tail) a[bfs[i]] = (a[bfs[i]] + a[fail[bfs[i]]]) % MOD;
		rep (i, 1, tail) {
			int u = bfs[i];
			b[u] = (b[u] + a[u]) % MOD;
			rep (j, 0, 25) {
				if (t[u][j]) {
					b[t[u][j]] = (b[t[u][j]] + b[u]) % MOD;
				}
			}
		}
		int ans = 0;
		f[0][0] = 1;
		g[0][0] = 1;
		rep (i, 1, tot) {
			int v = bfs[i], u = fa[v], val = fav[v];
			rep (j, 0, 5) g[v][j] = g[u][j];
			for (int x = fail[u]; !t[x][val]; x = fail[x]) {
				rep (j, 0, 5) g[v][j] = (g[v][j] + g[x][j]) % MOD;
				if (x == 0) break;
			}
			for (int j = 0, cur = 1; j <= 5; j++) {
				c[j] = cur, cur = (1ull * cur * (a[v] - e[v] + MOD)) % MOD;
			}
			rep (j, 0, 5) {
				int sum = 0;
				rep (k, 0, j)
					sum = (sum + 1ull * C[j][k] * c[k] * g[v][j - k]) % MOD;
				d[j] = sum;
			}
			for (int j = 0, cur = 1; j <= 5; j++)
				d[j] = (d[j] - cur + MOD) % MOD, cur = 1ull * cur * (b[v] - e[v] + MOD) % MOD;
			for (int j = 0, cur = 1; j <= 5; j++)
				d[j] = (d[j] + cur) % MOD, cur = 1ull * cur * b[v] % MOD;
			rep (j, 0, 5) g[v][j] = d[j];
			rep (j, 0, 5) f[v][j] = f[fail[v]][j], f[v][j] = (f[v][j] + g[v][j]) % MOD;
		}
		for (int i = 0, u = 0; i < (int) s.length(); i++)
			u = ch[u][s[i] - 97], ans = (ans + f[u][5]) % MOD;
		print((ans + MOD) % MOD), putchar(10);
	}
	return 0;
}
