#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 1e6 + 5;
const int MAXM = 2;
const int LG = 30;

int ans[MAXN], id[MAXN];
vector <int> _fail[MAXN];

namespace AC_Automaton {
	int ch[MAXN][MAXM], fail[MAXN], tot = 0;
	queue <int> q;

	void insert(string s, int _id) {
		int u = 0, n = s.size();
		rep (i, 0, n - 1) {
			int c = s[i] - '0';
			if (!ch[u][c]) ch[u][c] = ++tot;
			u = ch[u][c];
		}
		id[_id] = u;
	}

	void build() {
		rep (i, 0, MAXM - 1) if (ch[0][i]) q.push(ch[0][i]);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			rep (i, 0, MAXM - 1) {
				if (ch[u][i]) {
					fail[ch[u][i]] = ch[fail[u]][i];
					q.push(ch[u][i]);
				}
				else ch[u][i] = ch[fail[u]][i];
			}
		}
		rep (i, 1, tot) _fail[fail[i]].push_back(i);
	}
} // namespace AC_Automaton

using AC_Automaton::ch;
using AC_Automaton::tot;

int n, q, l[MAXN], r[MAXN];
string p[MAXN];
int f[MAXN][LG + 1][2], g[MAXN][LG + 1][2], tp;

void init() {
	rep (i, 0, tot) f[i][0][0] = ch[i][0], f[i][0][1] = ch[i][1];
	rep (i, 1, LG) {
		rep (j, 0, tot) {
			f[j][i][0] = f[f[j][i - 1][0]][i - 1][1];
			f[j][i][1] = f[f[j][i - 1][1]][i - 1][0];
		}
	}
}

void nxt(int i, int j) {
	g[tp][i][j]++;
	tp = f[tp][i][j];
}

void insert(int l, int r) {
	r++;
	rep (i, 0, LG) {
		if ((l & (1ll << i)) && l + (1ll << i) <= r) {
			nxt(i, __builtin_parityll(l));
			l += (1ll << i);
		}
	}
	_rep (i, LG, 0) {
		if (((l % (1ll << i)) == 0 && l + (1ll << i) <= r)) {
			nxt(i, __builtin_parityll(l));
			l += (1ll << i);
		}
	}
}

void dfs(int u) {
	/* cout << u << endl; */
	for (auto v : _fail[u]) {
		dfs(v);
		ans[u] += ans[v];
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	rep (i, 1, n) cin >> l[i] >> r[i];
	rep (i, 1, q) cin >> p[i];
	rep (i, 1, q) AC_Automaton::insert(p[i], i);
	AC_Automaton::build();
	init();
	rep (i, 1, n) insert(l[i], r[i]);
	_rep (j, LG - 1, 0) {
		rep (i, 0, tot) {
			g[i][j][0] += g[i][j + 1][0];
			g[f[i][j][1]][j][0] += g[i][j + 1][1];
			g[i][j][1] += g[i][j + 1][1];
			g[f[i][j][0]][j][1] += g[i][j + 1][0];
		}
	}
	rep (i, 0, tot) {
		ans[ch[i][0]] += g[i][0][0];
		ans[ch[i][1]] += g[i][0][1];
	}
	dfs(0);
	/* rep (i, 1, tot) cout << ans[i] << " "; */
	/* cout << endl; */
	rep (i, 1, q) cout << ans[id[i]] << endl;
	return 0;
}
