#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n, m, k, cnt, ans;
bool vis[10][10];
bool mk[20];
map <int, int> MP;

void col(int u) {
	mk[u] = 1;
	++cnt;
	rep (i, 1, n) if (vis[u][i]) {
		if (!mk[i]) col(i);
	}
}

int h() {
	int res = 0;
	rep (i, 1, n) rep (j, 1, n) res = (res << 1 | vis[i][j]);
	return res;
}

void dfs(int step) {
	if (step > m) {
		if (MP[h()]) return;
		memset(mk, 0, sizeof mk);
		int mx = 0;
		rep (i, 1, n) {
			if (!mk[i]) {
				cnt = 0, col(i);
				mx = max(mx, cnt);
			}
		}
		if (mx == k) {
			++ans;
		}
		MP[h()] = 1;
		return;
	}
	//int u = step;
	rep (u, 1, n) {
		rep (v, 1, n) {
		if (!vis[u][v] && u != v) {
				vis[u][v] = vis[v][u] = 1;
				dfs(step + 1);
				vis[u][v] = vis[v][u] = 0;
			}
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("kid.in", "r", stdin);
	freopen("kid.out", "w", stdout);
#endif
#endif
	cin >> n >> m >> k;
	if (m > ((n * (n - 1)) / 2)) return cout << 0, 0;
	if (n <= k) {
		if (n < k) cout << 0;
		else if (m < n - 1) cout << 0;
		else if (m > ((n * (n - 1)) / 2)) cout << 0;
		else cout << 1;
		return 0;
	}
	dfs(1);
	cout << ans;
	return 0;
}

