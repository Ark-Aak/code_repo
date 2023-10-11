/*
    Program: double.cpp
    Author: 1l6suj7
    DateTime: 2023-10-07 09:53:41
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

const int N = 2010;

struct edge {
    int v, w, nxt;
}e[N << 1];

int head[N], en;

void add(int u, int v, int w) { e[++en] = {v, w, head[u]}, head[u] = en; }

struct node {
    int pos; ll dis;

    bool operator < (const node & t) const { return dis > t.dis; }
};

priority_queue<node> q;
bool vis[N];
ll dis[N];
void dij(int s, int t) {
    while(!q.empty()) q.pop();
    mst(dis, 0x3f), mst(vis, 0);
    q.push({s, 0}), dis[s] = 0;;
    while(!q.empty()) {
        node tt = q.top(); q.pop();
        int u = tt.pos;
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(vis[v] || dis[u] + e[i].w >= dis[v]) continue;
            dis[v] = dis[u] + e[i].w, q.push({v, dis[v]});
        }
    }
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

int n, Q;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("double.in", "r", stdin);
    freopen("double.out", "w", stdout);
    n = read();
    int w;
    lp(i, 1, n) w = read(), add(2 * i - 1, 2 * i, w), add(2 * i, 2 * i - 1, w);
    int u, v, w1, w2;
    lp(i, 1, n - 1) {
        u = read(), v = read(), w1 = read(), w2 = read();
        add(2 * u - 1, 2 * v - 1, w1), add(2 * u, 2 * v, w2);
    }
    Q = read();
    lp(i, 1, Q) {
        u = read(), v = read();
        dij(u, v);
        printf("%lld\n", dis[v]);
    }
    return 0;
}