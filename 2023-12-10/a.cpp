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

const int MOD = 998244353;
const int MAXN = 1e6 + 5;
int n, k, a[MAXN], b[MAXN];
int c[MAXN], kmp[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
#endif
	read(n); read(k);
	if (k >= n - 1) return puts("0"), 0;
	++k;
	rep (i, 1, n) {
		read(a[i]);
	}
	rep (i, 1, n) {
		read(b[i]); b[i + n] = b[i];
	}
	rep (i, 1, k) {
		rep (i, 1, n - 1) c[i] = a[i + 1] - a[i];
		rep (i, 1, n) a[i] = (c[i] % MOD + MOD) % MOD;
		rep (i, 1, (n << 1) - 1) c[i] = b[i + 1] - b[i];
		rep (i, 1, (n << 1)) b[i] = (c[i] % MOD + MOD) % MOD;
	}
	for (int i = 2, j = 0; i <= n; i++) {
		while (j && a[j + 1] != a[i]) j = kmp[j];
		if (a[j + 1] == a[i]) j++;
		kmp[i] = j;
	}
	for (int i = 1, j = 0; i <= (n << 1); i++) {
		while (j && a[j + 1] != b[i]) j = kmp[j];
		if (a[j + 1] == b[i]) j++;
		if (j >= n - k) {
			print(i - j), putchar(10);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
