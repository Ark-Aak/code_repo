/*
    Program: trade.cpp
    Author: 1l6suj7
    DateTime: 2023-09-28 09:30:47
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

const int N = 1010, M = 5010;

struct node {
    int pos; ll dis, tm;
};

struct edge {
    int v, nxt;
}e[M << 1];

int n, m, C; ll c[N], ans;
int head[N], tot;
ll tr[N][M << 1]; int mx = 4000;
bool vis[N][M << 1];

void mdf(int no, int x, ll y) { while(x <= mx) tr[no][x] = max(tr[no][x], y), x += x & -x; }

ll qry(int no, int x) { ll y = -MAX8; while(x) y = max(y, tr[no][x]), x -= x & -x; return y; }

void add(int u, int v) { e[++tot] = {v, head[u]}, head[u] = tot; }

queue<node> q;
void SPFA() {
    q.push({1, 0, 0}), vis[1][0] = 1;
    mst(tr, -0x3f), mdf(1, 1, 0);
    while(!q.empty()) {
        node t = q.front(); q.pop();
        int u = t.pos;
        vis[u][t.tm] = 0;
        if(u == 1) ans = max(ans, t.dis - C * t.tm * t.tm);
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(t.dis + c[v] - C * t.tm * t.tm <= qry(v, t.tm + 1)) continue;
            mdf(v, t.tm + 1, t.dis + c[v] - C * t.tm * t.tm);
            if(!vis[v][t.tm + 1]) q.push({v, t.dis + c[v], t.tm + 1});
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

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("trade.in", "r", stdin);
    freopen("trade.out", "w", stdout);
    n = read(), m = read(), C = read();
    lp(i, 1, n) c[i] = read();
    int u, v;
    lp(i, 1, m) u = read(), v = read(), add(u, v);
    SPFA();
    printf("%lld\n", ans);
    return 0;
}