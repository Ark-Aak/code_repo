/*
    Program: tower.cpp
    Author: 1l6suj7
    DateTime: 2023-10-09 08:07:59
    Description: 
*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;

const int N = 200010, M = 110;

struct edge {
    int v; ll w; int nxt;
}E[N << 1];
int en, head[N];

void add(int u, int v, ll w) { E[++en] = {v, w, head[u]}, head[u] = en; }

int n, K, c[N], s[M][M];

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

struct node { int pos, w; ll dis; };

queue<node> q;
ll dis[N];
bool vis[N];
void spfa() {
    mst(dis, 0x3f), q.push({1, 0, 0}), vis[1] = 1, dis[1] = 0;
    while(!q.empty()) {
        node frt = q.front(); int u = frt.pos, pre = frt.w, d = frt.dis;
        q.pop();
        //cout << u << ' ' << pre << endl;
        if(u <= n) vis[u] = 0;
        for(int i = head[u]; i; i = E[i].nxt) {
            int v = E[i].v, w = v <= n? (E[i].w < pre? -E[i].w : E[i].w - 2 * pre) : E[i].w;
            if(v <= n && d + w >= dis[v]) continue;
            dis[v] = d + w;
            if(v <= n && vis[v]) continue;
            q.push({v, u <= n? w : pre, dis[v]});
        }
    }
}

signed main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    freopen("tower.in", "r", stdin);
    freopen("tower.out", "w", stdout);
    //ll t1 = clock();
    n = read(), K = read();
    lp(i, 1, n) c[i] = read(), add(i, n + c[i], i), add(n + K + c[i], i, i);
    char ch;
    lp(i, 1, K) {
        c[n + i] = c[n + K + i] = i;
        lp(j, 1, K) {
            ch = getchar();
            while(ch != '0' && ch != '1') ch = getchar();
            if(ch == '1') add(n + i, n + K + j, 0);
        }
    }
    spfa();
    //ll t2 = clock();
    //cout << "time: " << t2 - t1 << endl;
    if(dis[n] <= 1e10) printf("%lld", dis[n]);
    else printf("-1");
    return 0;
}