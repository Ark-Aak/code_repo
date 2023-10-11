/*
    Program: network.cpp
    Author: 1l6suj7
    DateTime: 2023-10-08 09:41:15
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

struct edge {
    int v, nxt;
}e[N];
int en, head[N], fa[N];
vector<int> E[N];

int md[N];
vector<int> qy[N];

int n, Q, ans[N];
int tr[N];

void mdf(int x, int y) { /*cout << x << ' ' << y << endl;*/ while(x <= Q) tr[x] = min(tr[x], y), x += x & -x; }

void del(int x) { while(x <= Q) tr[x] = MAX4, x += x & -x;; }

int qry(int x) { /*cout << x << endl;*/ int res = MAX4; while(x) res = min(res, tr[x]), x -= x & -x; return res; }

void add(int u, int v) { e[++en] = {v, head[u]}, head[u] = en; }

struct node {
    int pos, dis;
};

queue<node> q;
void upd(int x, int t, int b) {   //update query
    if(t > Q) return;
    q.push({x, min(x, b)});
    while(!q.empty()) {
        int u = q.front().pos, d = q.front().dis; q.pop();
        for(int i = 0; i < qy[u].size(); ++i) {
            ans[qy[u][i]] = min(ans[qy[u][i]], qry(qy[u][i]))/*, cout << u << ' ' << ans[qy[u][i]] << endl*/;
            if(t <= qy[u][i]) ans[qy[u][i]] = min(ans[qy[u][i]], d);
        }
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(v == fa[u]) continue;
            q.push({v, min(d, v)});
        }
    }
}

vector<int> cl;
int upd2(int now) {     //update modify
    int t = MAX4;
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        t = min(t, upd2(v));
    }
    if(md[now] <= Q) t = min(t, md[now]);
    if(t <= Q) /*cout << t << ' ' << now << endl,*/ mdf(t, now), cl.push_back(t);
    return t;
}

void solve(int now) {
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        fa[v] = now, solve(v);
    }
    //cout << now << endl;
    int t = md[now];
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        upd(v, t, now);
        t = min(t, upd2(v));
        if(t <= Q) mdf(t, now), cl.push_back(t);
    }
    for(int i = 0; i < qy[now].size(); ++i) ans[qy[now][i]] = min(ans[qy[now][i]], qry(qy[now][i]))/*, cout << now << ' ' << qy[now][i] << ' ' << ans[qy[now][i]] << endl*/;
    for(int i = 0; i < cl.size(); ++i) del(cl[i]);  cl.clear();
    t = md[now];
    for(int i = 0; i < E[now].size(); ++i) {
        int v = E[now][i];
        if(v == fa[now]) continue;
        upd(v, t, now);
        t = min(t, upd2(v));
        if(t <= Q) mdf(t, now), cl.push_back(t);
        //cout << now << ' ' << v << ' ' << qry(2) << endl;
    }
    for(int i = 0; i < cl.size(); ++i) del(cl[i]);  cl.clear();
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

int op[N];

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("network.in", "r", stdin);
    freopen("network.out", "w", stdout);
    n = read(), Q = read();
    int u, v;
    lp(i, 1, n - 1) {
        u = read(), v = read();
        add(u, v), add(v, u);
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    char opt[10]; int x;
    mst(md, 0x3f);
    lp(i, 1, Q) {
        scanf("%s", opt), x = read();
        if(opt[0] == 'J') md[x] = min(md[x], i);
        else qy[x].push_back(i), op[i] = 1;
    }
    mst(ans, 0x3f), mst(tr, 0x3f);
    solve(1);
    lp(i, 1, Q) if(op[i]) printf("%d\n", ans[i]);
    return 0;
}
/*
7 6
1 2
1 3
2 4
2 5
3 6
3 7
JC 6
Q 6
JC 2
Q 6
JC 5
Q 4

*/