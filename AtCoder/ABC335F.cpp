#include <bits/stdc++.h>

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

const int MAXN = 2e5 + 5, MOD = 998244353, B = sqrt(2e5);
int n, a[MAXN], f[MAXN], tag[B][B];

int main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	f[1] = 1;
	rep (i, 1, n) {
		rep (j, 1, B - 1) f[i] = (f[i] + tag[j][i % j]) % MOD;
		if (a[i] < B) {
			tag[a[i]][i % a[i]] = (tag[a[i]][i % a[i]] + f[i]) % MOD;
			continue;
		}
		for (int j = i + a[i]; j <= n; j += a[i]) {
			f[j] = (f[i] + f[j]) % MOD;
		}
	}
	int sum = 0;
	rep (i, 1, n) sum += f[i], sum %= MOD;
	print(sum);
	return 0;
}
