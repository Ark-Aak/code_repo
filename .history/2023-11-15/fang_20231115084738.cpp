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

const int MAXN = 1e6 + 5;
int T;
int n, k;
int c[MAXN], b[MAXN], a[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fang.in", "r", stdin);
	freopen("fang.out", "w", stdout);
#endif
#endif
	read(T);
	rep (__, 1, T) {
		read(n), read(k);
		int ans = 0, sum = 0;
		rep (i, 1, n) {
			sum = 0;
			int rc = i % k * i % k * i % k;
			a[i % k]++;
			int rb = i % k * i % k;
			if (rb <= rc) {
				int ls = rc - rb;
				sum += a[ls];
			}
			if (rb <= rc + k) {
				int ls = rc - rb + k;
				if (ls < k) sum += a[ls];
			}
			ans += sum;
		}
		cout << "Case " << __ << ": " << ans << endl;
	}
	return 0;
}