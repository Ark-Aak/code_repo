#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep (i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 1e6 + 5;
int n, k;
vector <int> G[MAXN];

int dfs(int u, int fa) {
	int res = 1;
	for (auto v : G[u]) if (v ^ fa) res += dfs(v, u);
	if (res > k) puts("No"), exit(0);
	res %= k;
	return res;
}

int main() {
#ifndef LOCAL
	freopen("cut.in", "r", stdin);
	freopen("cut.out", "w", stdout);
#endif
	n = read(), k = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (n % k) return puts("No"), 0;
	if (dfs(1, 0) == 0) puts("Yes");
	else puts("No");
	return 0;
}
