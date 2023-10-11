/*
    Program: permutation.cpp
    Author: 1l6suj7
    DateTime: 2023-10-05 08:16:10
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

int n, a[N], b[N], f[N][3], k;

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
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    n = read(), k = read(); ++k;
    lp(i, 1, n) f[i][0] = a[i] = read();
    lp(i, 1, n) f[i][1] = b[i] = read();
    if(k == 1) { lp(i, 1, n) printf("%d ", a[i]); return 0; }
    if(k == 2) { lp(i, 1, n) printf("%d ", b[i]); return 0; }
    bool f1 = false, f2 = false;
    int i = 3;
    while(i <= k) {
        f2 = true;
        lp(j, 1, n) {
            f[f[j][0]][2] = f[j][1];
            if(f[f[j][0]][2] != b[f[j][0]]) f2 = false;
        }
        if(f1 && f2) break;
        f1 = true;
        lp(j, 1, n) if(f[j][2] != a[j]) f1 = false;
        lp(j, 1, n) f[j][0] = f[j][1], f[j][1] = f[j][2];
        ++i;
    }
    if(i > k) { lp(i, 1, n) printf("%d ", f[i][2]); return 0; }
    // int t = k;
    // while(t - i + 1 > 0) t -= i - 2;
    // --t;
    int t = k % (i - 2);
    if(t == 0) t = i - 2;
    if(t == 0) { lp(i, 1, n) printf("%d ", a[i]); return 0; }
    if(t == 1) { lp(i, 1, n) printf("%d ", b[i]); return 0; }
    lp(i, 1, n) f[i][0] = a[i], f[i][1] = b[i];
    for(i = 3; i <= t; ++i) {
        lp(j, 1, n) f[f[j][0]][2] = f[j][1];
        lp(j, 1, n) f[j][0] = f[j][1], f[j][1] = f[j][2];
    }
    lp(i, 1, n) printf("%d ", f[i][2]);
    return 0;
}