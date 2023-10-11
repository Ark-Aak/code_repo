/*
    Program: geometry.cpp
    Author: 1l6suj7
    DateTime: 2023-09-30 11:00:52
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

double L, l;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("geometry.in", "r", stdin);
    freopen("geometry.out", "w", stdout);
    cin >> L >> l;
    double t = L - l;
    double t2 = t - l * (ll)(t / l);
    if(t2 == 0) printf("%.9lf", 3.0 * t);
    else if(t2 * (ll)(l / t2) == l) printf("%.9lf", t + 2.0 * l * (ll)(t / l) + 3.0 * l - t2);
    else printf("%d", -1);
    return 0;
}
/*
L = 7  l = 3
t = 1
t2 = 1 
*/