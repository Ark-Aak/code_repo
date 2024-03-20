#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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

int n, k, fans;
int f[105][105 * 105], g[105][105 * 105];
const int mod = 1e9 + 7;

signed main() {
	cin >> n >> k;
	f[n + 1][0] = 1, g[n + 1][0] = 0;
	_rep(i, n, 1) {
		rep (j, 0, (n - i) * k) {
			if (f[i + 1][j]) {
				rep (t, 0, k) {
					int res = t + j, val = 0;
					if (t <= i) val = res / i, res %= i;
					f[i][j + val] = (f[i][j + val] + f[i + 1][j]) % mod;
					g[i][j + val] = (g[i][j + val] + g[i + 1][j] + 1ll * f[i + 1][j] * res % mod) % mod;
				}
			}
		}
	}
	rep (i, 0, n * k) fans = (fans + g[1][i]) % mod;
	cout << fans;
	return 0; 
}
