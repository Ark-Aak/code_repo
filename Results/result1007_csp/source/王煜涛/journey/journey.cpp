/*
    Program: journey.cpp
    Author: 1l6suj7
    DateTime: 2023-10-07 10:42:55
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

const int N = 1010, M = 200010;

struct edge {
    int id, v, nxt;
}e[M << 1];

int en, head[N];

void add(int id, int u, int v) { e[++en] = {id, v, head[u]}, head[u] = en; }

int dis[N];
bool vis[N];
//queue<int> q;
// void spfa(int s, int l) {
//     mst(dis, 0x3f);
//     q.push(s), dis[s] = l, vis[s] = 1;
//     while(!q.empty()) {
//         int u = q.front();
//         q.pop();
//         vis[u] = 0;
//         for(int i = head[u]; i; i = e[i].nxt) {
//             int v = e[i].v;
//             if(e[i].id < dis[v] && dis[u] <= e[i].id) {
//                 dis[v] = e[i].id;
//                 if(!vis[v]) q.push(v), vis[v] = 1;
//             }
//         }
//     }
// }

struct node {
    int pos, dis;

    bool operator < (const node & t) const { return t.dis > dis; }
};

priority_queue<node> q;
void dij(int s, int l, int et) {
    while(!q.empty()) q.pop();
    mst(dis, 0x3f), mst(vis, 0);
    q.push({s, l}), dis[s] = l;
    while(!q.empty()) {
        node t = q.top(); q.pop();
        int u = t.pos;
        if(vis[u]) continue;
        vis[u] = 1;
        if(u == et) return;
        for(int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v;
            if(vis[v]) continue;
            if(e[i].id < dis[v] && dis[u] <= e[i].id) dis[v] = e[i].id, q.push({v, dis[v]});
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

struct ques {
    int id, l, r, s, t;
}qs[M];

int n, m, Q, ans[M];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    n = read(), m = read(), Q = read();
    int u, v;
    lp(i, 1, m) u = read(), v = read(), add(i, u, v), add(i, v, u);
    bool fl = 1, fl2 = 1;
    lp(i, 1, Q) {
        qs[i].l = read(), qs[i].r = read(), qs[i].s = read(), qs[i].t = read(), qs[i].id = i;
        if(qs[i].l != 1) fl = 0;
        if(qs[i].l != qs[i].r) fl2 = 0;
    }
    if(fl) {
        sort(qs + 1, qs + 1 + Q, [] (ques t1, ques t2) { return t1.s < t2.s; });
        lp(i, 1, Q) {
            if(qs[i].s != qs[i - 1].s) dij(qs[i].s, 1, 0);
            if(dis[qs[i].t] <= qs[i].r) ans[qs[i].id] = 1;
            else ans[qs[i].id] = 0;
        }
        lp(i, 1, Q) {
            if(ans[i]) printf("Yes\n");
            else printf("No\n");
        }
        return 0;
    }
    if(fl2) {
        lp(i, 1, Q) {
            if(qs[i].s == qs[i].t) { ans[i] = 1; continue; }
            for(int j = head[qs[i].s]; j; j = e[j].nxt) if(e[j].v == qs[i].t && e[j].id == qs[i].l) ans[i] = 1;
        }
        lp(i, 1, Q) {
            if(ans[i]) printf("Yes\n");
            else printf("No\n");
        }
        return 0;
    }
    lp(i, 1, Q) {
        if(qs[i].s != qs[i].t) dij(qs[i].s, qs[i].l, qs[i].t);
        if(qs[i].s == qs[i].t || dis[qs[i].t] <= qs[i].r) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}