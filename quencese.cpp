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

ll T, x, ans, f[1000005];
const ll MOD = 998244353;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("quencese.in", "r", stdin);
	freopen("quencese.out", "w", stdout);
#endif
#endif
	f[1] = 1;
	rep (i, 2, 5e4) rep (j, 1, sqrt(i)) {
		f[i] += f[j];
		if (f[i] > MOD) f[i] -= MOD;
	}
	read(T);
	while (T --> 0) {
		read(x);
		if (x <= 5e4) cout << f[x] << endl;
		else {
			ll ans = 0;
			rep (i, 1, sqrt(sqrt(x))) ans += ((ll) sqrt(x) - i * i + 1) * f[i] % MOD, ans %= MOD;
			cout << ans << endl;
		}
	}
}
