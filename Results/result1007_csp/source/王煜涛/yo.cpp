/*
    Program: yo.cpp
    Author: 1l6suj7
    DateTime: 2023-10-07 08:14:55
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

const int N = 1000010, M = 11;

int n, a[N], ans;
//int f[M][2], g[M];
char s[N];

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

int f[N][M];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("yo.in", "r", stdin);
    freopen("yo.out", "w", stdout);
    n = read();
    char c;
    lp(i, 1, n) {
        c = getchar();
        while(!isdigit(c)) c = getchar();
        a[i] = c - '0';
    }
    lp(i, 1, n) {
        c = getchar();
        while(c != 'y' && c != 'o') c = getchar();
        s[i] = c;
    }
    if(n == 1 || s[1] == 'o') return printf("oimiya"), 0;
    printf("yoimiya");
    // f[0][1] = 1;
    // lp(i, 1, n) {
    //     if(s[i] == 'y') {
    //         if(f[0][i & 1]) f[0][!(i & 1)] = f[0][i & 1];
    //         lp(j, 0, 10) {
    //             if(f[j][i & 1] && a[i] - j >= 0) f[a[i] - j][!(i & 1)] = f[j][i & 1];
    //         }
    //     }
    // }
    // int t = (a[n - 1] == a[n]);
    // if(s[n - 1] == 'y' && s[n] == 'y') f[n - 1][a[n - 1]] = f[n - 1][0] = 1;
    // else f[n - 1][a[n - 1]] = 0;
    // dlp(dep, n - 2, 1) {
    //     int mx[M], mn[M]; mx[0] = mn[0] = f[dep + 1][0];
    //     lp(i, 1, 9) mx[i] = max(mx[i - 1], f[dep + 1][i]), mn[i] = min(mn[i - 1], f[dep + 1][i]);
    //     f[dep][0] = f[dep + 1][0];
    //     lp(i, 0, a[dep + 1]) {
    //         if(s[dep] == 'y') f[dep][i] = f[dep + 1][a[dep + 1] - i];
    //         else f[dep][i] = f[dep + 1][a[dep + 1] - i];
    //     }
    //     lp(i, 0, 9) cout << f[dep][i] << ' '; cout << endl;
    // }
    // int mn = min(f[1][0], f[1][a[1]]), mx = max(f[1][0], f[1][a[1]]);
    // if(s[1] == 'y') ans = mx;
    // else ans = mn;
    // if(ans) printf("yoimiya");
    // else printf("oimiya");
    return 0;
}