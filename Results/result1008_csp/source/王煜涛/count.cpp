/*
    Program: count.cpp
    Author: 1l6suj7
    DateTime: 2023-10-08 07:53:56
    Description: 
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define ll long long
#define lp(i, j, n) for(int i = j; i <= n; ++i)
#define dlp(i, n, j) for(int i = n; i >= j; --i)
#define lft(n) ((n) << 1)
#define rt(n) ((n) >> 1)
#define mst(n, v) memset(n, v, sizeof(n))
#define mcy(n, v) memcpy(n, v, sizeof(v))
#define INF 1e18
#define MAX4 0x3f3f3f3f
#define MAX8 0x3f3f3f3f3f3f3f3f
#define lc(x) (x << 1)
#define rc(x) ((x << 1) ^ 1)

using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const ll N = 5010, M = 100010, MOD = 998244353;

int n, m, a[M];
ll f[N][N], g[N], s[N], ans;

int read() {
    int x = 0;
    char c;
    int f = 1;
    c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') f = -f, c = getchar();
    while(c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}

ll qpow(ll x, int k) {
    ll res = 1;
    while(k) {
        if(x & 1) res = res * x % MOD;
        x = x * x % MOD, k >>= 1;
    }
    return res;
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    n = read(), m = read();
    lp(i, 1, m) a[i] = read();
    g[0] = 1;
    lp(i, 1, m) s[i] = g[0] - f[0][i];
    lp(i, 1, n) {
        lp(j, 1, m) f[i][j] = s[j];
        lp(j, 1, m) g[i] = (g[i] + f[i][j]) % MOD;
        lp(j, 1, m) {
            if(i - a[j] >= 0) s[j] = (s[j] - g[i - a[j]] + f[i - a[j]][j]) % MOD;
            s[j] = (s[j] + g[i] - f[i][j]) % MOD;
        }
    }
    lp(i, 1, m) ans = (ans + f[n][i]) % MOD;
    printf("%lld", (ans % MOD + MOD) % MOD);
    return 0;
}
/*
f[i][j] = sum { f[k][l] }
i - k <= a[j]
k <= i - 1
l != j
*/