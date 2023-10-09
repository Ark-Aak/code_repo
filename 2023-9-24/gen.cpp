#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

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

#define int ll

vector <int> t;
int n, m, ans, deg[200005], cnt[1000005];

const int MOD = 1e9 + 7;

int f(int x, int y) {
	return (x ^ y) % MOD * (x | y) % MOD * (x & y) % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gen.in", "r", stdin);
	freopen("gen.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, m) {
		int u, v;
		cin >> u >> v;
		deg[u] += 1;
		deg[v] += 1;
	}
	rep (i, 1, n) {
		if (!cnt[deg[i]]) t.emplace_back(deg[i]);
		cnt[deg[i]]++; cnt[deg[i]] %= MOD;
	}
	sort(t.begin(), t.end());
	rep (i, 0, t.size() - 1) {
		rep (j, i + 1, t.size() - 1) {
			ans += f(t[i], t[j]) * cnt[t[i]] % MOD * cnt[t[j]];
			ans %= MOD;
		}
	}
	cout << ans << endl;
	return 0; 
}
