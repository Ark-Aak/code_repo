#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MOD = 998244353, MAXN = 2e5 + 5;
int n, p[MAXN], pos[MAXN], ans, res;
string s;
bool vis[MAXN], ord[MAXN];
bool vvis[MAXN];

void dfs(int x) {
	if (ord[x]) return;
	ord[x] = 1;
	if (!vis[x]) {
		int y = (x - 1) ? (x - 1) : n;
		if (s[x] == '?' && !vvis[x]) res *= 2, res %= MOD;
		if (s[y] == 'R' && pos[y] < pos[x]) return res = 0, void();
		if (pos[y] < pos[x]) vvis[y] = 1;
		vis[x] = 1, dfs(y);
	}
	else {
		int y = (x % n + 1);
		if (s[x] == '?' && !vvis[x]) res *= 2, res %= MOD;
		if (s[y] == 'L' && pos[y] < pos[x]) return res = 0, void();
		if (pos[y] < pos[x]) vvis[y] = 1;
		vis[y] = 1, dfs(y);
	}
}

signed main() {
	cin >> n;
	rep(i, 1, n) cin >> p[i], pos[p[i]] = i;
	cin >> s;
	s = ' ' + s;
	int fir = p[1];
	if (s[fir] == '?') {
		res = 1;
		s[fir] = 'L'; ord[fir] = 1; vis[fir] = 1;
		dfs((fir - 1) ? (fir - 1) : n);
		ans += res;
		rep (i, 1, n) vis[i] = ord[i] = vvis[i] = 0;
		res = 1; s[fir] = 'R'; ord[fir] = 1; vis[fir % n + 1] = 1;
		dfs(fir % n + 1);
		ans += res;
	}
	else {
		if (s[fir] == 'L') {
			res = 1;
			ord[fir] = 1; vis[fir] = 1;
			dfs((fir - 1) ? (fir - 1) : n);
			ans += res;
		}
		else {
			res = 1; ord[fir] = 1;
			vis[fir % n + 1] = 1; dfs(fir % n + 1);
			ans += res;
		}
	}
	cout << ans % MOD;
	return 0;
}
