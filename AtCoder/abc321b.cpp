#include <bits/stdc++.h>

#define rep(i, a, b) for(long long i = (a); i <= b; i++)
#define _rep(i, a, b) for(long long i = (a); i >= b; i--)

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

signed main() {
	int n, x, a[105];
	cin >> n >> x;
	rep (i, 1, n - 1) {
		cin >> a[i];
	}
	sort(a + 1, a + n);
	int mx = 0, ans = -1, sum = 0;
	rep (i, 2, n - 2) sum += a[i];
	rep (i, 0, 100) {
		if (sum + a[1] + a[n - 1] + i - min(a[1], min(a[n - 1], i)) - max(a[1], max(a[n - 1], i)) >= x) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0; 
}
