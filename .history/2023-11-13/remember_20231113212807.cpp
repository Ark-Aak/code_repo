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

const int MAXN = 2e3 + 5;
int T, n, a[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("remember.in", "r", stdin);
	freopen("remember.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		read(n);
		rep (i, 1, n) read(a[i]);
		int ord[10];
		rep (i, 1, n) ord[i] = i;
		int ans = 0;
		do {
			int f = 0;
			rep (i, 1, n) {
				int cnt = 0;
				int t = a[ord[i]];
				while (t) {
					cnt++;
					t /= 10;
				}
				f = f * pow(10, cnt);
				f += a[ord[i]];
				f %= 11;
			}
			if (!f) ans++;
		} while(next_permutation(ord + 1, ord + n + 1));
		print(ans % 147744151), putchar(10);
	}
	return 0;
}
