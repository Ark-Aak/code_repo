/*
    Program: matrix.cpp
    Author: 1l6suj7
    DateTime: 2023-10-10 10:56:09
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

const int N = 23, M = 200010;

int n, m, a[N][M], sum[M], ans = 1e9;

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
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    n = read(), m = read();
    char ch;
    lp(i, 1, n) lp(j, 1, m) {
        ch = getchar();
        while(ch != '0' && ch != '1') ch = getchar();
        if(ch == '1') a[i][j] = 1, ++sum[j];
    }
    lp(i, 0, (1 << n) - 1) {
        int res = 0;
        lp(j, 1, m) {
            int k = 1, s = i;
            while(s) { if(s & 1) sum[j] += a[k][j]? -1 : 1; ++k, s >>= 1; }
            res += min(sum[j], n - sum[j]);
            k = 1, s = i;
            while(s) { if(s & 1) sum[j] += a[k][j]? 1 : -1; ++k, s >>= 1; }
            if(res >= ans) break;
        }
        ans = min(ans, res);
    }
    printf("%d", ans);
    return 0;
}