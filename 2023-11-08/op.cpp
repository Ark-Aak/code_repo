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

int T, n, a[20], b[20];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("op.in", "r", stdin);
	freopen("op.out", "w", stdout);
#endif
#endif
	cin >> T;
	while (T --> 0) {
		cin >> n;
		rep (i, 1, n) cin >> a[i] >> b[i];
		if (a[1] < b[1]) {
			cout << b[1] - a[1] << endl;
			continue;
		}
		else {
			int ans = a[1] - b[1], cnt = 0;
			while (a[1] > b[1]) {
				++cnt;
				a[1] /= 2;
				ans = min(ans, cnt + abs(b[1] - a[1]));
			}
			ans = min(ans, cnt + b[1] - a[1]);
			print(ans); putchar(10);
		}
	}
	return 0;
}
