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

ll T, n, c[2000005], cnt;
const ll INF = 1e18;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
#endif
#endif
	read(T);
	for (ll i = 1; true; i++) {
		ll a = i, b = i * i * i;
		if (b - 2 > INF) break;
		ll k = i * i;
		c[++cnt] = b;
		if (i == 1) continue;
		while (1) {
			if (1.0 * k * b - a > 2 * INF) break;
			a = k * b - a;
			swap(a, b);
			c[++cnt] = b;
		}
	}
	sort(c + 1, c + 1 + cnt);
	while (T --> 0) {
		ll x;
		read(x);
		cout << ((int) (lower_bound(c + 1, c + 1 + cnt, x + 1) - c - 1)) << endl;
	}
	return 0;
}
