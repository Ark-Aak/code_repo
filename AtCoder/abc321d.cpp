#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

int n, m, p;
int a[200005], b[200005];
int prefix[200005];
ll ans = 0;

signed main() {
	cin >> n >> m >> p;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, m) cin >> b[i];
	sort(b + 1, b + 1 + m);
	rep (i, 1, m) prefix[i] = prefix[i - 1] + b[i];
	rep (i, 1, n) {
		int tmp = p - a[i];
		int val = (upper_bound(b + 1, b + 1 + m, tmp) - b - 1);
		cout << val << endl;
		ans += a[i] * val;
		ans += prefix[val];
		ans += p * (m - val);
	}
	cout << ans;
	return 0; 
}
