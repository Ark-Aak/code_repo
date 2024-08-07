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

#define int ll

int f(int n, int m) {
	return n * n % m;
}

int T, n, m;

map <int, int> c;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
#endif
#endif
	/*
	while (1) {
		int m;
		cin >> m;
		rep (__, 1, m) {
			cnt.clear();
			rep (i, 0, __ - 1) {
				cnt[f(i, __)] = 1;
				if (f(i, __) == 1 && f(i + 1, __) == 0) {
					cout << __ << " : " << i + 1 << ", kind: " << cnt.size() << ", factors: ";
					int ti = __, fac = 2;
					while (ti > 1) {
						while (ti % fac == 0) cout << fac << " ", ti /= fac;
						fac++;
					}
					cout << endl;
					break;
				}
			}
			cout << "----------------" << endl;
		}
	}
	*/
	cin >> T;
	while (T --> 0) {
		cin >> n >> m;
		if (n <= 1e6) {
			c.clear();
			int ans = 0;
			rep (i, 0, n - 1) {
				ans += c[f(i, m)];
				c[f(i, m)]++;
			}
			cout << ans << endl;
			continue;
		}
		int len = (m % 4 ? m : m / 2);
		int cnt = n / len;
		int lst = (cnt) * 2 - 1;
		int sum = (lst) * (lst + 1) / 2;
		int ans = 0, knd = (len + 1) / 2;
		ans += knd * sum;
		int tn = n;
		n -= cnt * len;
		int fct = ceil(tn * 1.0 / len), calc = cnt * 2 + (n >= 1) - 1;
		if (n >= knd) {
			ans += knd * (lst + 1);
			lst += 1;
			n -= knd;
		}
		ans -= (fct + calc) * (calc - fct + 1) / 2;
		ans += n * (lst + 1);
		cout << ans << endl;
	}
	return 0;
}