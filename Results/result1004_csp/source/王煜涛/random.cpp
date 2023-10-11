/*
    Program: random.cpp
    Author: 1l6suj7
    DateTime: 2023-10-04 08:10:05
    Description: 
*/

#include <bits/stdc++.h>
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

const ll N = 4010, MOD = 998244353;

int n, m, mp[N][N];
char t[N][N];
ll ans;

ll qpow(ll x, int k) {
    ll res = 1;
    while(k) {
        if(k & 1) res = res * x % MOD;
        x = x * x % MOD, k >>= 1;
    }
    return res;
}

int judge(int i, int k, int j) { return (mp[i][j] || t[i][j]) && (mp[j][k] || t[j][k]) && (mp[k][i] || t[k][i]); }

void solve() {
    ans = 0;
    lp(i, 1, n) lp(j, i + 1, n) lp(k, j + 1, n) {
        if(i == j || j == k || i == k) continue;
        int tmp = judge(i, j, k) + judge(k, j, i);
        if(tmp) {
            ll rst = m - mp[i][j] - mp[i][k] - mp[j][k];
            ans = (ans + qpow(2, rst) * tmp) % MOD;
        }

    }
    ans = ans % MOD;
}

ll C(int a, int b) {
    ll res = 1;
    dlp(i, a, a - b + 1) res = res * i / (a - i + 1) % MOD;
    return res;
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("random.in", "r", stdin);
    freopen("random.out", "w", stdout);
    n = read();
    char c;
    lp(i, 1, n) {
        lp(j, 1, n) {
            c = getchar();
            while(c != '0' && c != '1') c = getchar();
            if(c == '1') t[i][j] = 1;
        }
    }
    if(n <= 2) return printf("0"), 0;
    lp(i, 1, n) lp(j, i + 1, n) if(!t[i][j] && !t[j][i]) mp[i][j] = mp[j][i] = 1, ++m;
    if(m < n * (n - 1) / 2) solve();
    else ans = C(n, 3) * 2l % MOD * qpow(2, m - 3) % MOD;
    printf("%lld", ans % MOD);
    return 0;
}