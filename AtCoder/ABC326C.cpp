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

int n, m;
int a[300005], qz[300005];

int main() {
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	rep (i, 1, n) {
		qz[i] = qz[i - 1] + 1;
	}
	int ans = 0;
	rep (i, 1, n) {
		auto nxt = (upper_bound(a + 1, a + 1 + n, a[i] + m) - 1);
		while ((*nxt) > a[i] + m - 1) nxt--;
		int pos = nxt - a;
		ans = max(ans, qz[pos] - qz[i - 1]);
	}
	cout << ans;
	return 0;
}
