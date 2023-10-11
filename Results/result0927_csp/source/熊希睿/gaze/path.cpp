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

int n, k;
int a[500], f[500][500][500];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	rep (i, 1, n) cin >> a[i];
	memset(f, 0x3f, sizeof f);
	rep (j, 0, k) rep (v, 1, n) {
		if (a[v] < a[1]) continue;
		f[1][j][v] = a[v] - a[1];
	}
	rep (i, 2, n) {
		set <pair <int, int> > tmp[500];
		rep (j, 0, k) rep (v, 1, n) tmp[j].insert(make_pair(f[i - 1][j][v], v));
		rep (j, 0, k) {
			rep (v, 1, n) {
				if (a[v] < a[i]) continue;
				f[i][j][v] = min(f[i][j][v], f[i - 1][j][v] + a[v] - a[i]);
				auto x = *(tmp[j].begin());
				if (j > 0) f[i][j][v] = min(f[i][j][v], f[i - 1][j - 1][x.second] + a[v] - a[i]);
			}
		}
	}
	int ans = LONG_LONG_MAX;
	rep (j, 0, k) rep (v, 1, n) ans = min(ans, f[n][j][v]);
	cout << ans;
	return 0; 
}
