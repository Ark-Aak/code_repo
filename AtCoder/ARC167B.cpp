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

const int MOD = 998244353;

double log(int a, int b) {
	return log2(a) / log2(b);
}

signed main() {
	int a, b;
	cin >> a >> b;
	double res = 0;
	int ans = 0;
	rep (i, 1, sqrt(a)) {
		if (a % i == 0) {
			res += log(i, a);
		}
		if (a / i != i) res += (log(a / i, a));
	}
	int lg = 1;
	while (b) {
		if (b & 1) {
			res *= (lg + 1);
		}
		lg = (lg << 1) % MOD;
		b >>= 1;
	}
	cout << ceil(res);
	return 0;
}
