/*
    Program: magic.cpp
    Author: 1l6suj7
    DateTime: 2023-10-04 10:42:41
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

const int N = 400010;

struct edge {
    int u, v; ll w; int nxt;

    bool operator < (const edge & t) const { return w < t.w; }
}e[N << 1];

struct node {
    int pos; ll dis, pre;

    bool operator < (const node & t) const { return dis > t.dis; }
};

int n, c[N], p1[N], p2[N], p3[N], p4[N];
vector<int> pos[N], no;
int fa[N];
int head[N], en, rt;
ll dis[N], ans;

void add(int u, int v, ll w) { e[++en] = {u, v, w, head[u]}, head[u] = en; }

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

int fa2[N << 1];
int fd2(int x) { return x == fa2[x]? x : (fa2[x] = fd2(fa2[x])); }

void krus() {
    sort(e + 1, e + 1 + en);
    for(auto t : no) fa2[t] = t;
    lp(i, 1, en) {
        int t1 = fd2(e[i].u), t2 = fd2(e[i].v);
        if(t1 != t2) ans += e[i].w, fa2[t1] = t2;
    }
}

int fd(int x) { return x == fa[x]? x : (fa[x] = fd(fa[x])); }

bool vis[N];
signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    n = read();
    lp(i, 1, n) {
        c[i] = read(), p1[i] = read(), p2[i] = read(), p3[i] = read(), p4[i] = read();
        pos[p1[i]].emplace_back(i), pos[p2[i]].emplace_back(i), pos[p3[i]].emplace_back(n + i), pos[p4[i]].emplace_back(n + i);
    }
    lp(i, 1, 2 * n) fa[i] = i;
    lp(i, 1, 2 * n) {
        int t1 = fd(pos[i][0]), t2 = fd(pos[i][1]);
        fa[t1] = t2;
    }
    lp(i, 1, n) {
        int t1 = fd(i), t2 = fd(n + i);
        if(t1 == t2) continue;
        if(!rt) rt = t1;
        if(!vis[t1]) vis[t1] = 1, no.push_back(t1);
        if(!vis[t2]) vis[t2] = 1, no.push_back(t2);
        add(t1, t2, c[i]), add(t2, t1, c[i]);
    }
    krus();
    printf("%lld", ans);
    return 0;
}