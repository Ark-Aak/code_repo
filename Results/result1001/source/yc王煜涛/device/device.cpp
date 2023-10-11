/*
    Program: device.cpp
    Author: 1l6suj7
    DateTime: 2023-10-01 08:11:21
    Description: 
*/

#include <bits/stdc++.h>
#define int long long
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

int T, k, n;

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

int a[10], tot;

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("device.in", "r", stdin);
    freopen("device.out", "w", stdout);
    T = read();
    while(T--) {
        k = read(), n = read();
        if(n == 0) { printf("%d\n", 1); continue; }
        tot = 0;
        while(k) a[++tot] = k % 10, k /= 10;
        if(a[1] == a[2] && a[2] == a[3] && a[1] == a[3]) { printf("%d\n", 1); continue; }
        if(n == 1) {
            if(a[1] != a[2] && a[2] != a[3] && a[1] != a[3]) printf("%d\n", 24);
            else printf("%d\n", 7);
        }else {
            if(a[1] != a[2] && a[2] != a[3] && a[1] != a[3]) printf("%d\n", 27);
            else printf("%d\n", 8);
        }
        
    }
    return 0;
}