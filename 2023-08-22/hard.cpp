#include <bits/stdc++.h>

#define rep(i, a, b) for(ll i = (a); i <= b; i++)
#define _rep(i, a, b) for(ll i = (a); i >= b; i--)

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

ll qpow(ll a, ll b, ll p) {
	ll res = 1;
	a %= p, b %= p;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

ll tSub1[10], ansSub1, p, k;
const int MOD = 1e9 + 7;

void dfs(int step) {
	if (step >= p) {
		rep (i, 0, p - 1) {
			if (tSub1[(k * i) % p] != (k * tSub1[i]) % p) return;
		}
		ansSub1++;
		if (ansSub1 >= MOD) ansSub1 -= MOD;
		return;
	}
	rep (i, 0, p - 1) {
		tSub1[step] = i;
		dfs(step + 1);
	}
}

ll ans = 1, cnt;
bitset <1000005> vis;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);
#endif
#endif
	cin >> p >> k;
	if (k == 0) {
		cout << qpow(p, p - 1, MOD);
		return 0;
	}
	if (k == 1) {
		cout << qpow(p, p, MOD);
		return 0;
	}
	if (3 <= p && p <= 7) {
		dfs(0);
		cout << ansSub1;
		return 0;
	}
	rep (i, 1, p - 1) {
		if (!vis[i]) {
			ans *= p; ans %= MOD;
			ll t = i;
			while (!vis[t]) {
				vis[t] = 1;
				t = (t * k) % p;
			}
		}
	}
	cout << ans;
	return 0; 
}
