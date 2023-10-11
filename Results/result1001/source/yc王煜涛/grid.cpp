/*
    Program: grid.cpp
    Author: 1l6suj7
    DateTime: 2023-10-01 11:17:07
    Description: 
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int unsigned long long
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

int T, x, y;

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
    freopen("grid.in", "r", stdin);
    freopen("grid.out", "w", stdout);
    T = read();
    while(T--) {
        x = read(), y = read();
        if(x > y) swap(x, y);
        int res = 0;
        if(x == 1) res = 0;
        else if(x == 2) {
             lp(i, 1, y - 1) res += (2 + i) * (y - i);   //-i^2 + (y - 2)i + 2y
             res *= y * 2;
        }else {
            lp(i, 1, x - 1) {
                int t = -(y - 1) * y * (2 * y - 1) / 6 + (y - i - 1) * (y - 1) * y / 2 + (1 + i) * y * (y - 1);
                res = t * y * (1 << (x - i));
                //lp(j, 1, y - 1) res += (1 + i + j) * (y - j) * y * (1 << (x - i));  //-j^2 + (y - i - 1)j + (1 + i)y
            } 
        }
        printf("%llu\n", res);
    }
    return 0;
}