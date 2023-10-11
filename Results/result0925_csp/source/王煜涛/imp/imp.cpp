#include <bits/stdc++.h>
#define ll long long
#define lc(x) (x << 1)
#define rc(x) ((x << 1) ^ 1)
#define MAX8 0x3f3f3f3f3f3f3f3f

using namespace std;

const int N = 800010;

struct node {
    ll x, y, c;

    bool operator < (const node & t) const { return y < t.y; }
}nd[N], tg[N];

struct tree {
    ll sum, add, mn;
}tr[N << 2];

int n;
ll ans, a[N];
ll trs[N], tot;

int getv(ll x) { return lower_bound(trs + 1, trs + 1 + tot, x) - trs; }

void pls(int x, ll v, ll l, ll r) { tr[x].add += v, tr[x].sum += v * (r - l + 1), tr[x].mn += v; }

void maintain(int x) { tr[x].sum = tr[lc(x)].sum + tr[rc(x)].sum, tr[x].mn = min(tr[lc(x)].mn, tr[rc(x)].mn); }

void pushdown(int x, int l, int r) {
    int mid = l + r >> 1;
    pls(lc(x), tr[x].add, l, mid), pls(rc(x), tr[x].add, mid + 1, r);
    tr[x].add = 0;
}

void build(int now, int l, int r) {
    if(l == r) { tr[now].sum = 0,  tr[now].add = 0, tr[now].mn = -trs[l + 1]; return; }
    int mid = l + r >> 1;
    build(lc(now), l, mid), build(rc(now), mid + 1, r);
    maintain(now);
}

void mdf(int now, int l, int r, int ql, int qr, ll v) {
    if(ql <= l && qr >= r) { pls(now, v, l, r); return; }
    pushdown(now, l, r);
    int mid = l + r >> 1;
    if(ql <= mid) mdf(lc(now), l, mid, ql, qr, v);
    if(qr > mid) mdf(rc(now), mid + 1, r, ql, qr, v);
    maintain(now);
}

ll qry(int now, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return tr[now].mn;
    pushdown(now, l, r);
    int mid = l + r >> 1; ll res = MAX8;
    if(ql <= mid) res = min(res, qry(lc(now), l, mid, ql, qr));
    if(qr > mid) res = min(res, qry(rc(now), mid + 1, r, ql, qr));
    return res;
}

ll qry2(int now, int l, int r, int x) {
    if(l == r) return tr[now].sum;
    pushdown(now, l, r);
    int mid = l + r >> 1;
    if(x <= mid) return qry2(lc(now), l, mid, x);
    else return qry2(rc(now), mid + 1, r, x);
}

int main() {
    freopen("imp.in", "r", stdin);
    freopen("imp.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> nd[i].x >> nd[i].y >> nd[i].c, trs[++tot] = nd[i].x, trs[++tot] = nd[i].y;
    trs[++tot] = -MAX8;
    sort(trs + 1, trs + 1 + tot);
    tot = unique(trs + 1, trs + 1 + tot) - trs - 1;
    for(int i = 1; i <= n; ++i) nd[i].x = getv(nd[i].x), nd[i].y = getv(nd[i].y);
    for(int i = 1; i <= n; ++i) {
        if(nd[i].x > nd[i].y) tg[i].x = nd[i].y, tg[i].y = nd[i].x;
        else tg[i].x = nd[i].x, tg[i].y = nd[i].y;
        tg[i].c = nd[i].c;
    }
    sort(tg + 1, tg + 1 + n);
    build(1, 1, tot);
    tg[0].y = 1;
    for(int i = 1; i <= n; ++i) {
        mdf(1, 1, tot, tg[i].x, tot, tg[i].c);
        if(tg[i + 1].y == tg[i].y) continue;
        ans = max(ans, qry2(1, 1, tot, tg[i].y) - trs[tg[i].y] - qry(1, 1, tot, 1, tg[i].y - 1));
    }
    cout << ans;
    return 0;
}
/*
f[i] = max(A[i] - A[j - 1] - i + j)
     = max(A[i] - i - (A[j - 1] - j))

6
2 3 4
1 4 -4
0 0 2
1 0 -5
3 1 -1
1 1 3
*/