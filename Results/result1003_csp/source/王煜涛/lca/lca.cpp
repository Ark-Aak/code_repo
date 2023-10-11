/*
    Program: lca.cpp
    Author: 1l6suj7
    DateTime: 2023-10-03 08:32:36
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

const int N = 500010;

int n;

struct edge {
    int v, nxt;
}e[N << 1];

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

int head[N], en;
int fa[N];

void add(int u, int v) { e[++en] = {v, head[u]}, head[u] = en; }

ll f[N], g[N], sz[N];

void dfs1(int now) {
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        fa[v] = now, dfs1(v);
        f[now] += f[v], sz[now] += sz[v];
    }
    ++sz[now];
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        f[now] += sz[v] * (sz[now] - sz[v]) * (ll)now;
    }
    f[now] += sz[now] * (ll)now;
}

void dfs2(int now) {
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        g[v] = g[now] + 2l * sz[v] * (sz[now] - sz[v]) * (ll)(v - now);
        ll t = sz[v]; sz[v] = sz[now];
        dfs2(v); sz[v] = t;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    n = read();
    int u, v;
    lp(i, 1, n - 1) u = read(), v = read(), add(u, v), add(v, u);
    dfs1(1), g[1] = f[1];
    dfs2(1);
    lp(i, 1, n) printf("%lld ", g[i]);
    return 0;
}