/*
    Program: robot.cpp
    Author: 1l6suj7
    DateTime: 2023-10-02 08:00:50
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

const int N = 120010;

struct edge {
    int v, nxt;
}e[N << 1];

struct tree {
    int lc, rc, sum;
}tr[N << 8], tr2[N << 8];
int trn, rt[N], trn2, rt2[N];

int T, n, m;
int head[N], tot;

void maintain(int x) { tr[x].sum = tr[tr[x].lc].sum + tr[tr[x].rc].sum; }

int mdf(int now, int l, int r, int x, int v) {
    int cp = ++trn;
    tr[cp] = tr[now];
    if(l == r) { ++tr[cp].sum; return cp; }
    int mid = l + r >> 1;
    if(x <= mid) tr[cp].lc = mdf(tr[now].lc, l, mid, x, v);
    else tr[cp].rc = mdf(tr[now].rc, mid + 1, r, x, v);
    maintain(cp);
    //cout << now << ' ' << cp << ' ' << tr[cp].sum << endl;
    return cp;
}

int qry(int now, int l, int r, int ql, int qr) {
    if(ql <= l && qr >= r) return tr[now].sum;
    int mid = l + r >> 1, res = 0;
    if(ql <= mid) res = qry(tr[now].lc, l, mid, ql, qr);
    if(qr > mid) res += qry(tr[now].rc, mid + 1, r, ql, qr);
    return res;
}

void build(int & now, int l, int r) {
    now = ++trn;
    if(l == r) { tr[now].sum = tr[now].lc = tr[now].rc = 0; return; }
    int mid = l + r >> 1;
    build(tr[now].lc, l, mid), build(tr[now].rc, mid + 1, r);
    maintain(now);
}

void add(int u, int v) { e[++tot] = {v, head[u]}, head[u] = tot; }

int dep[N], grd[N], fa[N], sz[N], son[N], dfn[N], cnt;
void dfs1(int now) {
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        fa[v] = now, dep[v] = dep[now] + 1, dfs1(v);
        sz[now] += sz[v];
        if(sz[v] > sz[son[now]]) son[now] = v;
    }
    ++sz[now];
}

void dfs2(int now, int lst) {
    grd[now] = lst, dfn[now] = ++cnt;
    if(son[now]) dfs2(son[now], lst);
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now] || v == son[now]) continue;
        dfs2(v, v);
    }
}

int LCA(int a, int b) {
    while(grd[a] != grd[b]) {
        if(dep[grd[a]] < dep[grd[b]]) swap(a, b);
        a = fa[grd[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    return b;
}

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

void maintain2(int x) { tr2[x].sum = tr2[tr2[x].lc].sum + tr2[tr2[x].rc].sum; }

int merge(int a, int b) {
    if(!a || !b) return a + b;
    int x = ++trn2;
    tr2[x].lc = merge(tr2[a].lc, tr2[b].lc);
    tr2[x].rc = merge(tr2[a].rc, tr2[b].rc);
    maintain2(x);
    return x;
}

int mdf2(int now, int l, int r, int x, int v) {
    int cp = ++trn2;
    tr2[cp] = tr2[now];
    if(l == r) { ++tr2[cp].sum; return cp; }
    int mid = l + r >> 1;
    if(x <= mid) tr2[cp].lc = mdf(tr2[now].lc, l, mid, x, v);
    else tr2[cp].rc = mdf(tr2[now].rc, mid + 1, r, x, v);
    maintain2(cp);
    return cp;
}

int qry2(int now, int l, int r, int ql, int qr) {
    if(ql > qr) swap(ql, qr);
    if(ql <= l && qr >= r) return tr2[now].sum;
    int mid = l + r >> 1, res = 0;
    if(ql <= mid) res = qry(tr2[now].lc, l, mid, ql, qr);
    if(qr > mid) res += qry(tr2[now].rc, mid + 1, r, ql, qr);
    //cout << now << ' ' << l << ' ' << r << ' ' << res << ' ' << tr[now].sum << endl;
    return res;
}

vector<int> rp[N];
void dfs3(int now) {
    rt[now] = rt[fa[now]];
    for(auto t : rp[now]) rt[now] = mdf(rt[now], 1, n, dfn[t], 1);
    //cout << now << ' ' << rt[now] << endl;
    //cout << now << ' ' << qry(1, 1, n, 1, 3) << endl;
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        dfs3(v);
        rt2[now] = merge(rt2[now], rt2[v]);
    }
    if(!rt2[now]) rt2[now] = ++trn2;
    for(auto t : rp[now]) rt2[now] = mdf2(rt2[now], 1, n, dfn[t], 1);
}

int qry_line(int a, int b, int trt) {
    int res = 0;
    while(grd[a] != grd[b]) {
        if(dep[grd[a]] < dep[grd[b]]) swap(a, b);
        res += qry(trt, 1, n, dfn[grd[a]], dfn[a]), a = fa[grd[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    res += qry(trt, 1, n, dfn[b], dfn[a]);
    //cout << a << ' ' << b << ' ' << trt << ' ' << res << endl;
    return res;
}

int qry_line2(int a, int b, int trt) {
    int res = 0;
    while(grd[a] != grd[b]) {
        if(dep[grd[a]] < dep[grd[b]]) swap(a, b);
        res += qry2(trt, 1, n, dfn[grd[a]], dfn[a]), a = fa[grd[a]];
    }
    if(dep[a] < dep[b]) swap(a, b);
    res += qry2(trt, 1, n, dfn[b], dfn[a]);
    //cout << a << ' ' << b << ' ' << trt << ' ' << res << endl;
    return res;
}

int p[N], q[N];

bool judge() {
    lp(i, 1, m) {
        int t = LCA(p[i], q[i]);
        int res = 0;
        if(t == q[i]) {
            res += qry_line2(p[i], q[i], rt2[q[i]]);
            for(int i = head[p[i]]; i; i = e[i].nxt) {
                int v = e[i].v;
                if(v != fa[p[i]]) res -= qry_line2(p[i], q[i], rt2[v]);
            }
        }else {
            res = qry_line(p[i], q[i], rt[p[i]]) + qry_line(p[i], q[i], rt[fa[q[i]]]) - qry_line(p[i], q[i], rt[t]) - qry_line(p[i], q[i], rt[fa[t]]);
            //cout << res << endl;
            res += qry_line2(p[i], q[i], rt2[q[i]]);
        }
        //cout << p[i] << ' ' << q[i] << ' ' << res << endl;
        //cout << p[i] << ' ' << q[i] << ' ' << t << ' ' << res << endl;
        if(res > 1) return false;
    }
    return true;
}

bool vis[N];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    T = read();
    while(T--) {
        trn = 0, trn2 = 0, tot = 0, mst(son, 0), mst(fa, 0), mst(sz, 0), mst(head, 0), mst(rt, 0), mst(rt2, 0), mst(vis, 0), cnt = 0;
        n = read();
        int u, v;
        lp(i, 1, n - 1) u = read(), v = read(), add(u, v), add(v, u);
        dfs1(1), dfs2(1, 1);
        m = read();
        bool f = true;
        lp(i, 1, m) {
            p[i] = read(), q[i] = read();
            if(vis[q[i]]) f = false;
            rp[p[i]].emplace_back(q[i]), vis[q[i]] = 1;
        }
        if(f) {
            build(rt[0], 1, n), dfs3(1);
            if(judge()) printf("Yes\n");
            else printf("No\n");
        }else printf("No\n");
        lp(i, 1, m) rp[p[i]].clear();
        for(int i = 1; i <= trn; i += 4) {
            tr[i] = {0, 0, 0};
            tr[i + 1] = {0, 0, 0};
            tr[i + 2] = {0, 0, 0};
            tr[i + 3] = {0, 0, 0};
        }
        for(int i = 1; i <= trn2; i += 4) {
            tr2[i] = {0, 0, 0};
            tr2[i + 1] = {0, 0, 0};
            tr2[i + 2] = {0, 0, 0};
            tr2[i + 3] = {0, 0, 0};
        }
    }
    return 0;
}
