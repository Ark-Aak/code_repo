/*
    Program: badge.cpp
    Author: 1l6suj7
    DateTime: 2023-10-01 10:28:42
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

const int N = 200010;

struct range {
    int l, r;
}rg[N];

int n, q, tr[N];

void mdf(int x, int y) { while(x <= n) tr[x] += y, x += x & -x; }

int qry(int x) { if(!x) return 0; int res = 0; while(x) res += tr[x], x -= x & -x; return res; }

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

int x[N];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("badge.in", "r", stdin);
    freopen("badge.out", "w", stdout);
    ll t1 = clock();
    n = read(), q = read();
    lp(i, 1, n) rg[i].l = read(), rg[i].r = read();
    int m;
    while(q--) {
        m = read();
        lp(i, 1, m) {
            x[i] = read();
            mdf(x[i], 1);
        }
        int res = 0;
        lp(i, 1, n) if((qry(rg[i].r) - qry(rg[i].l - 1)) & 1) ++res;
        printf("%d\n", res);
        lp(i, 1, m) mdf(x[i], -1);
    }
    ll t2 = clock();
    printf("%lld", t2 - t1);
    return 0;
}