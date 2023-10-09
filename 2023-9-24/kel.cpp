#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

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

#define int ll

int res[9999999], cnt;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("kel.in", "r", stdin);
	freopen("kel.out", "w", stdout);
#endif
#endif
	int n, l, r;
	cin >> n >> l >> r;
	if (((r - l + 2) * (r - l + 1) + 1) < n) {
		cout << "Shinomiya";
		return 0;
	}
	if (n <= 3) {
		rep (i, 1, n) cout << l << " ";
		return 0;
	}
	int lft = l, rgt = l;
	rep (i, 1, n / 2) {
		if (lft > r) continue;
		res[++cnt] = lft, res[++cnt] = rgt;
		++rgt;
		if (rgt > r) rgt = ++lft;
	}
	if (cnt < n) res[++cnt] = lft;
	if (res[n - 1] == r) res[n] = l;
	rep (i, 1, n) cout << res[i] << " ";
	return 0; 
}
