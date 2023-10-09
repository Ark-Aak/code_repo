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

ll n, mod, ans[10000005], _base = 1, _ans;

int main() {
	cin >> n >> mod;
	ans[0] = ans[1] = 1;
	rep (i, 2, n) {
		ans[i] = ans[i - 1] % mod + ans[i - 2] * (i - 1) % mod;
		ans[i] %= mod;
		_base *= i;
		_base %= mod;
		_ans ^= ((mod + 1) / 2 * (mod + _base - ans[i])) % mod;
	}
	cout << _ans;
	return 0; 
}
