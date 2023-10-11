/*
    Program: path.cpp
    Author: 1l6suj7
    DateTime: 2023-09-27 08:01:05
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

const int N = 1050;

// struct tree {
//     ll s1, s2, s3, s21, s22;
//     ll tg1, tg2, cl;
// }tr[N];

// void maintain(int x) { tr[x].s1 = min(tr[lc(x)].s1, tr[rc(x)].s1), tr[x].s2 = min(tr[lc(x)].s2, tr[rc(x)].s2), tr[x].s3 = min(tr[lc(x)].s3, tr[rc(x)].s3), tr[x].s21 = max(tr[lc(x)].s21, tr[rc(x)].s21), tr[x].s22 = tr[lc(x)].s22 + tr[rc(x)].s22;  }

// void pls1(int x, ll v) { tr[x].s21 = max(tr[x].s21, v), tr[x].tg1 = max(tr[x].tg1, v), tr[x].s2 = tr[x].s21 * tr[x].s22, tr[x].s3 = tr[x].s1 + tr[x].s2; }

// void pls2(int x, ll v, ll len) { tr[x].s22 += v * len, tr[x].tg2 += v, tr[x].s2 = tr[x].s21 * tr[x].s22, tr[x].s3 = tr[x].s1 + tr[x].s2; }

// void cln(int x) { tr[x].s1 = tr[x].s2 = tr[x].s3 = tr[x].tg1 = tr[x].tg2 = tr[x].s21 = tr[x].s22 = 0, tr[x].cl = 1; }

// void pushdown(int x, ll len) { if(tr[x].cl) cln(lc(x)), cln(rc(x)), tr[x].cl = 0; if(tr[x].tg1) pls1(lc(x), tr[x].tg1), pls1(rc(x), tr[x].tg1), tr[x].tg1 = 0; if(tr[x].tg2) pls2(lc(x), tr[x].tg2, len - (len >> 1)), pls2(rc(x), tr[x].tg2, len >> 1), tr[x].tg2 = 0; }

// void mdf21(int now, int l, int r, int ql, int qr, ll v) {
//     if(ql <= l && qr >= r) { pls1(now, v); return; }
//     pushdown(now, r - l + 1);
//     int mid = l + r >> 1;
//     if(ql <= mid) mdf21(lc(now), l, mid, ql, qr, v);
//     if(qr > mid) mdf21(rc(now), mid + 1, r, ql, qr, v);
//     maintain(now);
// }

// void mdf22(int now, int l, int r, int ql, int qr, ll v) {
//     if(ql <= l && qr >= r) { pls2(now, v, r - l + 1); return; }
//     pushdown(now, r - l + 1);
//     int mid = l + r >> 1;
//     if(ql <= mid) mdf22(lc(now), l, mid, ql, qr, v);
//     if(qr > mid) mdf22(rc(now), mid + 1, r, ql, qr, v);
//     maintain(now);
// }

// void mdf1(int now, int l, int r, int x, ll v) {
//     if(l == r) { tr[now].s1 = v, tr[now].s3 = tr[now].s1 + tr[now].s2; return; }
//     pushdown(now, r - l + 1);
//     int mid = l + r >> 1;
//     if(x <= mid) mdf1(lc(now), l, mid, x, v);
//     else mdf1(rc(now), mid + 1, r, x, v);
//     maintain(now);
// }

// ll qry(int now, int l, int r, int ql, int qr) {
//     if(ql <= l && qr >= r) return tr[now].s3;
//     pushdown(now, r - l + 1);
//     int mid = l + r >> 1; ll res = 0;
//     if(ql <= mid) res = qry(lc(now), l, mid, ql, qr);
//     if(qr > mid) res = max(res, qry(rc(now), mid + 1, r, ql, qr));
//     return res;
// }

ll n, K, a[N];
ll s[N], f[N][N];

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
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    n = read(), K = read();
    lp(i, 1, n) a[i] = read(), s[i] = s[i - 1] + a[i];
    // lp(i, 2, K) {
    //     tr[1].cl = 1, tr[1].s1 = tr[1].s2 = tr[1].s3 = tr[1].tg1 = tr[1].tg2 = tr[1].s21 = tr[1].s22 = 0;
    //     lp(j, 1, n) {
    //         if(j > 1) mdf21(1, 1, n, 1, j - 1, a[j]), mdf22(1, 1, n, 1, j - 1, 1);
    //         if(j >= i && j > 1) f[i][j] = qry(1, 1, n, 1, j - 1) - s[j];
    //         mdf1(1, 1, n, j, f[i - 1][j] + s[j]);
    //         cout << i << ' ' << j << ' ' << f[i][j] << endl;
    //     }
    // }
    ll t = 0;
    mst(f, 0x3f);
    lp(i, 1, n) t = max(t, a[i]), f[1][i] = t * i - s[i];
    lp(i, 2, K + 1) {
        lp(j, i, n) {
            ll t2 = a[j];
            dlp(k, j - 1, 1) {
                f[i][j] = min(f[i][j], f[i - 1][k] + t2 * (j - k) - (s[j] - s[k]));
                t2 = max(t2, a[k]);
            }
        }
    }
    printf("%lld", f[K + 1][n]);
    return 0;
}
/*
f[i][j] = f[i - 1][k] + S[k] + A[k + 1][j] * (j - k) - S[j]
*/