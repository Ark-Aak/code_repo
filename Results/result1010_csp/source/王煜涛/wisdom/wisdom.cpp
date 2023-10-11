/*
    Program: wisdom.cpp
    Author: 1l6suj7
    DateTime: 2023-10-10 10:36:28
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

const ll N = 1000010, MOD = 1e9 + 7;

struct ques {
    int p; ll x;
}ql[N], qr[N];

int n, m, K;
ll adl[N], ln, adr[N], rn, ans;
bool vis[N];

ll calc(ll a, ll d, ll num) {
    ll b = a + (num - 1) * d;
    return (a + b) * num / 2ll % MOD;
}

ll getv(ll x, ll y) { return ((x - 1) * m + y) % MOD; }

ll solve() {
    ll res = 0;
    lp(i, 1, ln) res = (res + calc((ql[i].p - 1) * m + 1, 1, m) * ql[i].x) % MOD;
    lp(i, 1, rn) res = (res + calc(qr[i].p, m, n) * qr[i].x) % MOD;
    lp(i, 1, ln) lp(j, 1, rn) res = (res + getv(ql[i].p, qr[j].p) * ql[i].x % MOD * qr[j].x % MOD - getv(ql[i].p, qr[j].p) * (ql[i].x + qr[j].x) % MOD) % MOD;
    ll t = 0, s = m - rn;
    lp(i, 1, rn) t += qr[i].p;
    t = calc(1, 1, m) - t;
    lp(i, 1, n) res = vis[i]? res : (res + t) % MOD, t = (t + m * s) % MOD;
    return (res % MOD + MOD) % MOD;
}

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

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("wisdom.in", "r", stdin);
    freopen("wisdom.out", "w", stdout);
    n = read(), m = read(), K = read();
    lp(i, 1, n) adl[i] = 1;
    lp(i, 1, m) adr[i] = 1;
    char opt; int x; ll y;
    lp(i, 1, K) {
        scanf("%c", &opt), x = read(), y = read();
        if(opt == 'R') adl[x] = adl[x] * y % MOD, vis[x] = 1;
        else adr[x] = adr[x] * y % MOD;
    }
    lp(i, 1, n) if(adl[i] != 1) ql[++ln] = {i, adl[i]};
    lp(i, 1, m) if(adr[i] != 1) qr[++rn] = {i, adr[i]};
    printf("%lld", solve());
    return 0;
}