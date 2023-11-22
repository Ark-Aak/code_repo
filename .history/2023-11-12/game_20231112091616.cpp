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

const int MAXN = 1e5 + 5;
int n;
int a[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n, greater <int>());
	bool flg = 0, cnt = 0;
	rep (i, 1, n) {
		if (a[i] != a[i - 1]) {
			if (cnt & 1) {
				flg = 1; break;
			}
			else cnt = 1;
		}
		else ++cnt;
	}
	return 0;
}