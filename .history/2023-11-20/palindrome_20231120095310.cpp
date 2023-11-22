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

//h(n) = \sum_{d|n, d != n} g(d) * n / d

#define int ll

const int MAXN = 1e5 + 5;
int n, k;
const int MOD = 998244353;
int h[MAXN];

void sieve() {
	h[1] = k + 1;
	rep (i, 1, n) {
		for (int j = i; j <= n; j += i) {
			
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	return 0;
}