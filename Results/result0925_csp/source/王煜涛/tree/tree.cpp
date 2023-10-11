/*
    Program: tree.cpp
    Author: 1l6suj7
    DateTime: 2023-09-25 11:31:59
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

const ll N = 10010, MOD = 1e9 + 7;

struct edge {
    int v, nxt;
}e[N << 2];

int n, k;
int head[N], tot, fa[N], p[N];
ll ans;
bool vis[N];

void add(int u, int v) {
    e[++tot].v = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}

void dfs(int now) {
    for(int i = head[now]; i; i = e[i].nxt) {
        int v = e[i].v;
        if(v == fa[now]) continue;
        fa[v] = now;
        dfs(v);
    }
}

int fd(int x) { return x == fa[x]? x : (fa[x] = fd(fa[x])); }

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

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    n = read(), k = read();
    int u, v;
    lp(i, 1, n - 1) u = read(), v = read(), add(u, v), add(v, u);
    dfs(1);
    lp(i, 1, n) {
        lp(j, 1, n) p[j] = j;
        ll cnt = 0;
        mst(vis, 0);
        lp(j, i, n) {
            vis[j] = 1;
            ++cnt;
            for(int l = head[j]; l; l = e[l].nxt) {
                int v = e[l].v;
                if(vis[v]) --cnt, fa[fd(v)] = fd(j);
            }
            if(k == 1) ans = (ans + cnt) % MOD;
            else ans = (ans + cnt * cnt % MOD) % MOD;
        }
    }
    printf("%lld", ans);
    return 0;
}
