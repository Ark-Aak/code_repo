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
const int MAXN = 2e5 + 5;
int s[MAXN], n, m, ans;

signed main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(s[i]);
	sort(s + 1, s + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n - m; i++) {
		ans += (s[i] + s[(n - m) * 2 - i + 1]) * (s[i] + s[(n - m) * 2 - i + 1]);
	}
	for (int i = (n - m) * 2 + 1; i <= n; i++)
		ans += s[i] * s[i];
	print(ans);
	return 0;
}
