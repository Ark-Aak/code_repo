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

const int MAXN = 5e4 + 5;
int n, a[MAXN], m, lst;
unordered_map <int, int> cnt;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("avidity.in", "r", stdin);
	freopen("avidity.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, m) {
		int l, r, ans = 0;
		read(l), read(r);
		l = (l + lst) % n + 1, r = (r + lst) % n + 1;
		if (l > r) swap(l, r);
		cnt.clear();
		rep (j, l, r) {
			cnt[a[j] * a[j]]++;
		}
		rep (j, l, r) {
			rep (k, j + 1, r) {
				int sum = a[j] * a[j] + a[k] * a[k];
				ans += cnt[sum];
			}
		}
		print(ans), putchar(10);
		lst = ans;
	}
	return 0;
}
