#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

#define int ll

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

const int MAXN = 7005;
int n, p, ans = 1, P, fac[MAXN], T[MAXN][MAXN];

bitset <MAXN> vis;

int qpow(int a, int b, int p) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
	}
	return res;
}

int dp0[MAXN];
int solve(int x) {
    int ans = 1, s = 1;
    rep (i, 1, n) dp0[i] = 0;
    dp0[0] = 1;
	rep (i, 1, n) {
        if (i >= x) dp0[i % x] = dp0[i % x] * T[i - x + 1][i - 1] % P;
        ans = (s - dp0[i % x] + P) % P;
        s = (s * i + ans) % P;
        dp0[i % x] = (dp0[i % x] * i + ans) % P;
    }
    return ans;
}

signed main() {
	n = read(), P = (p = read()) - 1;
	fac[0] = 1;
	rep (i, 1, n) {
		fac[i] = fac[i - 1] * i % P;
		T[i][i - 1] = 1;
		rep (j, i, n) T[i][j] = T[i][j - 1] * j % P;
	}
	vis[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			for (int j = i; j <= n; j *= i) ans = ans * qpow(i, P + fac[n] - solve(j), p) % p;
		}
		rep (j, 2, n / i) vis[i * j] = 1;
	}
	print(ans);
	return 0;
}
