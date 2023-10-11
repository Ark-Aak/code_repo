/*
    Program: travel.cpp
    Author: 1l6suj7
    DateTime: 2023-10-05 11:01:07
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

const ll N = 100010, MOD = 998244353;

struct ques {
    int l, r, s;
}qs[N];

int n, k, m;

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
        if(k & 1) res = res * x % MOD;
        x = x * x % MOD, k >>= 1;
    }
    return res;
}

int prs[100];
bool judge(int s, int t) {
    mst(prs, 0);
    lp(i, 0, n - 1) prs[i + 1] = prs[i] + ((s & (1 << i))? 1 : 0);
    lp(i, 1, m) if((prs[qs[i].r] - prs[qs[i].l - 1]) & ((qs[i].s & t)? 0 : 1)) return false;
    return true;
}

int ans[N];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    n = read(), k = read(), m = read();
    lp(i, 1, m) qs[i].l = read(), qs[i].r = read(), qs[i].s = read();
    if(k == 0) {
        lp(i, 1, m) if(qs[i].s > 0) return printf("0"), 0;
        printf("1");
    }else if(n <= 10 && m <= 10) {
        lp(i, 0, (1 << n) - 1) {
            lp(j, 0, k - 1) {
                if(judge(i, 1 << j)) ++ans[j];
            }
        }
        ll res = 1;
        lp(i, 0, k - 1) res = res * ans[i] % MOD;
        printf("%lld", res);
    }else printf("0");
    return 0;
}