/*
    Program: easiest.cpp
    Author: 1l6suj7
    DateTime: 2023-09-28 09:20:36
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

const int N = 100010;

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

int n, m, a[N];

bool judge(int l, int r) {
    dlp(i, r - 1, l + 1) {
        if(a[i] > a[r]) return true;
    }
    bool flg = 1;
    lp(i, l + 1, r - 1) if(a[i] > a[l]) flg = 0;
    if(l + 1 == r || flg) return true;
    return false;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("easiest.in", "r", stdin);
    freopen("easiest.out", "w", stdout);
    n = read(), m = read();
    lp(i, 1, n) a[i] = read();
    int op, l1, r1, l2, r2;
    lp(i, 1, m) {
        op = read(), l1 = read(), r1 = read(), l2 = read(), r2 = read();
        if(op == 1) {
            int res = l2 - l1, lst = a[r2];
            lp(j, r2 + 1, r1) {
                if(a[j] > lst) lst = a[j];
                else ++res;
            }
            printf("%d\n", res);
        }else {
            ll res = 0;
            lp(i, l2, r2 - 1) {
                lp(j, i + 1, r2) {
                    if(judge(i, j)) ++res;
                }
            }
            printf("%lld\n", res);
        }
    }
    return 0;
}