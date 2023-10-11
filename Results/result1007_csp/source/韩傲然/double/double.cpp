#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 4e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int n;
int head[N], to[EG], nxt[EG], val[EG], tot;
void add(int u, int v, int w) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
    val[tot] = w;
}
int dis[2010][2010];
int vis[N];
void dijkstra(int s) {
    priority_queue< pair<int, int> > q;
    for(int i = 1; i <= n * 2; i++) vis[i] = 0, dis[s][i] = INF;
    dis[s][s] = 0;
    q.push({0, s});
    while(!q.empty()) {
        int x = q.top().second; q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x]; i; i = nxt[i]) {
            int ed = to[i], v = val[i];
            if(dis[s][ed] > dis[s][x] + v) {
                dis[s][ed] = dis[s][x] + v;
                q.push({-dis[s][ed], ed});
            }
        }
    }
}
vector<int> q[N];
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("double.in", "r", stdin);
        freopen("double.out", "w", stdout);
    #endif
    read(n);
    for(int i = 1; i <= n; i++) {
        int w;
        read(w); add(2 * i - 1, 2 * i, w); add(2 * i, 2 * i - 1, w);
    }
    for(int i = 1; i <= n - 1; i++) {
        int u, v, w1, w2;
        read(u, v, w1, w2);
        add(2 * u - 1, 2 * v - 1, w1); add(2 * v - 1, 2 * u - 1, w1);
        add(2 * u, 2 * v, w2); add(2 * v, 2 * u, w2);
    }
    int q; read(q);
    for(int i = 1; i <= n * 2; i++) {
        dijkstra(i);
    }
    for(int i = 1; i <= q; i++) {
        int u, v; read(u, v);
        cout << dis[u][v] << "\n";
    }
    return 0;
}