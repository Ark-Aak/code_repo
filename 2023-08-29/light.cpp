#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

vector <int> G[405];
ll n, a[405], _a[405], ord[405], ans;
bitset <405> vis, death;

void getOrder(int step) {
	if (step > n) {
		memcpy(a, _a, sizeof _a);
		ll tans = 0;
		death.reset();
		rep (i, 1, n) {
			tans += a[ord[i]];
			death[ord[i]] = 1;
			for (auto x : G[ord[i]]) if (!death[x]) a[x] += a[ord[i]];
		}
		ans = max(ans, tans);
	}
	rep (i, 1, n) {
		if (!vis[i]) {
			ord[step] = i;
			vis[i] = 1;
			getOrder(step + 1);
			vis[i] = 0;
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("light.in", "r", stdin);
	freopen("light.out", "w", stdout);
#endif
#endif
	cin >> n;
	rep (i, 1, n) cin >> _a[i];
	rep (i, 2, n) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getOrder(1);
	cout << ans;
	return 0; 
}
