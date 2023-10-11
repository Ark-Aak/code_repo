#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1010, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(5000)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
int n, m, c;
int V[N];
struct node {
    int x, v, t;
};
node q[N * 1000];
int l = 1, r = 0;
int vis[N], f[N][N];
int head[N], to[EG], nxt[EG], tot;
void add(int u, int v) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}
void SPFA() {
    q[++r] = {1, 0, 0};
    while(l <= r) {
        int x = q[l].x, v = q[l].v, t = q[l].t;
        l++;
        vis[x] = 0;
        for(int i = head[x]; i; i = nxt[i]) {
            int ed = to[i];
            if(f[ed][t + 1] < v + V[ed] - (2 * t + 1) * c) {
                f[ed][t + 1] = v + V[ed] - (2 * t + 1) * c;
                if(!vis[ed]) q[++r] = {ed, f[ed][t + 1], t + 1}, vis[ed] = 1;
            }
        }
    }
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("trade.in", "r", stdin);
    freopen("trade.out", "w", stdout);
    read(n, m, c);
    for(int i = 1; i <= n; i++) read(V[i]);
    for(int i = 1; i <= m; i++) {
        int x, y;
        read(x, y);
        add(x, y);
    }
    SPFA();
    cout << *max_element(f[1], f[1] + 1000 + 1) << "\n";
    return 0;
}
