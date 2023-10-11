/*
    Program: ave.cpp
    Author: 1l6suj7
    DateTime: 2023-10-11 08:15:37
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

const int N = 1000010;

int n;
double a[N], ans;

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
    freopen("ave.in", "r", stdin);
    freopen("ave.out", "w", stdout);
    n = read();
    lp(i, 1, n) a[i] = read();
    sort(a + 1, a + 1 + n);
    ans = a[1];
    lp(i, 2, n) ans = (ans + a[i]) / 2.0;
    printf("%.6lf", ans);
    return 0;
}