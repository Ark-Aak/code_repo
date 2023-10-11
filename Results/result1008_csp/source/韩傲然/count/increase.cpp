#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 2e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(N << 4)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
int head[N], nxt[EG], to[EG], val[EG], tot;
void add(int u, int v, int w) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
int n, m;
map<int, int> f[N][2];
void dfs(int x, int prev, int opt) {
    if(f[x][opt].find(prev) != f[x][opt].end()) return;
    else f[x][0][prev] = -inf, f[x][1][prev] = inf;
    bool flg = 0;
    for(int i = head[x]; i; i = nxt[i]) {
        int ed = to[i], v = val[i];
        if(v > prev) {
            flg = 1, dfs(ed, v, opt ^ 1);
            f[x][0][prev] = max(f[ed][1][v] + 1, f[x][0][prev]);
            f[x][1][prev] = min(f[ed][0][v] + 1, f[x][1][prev]);
        }
    }
    if(!flg) f[x][0][prev] = f[x][1][prev] = 0;
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("increase.in", "r", stdin);
        freopen("increase.out", "w", stdout);
    #endif
    read(n, m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        read(u, v, w); add(u, v, w); add(v, u, w);
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 0; j <= m; j++) f[i][j][0] = -inf, f[i][j][1] = inf;
    // }
    for(int i = 1; i <= n; i++) {
        dfs(i, 0, 0);
        cout << f[i][0][0] << " ";
    }
    cout << "\n";
    return 0;
}