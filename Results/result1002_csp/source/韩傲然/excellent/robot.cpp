#include<bits/stdc++.h>
#define int long long 
#define LL long long
#define ull unsigned long long
using namespace std;
const int N = 1e5 + 10, inf = 0x3f3f3f3f, INF = 0x3f3f3f3f3f3f3f3f;
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
int T, n, m;
int head[N], to[EG], nxt[EG], tot;
struct ROBOT {
    int p, q;
    bool operator < (const ROBOT &A) const {
        if(p != A.p) return p < A.p;
    }
}robot[N];
void add(int u, int v) {
    nxt[++tot] = head[u];
    head[u] = tot;
    to[tot] = v;
}      
void solve5() {
    bool ans = 1;
    sort(robot + 1, robot + m + 1);
    int mx = -1;
    for(int i = 1; i <= m; i++) {
        if(mx >= robot[i].q) {ans = 0; break;}
        mx = max(mx, robot[i].q);
    }
    cout << (ans ? "Yes\n" : "No\n");
}
signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);
    freopen("robot.in", "r", stdin);
    freopen("robot.out", "w", stdout);
    read(T);
    while(T--) {
        memset(head, 0, sizeof(head)); memset(to, 0, sizeof(to)); memset(nxt, 0, sizeof(nxt));
        read(n);
        for(int i = 1; i < n; i++) {
            int u, v; read(u, v);
            add(u, v); add(v, u);
        }
        read(m);
        for(int i = 1; i <= m; i++) read(robot[i].p, robot[i].q);
        solve5();
        
    }
    return 0;
}
