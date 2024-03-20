#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 1e6 + 5;
int n, k, mod;
inline int qpow(int x, int y) {
    int res = 1;
    while (y) {
        if (y & 1)
            res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }
    return res;
}
int fac[MAXN], inv[MAXN];
inline void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    inv[n] = qpow(fac[n], mod - 2);
    for (int i = n - 1; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
}
inline int c(int x, int y) {
    if (x < y || x < 0 || y < 0)
        return 0;
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}
signed main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
	n = read(), k = read(), mod = read();
    init(MAXN - 1);
    print((c(n + k - 3, n - 2) - c(n + k - 3, n) + mod) % mod * qpow(2, max(0ll, n - k - 1)) % mod);
    return 0;
}
