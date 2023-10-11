#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
struct Point{
    int v;
    long long w;
}
int n,m,u,v;
long long f[N],x,w1,w2;
bool vis[1005];
vector <Point> e[N];
void add(int u,int v,int w){
    e[u].push_back((Point){v,w});
}
void dfs(int u,long long step){
   for(int i = 0;i < e[u].size();i++){
       int v=e[u][i].v;
       long long w=e[u][i].w;
       f[v]=step+w;
       dfs(v,step+w);
   }
}
int main(){
    freopen("double.in","r",stdin);
    freopen("double.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
       cin >> x;
       add(2*i-1,2*i,x);
       add(2*i,2*i-1,x);
    }
    for(int i = 1;i <= m;i++){
        cin >> u >> v >> w1 >> w2;
        add(2*u-1,2*v-1,w1);
        add(2*v-1,2*u-1,w1);
        add(2*u,2*v,w2);
        add(2*v,2*u,w2);
    }
    cin >> q;
    while(q--){
        cin >> u >> v;
        f[u]=0;
        dfs(u,0);
        cout << f[v] << "\n";
    }
    return 0;
}
