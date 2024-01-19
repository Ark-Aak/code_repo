#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
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

int a1, b1, a2, b2, n, q;
int ans[2000005], c[2000005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);
#endif
#endif
	a1 = read(), b1 = read(), a2 = read(), b2 = read(), n = read();
	int s1 = a1 + b1, s2 = a2 + b2;
	int l = 0, r = 1;
	int LCM = s1 * s2 / __gcd(s1, s2);
	rep (i, 1, max(1000000ll, (LCM << 1))) {
		if ((i - 1) % s1 < a1) r++;
		if ((i - 1) % s2 < a2) l += (l < r - 1);
		ans[i] = l;
	}
	rep (i, 1, n) c[i] = ans[LCM + i] - ans[LCM];
	int cf = ans[2 * LCM] - ans[LCM];
	rep (i, 1, n) {
		int q = read();
		if (q <= 1e6) print(ans[q]), putchar(10);
		else {
			int sum = ans[LCM];
			q -= LCM;
			sum += cf * (q / LCM);
			q -= ((int) (q / LCM)) * LCM;
			sum += c[q];
			print(sum); putchar(10);
		}
	}
	return 0;
}
