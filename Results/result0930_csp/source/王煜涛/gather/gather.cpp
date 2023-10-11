/*
    Program: path.cpp
    Author: 1l6suj7
    DateTime: 2023-09-30 09:07:05
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

const int N = 100010;

int n, a[N];
ll lst[N], tr[N], ans;

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

void mdf(int x, ll y) { while(x <= n) tr[x] += y, x += x & -x; }

ll qry(int x) { ll res = 0; while(x) res += tr[x], x -= x & -x; return res; }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("gather.in", "r", stdin);
    freopen("gather.out", "w", stdout);
    n = read();
    lp(i, 1, n) a[i] = read(), lst[a[i]] = lst[a[i]]? lst[a[i]] : i;
    lp(i, 1, n) {
        ll l = lst[a[i]] == i? 0 : lst[a[i]];
        ans += qry(i - 1);
        if(l) ans -= qry(l);
        if(lst[a[i]] == i) mdf(i, 1);
    }
    printf("%lld", ans);
    return 0;
}