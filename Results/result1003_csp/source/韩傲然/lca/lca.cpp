#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 5e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
int head[N], to[EG], nxt[EG], tot, n;
int f[N], siz[N], g[N];
void add(int u, int v) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}
void dfs(int x, int fa) {
    siz[x] = 1;
    for(int i = head[x]; i; i = nxt[i]) {
        int ed = to[i];
        if(ed == fa) continue;
        dfs(ed, x);
        siz[x] += siz[ed]; ;
        f[x] += f[ed];
    }
    f[x] += 2 * siz[x] * x - x;
    for(int i = head[x]; i; i = nxt[i]) {
        int ed = to[i];
        if(ed == fa) continue;
        f[x] += (siz[x] - 1 - siz[ed]) * siz[ed] * x;
    }
}
void dfs2(int x, int fa) {
    if(x != 1) {
        g[x] = g[fa] - 2 * fa * (siz[fa] - 1 - siz[x]) * siz[x] - fa * 2 * siz[x];
        g[x] += 2 * x * (siz[1] - siz[x]) * (siz[x] - 1) + 2 * x * (siz[1] - siz[x]);
        siz[x] = siz[1];
    }
    for(int i = head[x]; i; i = nxt[i]) {
        int ed = to[i];
        if(ed == fa) continue;
        dfs2(ed, x);
    }
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("lca.in", "r", stdin);
    freopen("lca.out", "w", stdout);
    read(n);
    for(int i = 1, x, y; i < n; i++) read(x, y), add(x, y), add(y, x);
    dfs(1, -1);
    g[1] = f[1];
    dfs2(1, -1);
    
    for(int i = 1; i <= n; i++) cout << g[i] << " ";
    return 0;
}
