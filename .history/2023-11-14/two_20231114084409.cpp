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

struct func {
	int m, k;
	
	bool operator < (const func &t) const  {
		return (m * m - 2 * m + k) < (t.m * t.m - 2 * t.m + t.k);
	}

	func() {}
	func(int _m, int _k) : m(_m), k(_k) {}
};

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("two.in", "r", stdin);
	freopen("two.out", "w", stdout);
#endif
#endif
	
	return 0;
}