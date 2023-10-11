/*
    Program: jump.cpp
    Author: 1l6suj7
    DateTime: 2023-10-03 08:46:57
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

const int N = 1000010;

int n, a[N], tr[N], f[N];
int trs[N], nn;

void mdf(int x, int v) { while(x <= nn) tr[x] = max(tr[x], v), x += x & -x; }

int qry(int x) { int res = 0; while(x) res = max(res, tr[x]), x -= x & -x; return res; }

int getn(int x) { return lower_bound(trs + 1, trs + 1 + nn, x) - trs; }

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
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    n = read();
    lp(i, 1, n) a[i] = read(), trs[++nn] = a[i];
    trs[++nn] = 1e9 + 1;
    sort(trs + 1, trs + 1 + nn);
    nn = unique(trs + 1, trs + 1 + nn) - trs - 1;
    lp(i, 1, n) {
        a[i] = getn(a[i]);
        int ind = qry(nn - a[i]);
        mdf(nn - a[i] + 1, i);
        f[i] = f[ind] + 1;
    }
    lp(i, 1, n) printf("%d ", f[i]);
    return 0;
}