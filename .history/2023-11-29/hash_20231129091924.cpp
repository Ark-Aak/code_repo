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

map <int, int> cnt;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("hash.in", "r", stdin);
	freopen("hash.out", "w", stdout);
#endif
#endif
	while (1) {
		cnt.clear();
		int n, m, sum = 0;
		cin >> m;
		rep (__, 1, m)
		rep (i, 0, __ - 1) {
			sum += f(i, m);
			cnt[f(i, m)] = 1;
			cout << i << " X " << i << " mod " << m << " = " << f(i, m) << " kind = " << cnt.size() << endl;
		}
		cout << "----------------" << endl;
	}
	return 0;
}