#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

signed main() {
	int n = read(), C = read();
	int lst = 0, sum1 = 0, sum2 = 0;
	int ans = 0;
	rep (i, 1, n) {
		int x = read();
		ans += x, lst += x;
		if (C > 0)
			ans = max((lst - sum1) * C + sum1, ans);
		else
			ans = max((lst - sum2) * C + sum2, ans);
		sum1 = min(lst, sum1);
		sum2 = max(lst, sum2);
	}
	print(ans);
	return 0;
}
