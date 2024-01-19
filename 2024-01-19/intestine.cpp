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

const int MAXN = 505;
const int MOD = 998244353;
int n;
vector <int> G[MAXN];
int dfnc, dfn[MAXN];
int ans[MAXN][MAXN];

int order[MAXN][MAXN];

void dfs0(int u, int fa) {
	dfn[u] = ++dfnc;
	rep (i, 1, G[u].size()) {
		int v = G[u][order[u][i] - 1];
		if (v == fa) continue;
		dfs0(v, u);
	}
}

void dfs1(int step) {
	if (step > n) {
		dfnc = 0;
		memset(dfn, 0, sizeof dfn);
		dfs0(1, 0);
		rep (i, 1, dfnc) {
			ans[i][dfn[i]] = (ans[i][dfn[i]] + 1) % MOD;
		}
		return;
	}
	do {
		dfs1(step + 1);
	} while (next_permutation(order[step] + 1, order[step] + 1 + G[step].size()));
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("intestine.in", "r", stdin);
	freopen("intestine.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 2, n) {
		int x = read();
		G[x].push_back(i);
	}
	rep (i, 1, n) rep (j, 1, G[i].size()) order[i][j] = j;
	dfs1(1);
	rep (i, 1, n) {
		rep (j, 1, n) print(ans[i][j]), putchar(32);
		putchar(10);
	}
	return 0;
}
