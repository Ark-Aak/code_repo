#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 1e6 + 5, MAXM = 5005;
int n, m, mod, f[MAXM][MAXM], fac[MAXM], pre[MAXN], l[MAXN], sum[MAXN];
vector <int> d[MAXN];

void init() {
	f[0][0] = 1;
	rep (i, 1, 5000)
		rep (j, 1, i) f[i][j] = (1ll * f[i - 1][j] * (j - 1) + f[i - 1][j - 1]) % mod;
	fac[0] = 1;
	rep (i, 1, 5000) fac[i] = (1ll * fac[i - 1] * i) % mod;
	pre[m + 1] = 1;
	_rep (i, m, 1) pre[i] = (1ll * pre[i + 1] * i) % mod;
}

signed main() {
    freopen("christmas.in", "r", stdin);
    freopen("christmas.out", "w", stdout);
    n = read(), m = read(), mod = read();
    init();
	rep (i, 1, n) {
        l[i] = read();
        d[i].resize(l[i] + 10);
    }
    sum[0] = 1;
	rep (i, 1, n) {
		rep (j, 1, l[i]) {
            d[i][j] = 1ll * pre[m - j + 1] * f[l[i]][j] % mod * sum[i - 1] % mod;
            if (l[i - 1] >= j)
                d[i][j] = (1ll * d[i][j] - 1ll * d[i - 1][j] * f[l[i]][j] % mod * fac[j] % mod + mod) % mod;
            sum[i] = (sum[i] + d[i][j]) % mod;
        }
    }
    int ans = 0;
    rep (i, 1, l[n]) ans = (ans + d[n][i]) % mod;
	print(ans);
    return 0;
}
