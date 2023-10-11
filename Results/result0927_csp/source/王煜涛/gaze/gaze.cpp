/*
    Program: gaze.cpp
    Author: 1l6suj7
    DateTime: 2023-09-27 09:39:21
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

using namespace std;

const int N = 200010;

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

struct ques {
    int opt, id; ll x, a, b;

    bool operator < (const ques & t) const { return x < t.x; }
}qs[N];

struct world {
    ll a; int id, l, r, crt;

    bool operator < (const world & t) const { return a < t.a; }
}wd[N];

int n, m, pt[N], h[N], ans[N];

int solve(int nx) {
    int res = 0; wd[0].a = -1;
    lp(i, 1, n) {
        if(wd[i].a >= nx && wd[i - 1].a < nx) ++res;
    }
    return res;
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("gaze.in", "r", stdin);
    freopen("gaze.out", "w", stdout);
    n = read(), m = read();
    lp(i, 1, n) wd[i].a = read(), wd[i].id = i, wd[i].l = i - 1, wd[i].r = i + 1, wd[i].crt = 1;
    lp(i, 1, m) {
        qs[i].opt = read(), qs[i].id = i;
        if(qs[i].opt == 1) qs[i].x = read();
        else qs[i].a = read(), qs[i].b = read();
    }
    if(n <= 2000 && m <= 2000) {
        int nx = 0;
        lp(i, 1, m) {
            if(qs[i].opt == 1) nx = qs[i].x, printf("%d\n", solve(nx));
            else wd[qs[i].a].a = qs[i].b;
        }  
    }else {
        sort(wd + 1, wd + 1 + n);
        lp(i, 1, n) pt[wd[i].id] = i;
        h[0] = 1;
        lp(i, 1, n) {
            if(wd[pt[wd[i].l]].crt && wd[pt[wd[i].r]].crt) h[i] = h[i - 1] + 1;
            else if(!wd[pt[wd[i].l]].crt && !wd[pt[wd[i].r]].crt) h[i] = h[i - 1] - 1;
            else h[i] = h[i - 1];
            wd[i].crt = 0;
        }
        sort(qs + 1, qs + 1 + m);
        int j = 0;
        lp(i, 1, m) {
            while(j < n && qs[i].x > wd[j + 1].a) ++j;
            ans[qs[i].id] = h[j];
        }
        lp(i, 1, m) printf("%d\n", ans[i]);
    }
    return 0;
}