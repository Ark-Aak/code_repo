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
int a[500], f[500][500], pref[500];

signed main() {
	cin >> n >> k;
	rep (i, 1, n) cin >> a[i];
	k += 1;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	rep (i, 1, n) {
		rep (j, 1, k) {
			int Max = 0, sum = 0;
			_rep (K, i, 1) {
				sum += a[K];
				Max = max(Max, a[K]);
				f[i][j] = min(f[K - 1][j - 1] + Max * (i - K + 1) - sum, f[i][j]);
			}
		}
	}
	int ans = LONG_LONG_MAX;
	rep (i, 1, k) ans = min(ans, f[n][i]);
	cout << ans;
	return 0; 
}
