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

const int MAXN = 2005;
int n, a[MAXN];
vector <int> G[MAXN];

int f[MAXN], tp[MAXN], ans;

void dfs(int u, int step, int fa) {
	if (step != 1) f[step] = 0;
	else f[step] = 1;
	tp[step] = u;
	rep (i, 1, step - 1) f[step] = max(f[step], (a[tp[i]] < a[u]) * (f[i] > 0) * (f[i] + 1));
	ans = max(ans, f[step]);
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, step + 1, u);
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lot.in", "r", stdin);
	freopen("lot.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) {
		ans = 0;
		dfs(i, 1, 0);
		print(ans), putchar(10);
	}
	return 0;
}
