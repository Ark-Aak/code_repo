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

const int MAXN = 1e4 + 5;
int T, n;
string str;
vector <int> G[MAXN];
int siz[MAXN], mxs[MAXN], id[MAXN], val[MAXN];
vector <int> c;

void dfs(int u, int fa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		mxs[u] = max(mxs[u], siz[v]);
	}
	mxs[u] = max(mxs[u], n - siz[u]);
	if (mxs[u] * 2 <= n) c.push_back(u);
}

/*
笑死我啦🤣
原来这就是求重心啊🤣
*/

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		memset(mxs, 0, sizeof mxs);
		memset(siz, 0, sizeof siz);
		c.clear();
		cin >> n >> str;
		str = ' ' + str;
		if (n == 1) {
			if (str[1] == 'C') puts("Clash");
			else puts("Royale");
			continue;
		}
		rep (i, 1, n) val[i] = str[i] == 'R';
		rep (i, 1, n) vector <int>().swap(G[i]);
		for (int i = 1, u, v; i < n; i++) {
			u = read(), v = read();
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		dfs(1, 0);
		if (n & 1) {
			if (val[c[0]]) {
				puts("Royale");
				continue;
			}
			dfs(c[0], 0);
			int f0 = 0, f1 = 0;
			for (auto v : G[c[0]]) {
				if (val[v]) f1 += siz[v];
				else f0 += siz[v];
			}
			if (f0 >= f1) puts("Clash");
			else puts("Royale");
		}
		else {
			if (c.size() == 1 && val[c[0]]) {
				dfs(c[0], 0);
				int f0 = 0, f1 = 0;
				for (auto v : G[c[0]]) {
					if (val[v]) f1 += siz[v];
					else f0 += siz[v];
				}
				if (f0 >= f1) puts("Clash");
				else puts("Royale");
			}
			else {
				int val = 1;
				for (auto v : c) val = min(val, ::val[v]);
				if (val) puts("Royale");
				else puts("Clash");
			}
		}
	}
	return 0;
}
