#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

#define int i128

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int T;
int x, y, a, b;

int mygcd(int a, int b) {
	return !b ? a : mygcd(b, a % b);
}

int mymin(int a, int b) {
	return a < b ? a : b;
}

int calc(int x, int y, int a, int b, bool flg) {
	const int mod = a + b;
	int ans = 2;
	const int ta = flg ? b : a;
	const int tb = flg ? a : b;
	while (x != ta || y != tb) {
		ans++;
		bool flg = 1;
		if (y % a == 0 && x > b * y / a) {
			flg = 0;
			x -= b * y / a;
			if (x % mod) {
				x += b * y / a;
				break;
			}
			x /= mod;
			y /= a;
		}
		else if (x % a == 0 && y > b * x / a) {
			flg = 0;
			y -= b * x / a;
			if (y % mod) {
				y += b * x / a;
				break;
			}
			y /= mod;
			x /= a;
		}
		if (x <= 0 || y <= 0 || flg) break;
	}
	if (x != ta || y != tb) return -1;
	else return ans;
}

void solve() {
	x = read(), y = read(), a = read(), b = read();
	int GCD = mygcd(x, y);
	x /= GCD, y /= GCD;
	GCD = mygcd(a, b);
	a /= GCD, b /= GCD;
	int ans1 = calc(x, y, a, b, 0);
	int ans2 = calc(x, y, a, b, 1);
	if (ans1 == ans2 && ans1 == -1) return void(puts("-1"));
	if (ans1 == -1) ans1 = 1e18;
	if (ans2 == -1) ans2 = 1e18;
	return void((print(mymin(ans1, ans2)), puts("")));
}

signed main() {
#ifndef LOCAL
	ignore = freopen("cook.in", "r", stdin);
	ignore = freopen("cook.out", "w", stdout);
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
