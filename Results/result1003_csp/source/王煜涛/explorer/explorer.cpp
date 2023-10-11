/*
    Program: explorer.cpp
    Author: 1l6suj7
    DateTime: 2023-10-03 09:27:56
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

const int N = 2000010;

int n, m, a[N], l[N], r[N];

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

ll tr[N];

void mdf(int x, ll y) { while(x <= 2 * n) tr[x] += y, x += x & -x; }

ll qry(int x) { ll res = 0; while(x) res += tr[x], x -= x & -x; return res; }

int b[N];
ll calc1() {
    ll res = 0;
    lp(i, 1, n) {
        int r = a[i];
        if(r > n) continue;
        dlp(j, r - 1, i + 1) {
            b[j] = b[j + 1];
            if(a[j] > i && a[j] < r) ++b[j];
        }
        lp(j, i + 1, r - 1) if(a[j] > i && a[j] < r) res += b[a[j] + 1];
        lp(j, i + 1, r - 1) b[j] = 0;
        //cout << i << ' ' << res << endl;
    }
    lp(i, 1, n) {
        int r = a[i];
        lp(j, r + 1, n) if(a[j] <= n) ++b[a[j]];
        lp(j, r + 1, n) b[j] += b[j - 1];
        lp(j, r + 1, n) if(a[j] <= n) res += b[j - 1];
        lp(j, r + 1, n) b[j] = 0;
    }
    return res;
}

bool judge2(int a, int b) {
    if(l[a] > l[b]) swap(a, b);
    return r[a] > l[b] && r[a] < r[b];
}

ll calc2() {
    ll res = 0;
    lp(i, 1, n) {
        int r = a[i];
        lp(j, i + 1, r - 1) {
            if(a[j] > n || a[j] < r) continue;
            res += qry(a[j]);
            mdf(a[j], 1);
        }
        lp(j, i + 1, r - 1) if(a[j] <= n && a[j] > r) mdf(a[j], -1);
    }
    return res;
}

ll C(int a, int b) {
    ll res = 1;
    lp(i, a - b + 1, a) res *= (ll)i;
    lp(i, 1, b) res /= (ll)i;
    return res;
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("explorer.in", "r", stdin);
    freopen("explorer.out", "w", stdout);
    m = n = read();
    n <<= 1;
    int t1, t2;
    bool f = true;
    lp(i, 1, m) {
        t1 = read(), t2 = read();
        if(t1 != 2 * i - 1 || t2 != 2 * i) f = false;
        if(t1 > t2) swap(t1, t2);
        a[t1] = t2, a[t2] = n + t1;
        l[i] = t1, r[i] = t2;
    }
    if(!f) printf("%lld", calc1() + calc2());
    else printf("%lld", C(m, 3));
    return 0;
}