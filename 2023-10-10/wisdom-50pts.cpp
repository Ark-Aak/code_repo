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

int n, m, k;
int arr[1005][1005], cnt = 0;
const int MOD = 1e9 + 7;

signed main() {
	cin >> n >> m >> k;
	rep (i, 1, n) {
		rep (j, 1, m) {
			arr[i][j] = ++cnt;
		}
	}
	rep (q, 1, k) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		if (c == 'R') {
			rep (i, 1, m) arr[x][i] = (arr[x][i] * y % MOD);
		}
		else {
			rep (i, 1, n) arr[i][x] = (arr[i][x] * y % MOD);
		}
	}
	int ans = 0;
	rep (i, 1, n) rep (j, 1, m) ans = (ans + arr[i][j]) % MOD;
	cout << ans;
	return 0;
}
