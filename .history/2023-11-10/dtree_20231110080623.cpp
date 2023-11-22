#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

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

const int MAXN = 1e6 + 5;
int n, p;
int f[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("dtree.in", "r", stdin);
    freopen("dtree.out", "w", stdout);
#endif
#endif
    read(n), read(p);
	f[1] = 0; f[2] = 0;
	rep (i, 3, n) {
		rep (i, 1, n) {
			f[i] += f[i - 1] * f[n - i] * 2;
		}
	}
	print(f[n]), putchar(10);
	return 0;
}