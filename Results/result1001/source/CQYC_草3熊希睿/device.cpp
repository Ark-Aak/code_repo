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

int T;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("device.in", "r", stdin);
	freopen("device.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		int k, n;
		cin >> k >> n;
		int ans = 0;
		int a = k / 100, b = (k / 10) % 10, c = k % 10;
		if (n == 0) ans = 1;
		else if (n == 1) {
			if (a != b && b != c && a != c) ans = 24;
			else if (a == b && b == c) ans = 1;
			else if (a == b || b == c || a == c) ans = 7;
		}
		else {
			if (a != b && b != c && a != c) ans = 27;
			else if (a == b && b == c) ans = 1;
			else if (a == b || b == c || a == c) ans = 8;
		}
		cout << ans << endl;
	}
	return 0; 
}
