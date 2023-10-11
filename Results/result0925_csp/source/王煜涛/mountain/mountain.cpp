/*
    Program: mountain.cpp
    Author: 1l6suj7
    DateTime: 2023-09-25 09:51:10
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

const ll N = 2000010;

ll n, h[N], f[N];
ll tr[N], mx;

void mdf(ll x, ll y) { while(x <= mx) { tr[x] = max(tr[x], y), x += x & -x; } }

ll qry(ll x) { ll res = 0; while(x) res = max(res, tr[x]), x -= x & -x; return res; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("mountain.in", "r", stdin);
    freopen("mountain.out", "w", stdout);
    cin >> n;
    lp(i, 1, n) cin >> h[i], mx = max(mx, h[i]);
    mx += 2;
    mdf(mx, 0);
    lp(i, 1, n) {
        f[i] += i - qry(mx - h[i] - 1) - 1;
        mdf(mx - h[i], i);
    }
    mst(tr, 0);
    dlp(i, n, 1) {
        f[i] += n + 1 - qry(mx - h[i] - 1) - i - 1;
        mdf(mx - h[i], n + 1 - i);
    }
    lp(i, 1, n) cout << f[i] << endl;
    return 0;
}
