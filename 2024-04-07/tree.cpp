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

const int MAXN = 1e5 + 5;
int T, n, cnt;
int ch0[MAXN], ch1[MAXN];
int v[MAXN];
vector <int> G[MAXN];

void dfs(int u, int fa) {
	v[u] = v[fa] ^ 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

void solve() {
	cin >> n;
	string str;
	cin >> str;
	rep (i, 1, n) ch0[i] = str[i - 1] == '1';
	cin >> str;
	rep (i, 1, n) ch1[i] = str[i - 1] == '1';
	rep (i, 1, n) vector <int>().swap(G[i]);
	rep (i, 1, n) v[i] = 0;
	rep (i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool flg = 1;
	rep (i, 2, n) flg &= ch0[i] == ch0[i - 1];
	if (flg) {
		bool ok = 1;
		rep (i, 1, n) ok &= ch1[i] == ch0[1];
		puts(ok ? "TAK" : "NIE");
		return;
	}
	flg = 1;
	rep (i, 1, n) flg &= ch0[i] == ch1[i];
	if (flg) return puts("TAK"), void();
	int mxd = 0;
	rep (i, 1, n) mxd = max(mxd, (int) G[i].size());
	if (mxd <= 2) {
		int pos = 0;
		rep (i, 1, n) if (G[i].size() == 1) pos = i;
		int lst = pos;
		pos = G[pos][0];
		int cnt0 = (ch0[pos] != ch0[lst]) - (ch0[lst] != ch1[lst]);
		int cnt1 = (ch1[pos] != ch1[lst]);
		while (G[pos].size() > 1) {
			int v = (G[pos][0] == lst) ? G[pos][1] : G[pos][0];
			cnt0 += (ch0[v] != ch0[pos]);
			cnt1 += (ch1[v] != ch1[pos]);
			swap(lst, pos);
			pos = v;
		}
		puts(cnt0 >= cnt1 ? "TAK" : "NIE");
		return;
	}
	dfs(1, 0);
	flg = 1;
	rep (i, 2, n) flg &= ((ch1[i] ^ v[i]) == (ch1[i - 1] ^ v[i - 1]));
	puts(flg ? "NIE" : "TAK");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
