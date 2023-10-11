/*
    Program: ak.cpp
    Author: 1l6suj7
    DateTime: 2023-10-09 09:42:44
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

struct node {
    int l, r;
}nd[N];

int n, k, tot;
ll a[N], b[N];

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
    freopen("ak.in", "r", stdin);
    freopen("ak.out", "w", stdout);
    n = read(), k = read();
    ll sum = 0;
    lp(i, 1, n) {
        a[i] = read(), sum += a[i];
        if(i % k == 1) b[++tot] = a[i];
    }
    sort(b + 1, b + 1 + tot);
    printf("%lld", sum - b[tot / 2 + 1]);
    return 0;
}