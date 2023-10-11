#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1e6 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 1)

#define ls (k << 1)
#define rs (k << 1 | 1)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
int n, q;
int head[N], to[EG], nxt[EG], tot, deg[N];
void add(int u, int v) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}
int s[N], jccnt;
namespace solve1 {
    constexpr int N = 5000;
    int top[N], siz[N], dep[N], fa[N], son[N], dfn[N], rnk[N], cnt, st[N][20], lg[N], LG = 19;
    void dfs1(int x, int f) {
        dep[x] = dep[f] + 1; fa[x] = f; siz[x] = 1;
        for(int i = head[x]; i; i = nxt[i]) {
            int ed = to[i]; if(ed == f) continue;
            dfs1(ed, x); siz[x] += siz[ed];
            if(siz[ed] > siz[son[x]]) son[x] = ed;
        }
    }
    void dfs2(int x, int t) {
        top[x] = t; dfn[x] = ++cnt; rnk[dfn[x]] = x;
        if(son[x]) dfs2(son[x], t);
        for(int i = head[x]; i; i = nxt[i]) {
            int ed = to[i]; if(ed == son[x] || ed == fa[x]) continue;
            dfs2(ed, ed);
        }
    }
    inline void init() {
        lg[0] = -1;
        for(int i = 1; i <= n; i++) st[i][0] = rnk[i], lg[i] = lg[i >> 1] + 1;
        for(int j = 1; j <= LG; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline int query(int l, int r) {
        int len = r - l + 1;
        return min(st[l][lg[len]], st[r - (1 << lg[len]) + 1][lg[len]]);
    }
    int lca(int x, int y, int &mn) {
        while(top[x] != top[y]) {
            if(dep[top[x]] < dep[top[y]]) swap(x, y);
            mn = min(mn, query(dfn[top[x]], dfn[x]));
            x = fa[top[x]];
        }
        if(dep[x] > dep[y]) swap(x, y);
        mn = min(mn, query(dfn[x], dfn[y]));
        return x;
    }
    void main() {
        dfs1(1, 0); dfs2(1, 1);
        init();
        for(int i = 1; i <= q; i++) {
            int x; string str; cin >> str >> x;
            if(str[0] == 'J') s[++jccnt] = x;
            else {
                int ans = inf;
                for(int j = 1; j <= jccnt; j++) {
                    lca(x, s[j], ans);
                }
                cout << ans << "\n";
            }
        }
    }
}
namespace solve2 {
    constexpr int N = 1e6 + 10;
    int lpos, rpos, a[N], pos[N], cnt, lg[N], LG = 24, st[N][25];
    void init() {
        lpos = n + 1, rpos = 0;
        int cur = -1;
        for(int i = 1; i <= n; i++) {
            if(deg[i] == 1) {
                cur = i; pos[i] = 1; a[++cnt] = i; break;
            }
        }
        int pre = -1;
        while(cnt < n) {
            for(int i = head[cur]; i; i = nxt[i]) {
                int ed = to[i]; if(ed == pre) continue;
                a[++cnt] = ed; pos[ed] = cnt;
                pre = cur, cur = ed; break;
            }
        }
        lg[0] = -1;
        for(int i = 1; i <= n; i++) st[i][0] = a[i], lg[i] = lg[i >> 1] + 1;
        for(int j = 1; j <= LG; j++) {
            for(int i = 1; i + (1 << j) - 1 <= n; i++) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    inline int query(int l, int r) {
        int len = r - l + 1;
        return min(st[l][lg[len]], st[r - (1 << lg[len]) + 1][lg[len]]);
    }
    void main() {
        init();
        for(int i = 1; i <= q; i++) {
            int x; string str; cin >> str >> x;
            if(str[0] == 'J') lpos = min(lpos, pos[x]), rpos = max(rpos, pos[x]);
            else {
                int ans = inf;
                if(lpos <= pos[x]) ans = min(ans, query(lpos, pos[x]));
                if(rpos >= pos[x]) ans = min(ans, query(pos[x], rpos));
                cout << ans << "\n";
            }
        }
    }
    
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("network.in", "r", stdin);
        freopen("network.out", "w", stdout);
    #endif
    cin >> n >> q; 
    for(int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; add(u, v); add(v, u), deg[u]++, deg[v]++;
    }
    if(n <= 4000) solve1 :: main();
    else solve2 :: main();
    return 0;
}