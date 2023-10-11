/*
    Program: game.cpp
    Author: 1l6suj7
    DateTime: 2023-10-09 10:07:32
    Description: 
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define ll long long
#define lp(i, j, n) for(ll i = j; i <= n; ++i)
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

const ll N = 1010, MOD = 1e9 + 7;

ll T, n, m, f[N][N];

int gcd(ll a, ll b) { return b == 0? a : gcd(b, a % b); }

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    T = read();
    int K = 1000;
    lp(i, 1, K) lp(j, 1, K) f[i][j] = (i + j) / gcd(i, j) - 2;
    lp(i, 1, K) lp(j, 1, K) f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1]) % MOD;
    while(T--) {
        m = read(), n = read();
        printf("%lld\n", f[m][n]);
    }
    return 0;
}