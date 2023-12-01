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

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
#endif
#endif
	while (1) {
		int m;
		cin >> m;
		rep (i, 1, m) {
			if (i == 1) {
				cout << i << " : " << 1 << endl;
				continue;
			}
			rep (j, 0, i - 1) {
				if (f(j, i) == 1 && f(j + 1, i) == 0) {
					cout << i << " : " << j + 1 << ", factors: ";
					int ti = i;
					int fac = 2;
					while (ti) {
						while (ti % fac == 0) cout << fac << " ", ti /= fac;
						fac++;
					}
					break;
				}
			}
		}
		cout << "----------------" << endl;
	}
	return 0;
}