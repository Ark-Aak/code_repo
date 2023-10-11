#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 5e4 + 10, C = 51, inf = 0x3f3f3f3f;
#define SEG (int)(N << 2)
#define EG (int)(1.5e7 + 10)

void read(){};
template<class T1,class ...T2>
inline void read(T1& ret,T2&... rest){
    ret=0;char c=getchar();bool f=false;
    while(c<'0'||c>'9'){f=c=='-';c=getchar();}
    while(c>='0'&&c<='9'){ret=ret*10+c-'0';c=getchar();}
    if(f)ret=-ret;
    read(rest...);
}
int n, K;
int b[N], s[C][C];
vector<int> bel[N];
int mn[N], mx[N];
int head[N + 2 * C], to[EG], nxt[EG], val[EG], tot;
void add(int u, int v, int w) {
    nxt[++tot] = head[u];
    head[u] = tot;
    val[tot] = w;
    to[tot] = v;
}
int vis[N + 2 * C], dis[N + 2 * C];
priority_queue< pair<int, int> > q;
void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    q.push({0, 1});
    dis[1] = 0;
    while(q.size()) {
        int x = q.top().second; q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(int i = head[x]; i; i = nxt[i]) {
            int ed = to[i], v = val[i];
            if(dis[ed] > dis[x] + v) {
                dis[ed] = dis[x] + v;
                q.push({-dis[ed], ed});
            }
        }
    }
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
         freopen("tower.in", "r", stdin);
         freopen("tower.out", "w", stdout);
    #endif
    cin >> n >> K;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        bel[b[i]].emplace_back(i);
        if(mn[b[i]] == 0) mn[b[i]] = i;
        mx[b[i]] = i;
    }
    for(int i = 1; i <= K; i++) {
        for(auto j : bel[i]) {
            add(n + i, j, mx[i] - j);
            add(n + K + i, j, j - mn[i]);
        }
    }
    //cerr << clock() << endl;
    for(int i = 1; i <= K; i++) for(int j = 1; j <= K; j++) {
        char c; cin >> c;
        if(c == '1') {
            s[i][j] = 1;
            for(auto u : bel[i]) {
                if(u < mn[j]) add(u, n + K + j, mn[j] - u);
                else if(u > mx[j]) add(u, n + j, u - mx[j]);
                else {
                    for(auto v : bel[j]) add(u, v, abs(u - v));
                }
            }
        }
    }
    //cerr << clock() << endl;
    dijkstra();
    //for(int i = 1; i <= n; i++) cout << dis[i]
    cout << (dis[n] < inf ? dis[n] : -1) << "\n";
    //cerr << clock() << "\n";
    return 0;
}