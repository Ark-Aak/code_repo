#include <bits/stdc++.h>
using namespace std;
struct Point{
    int v,id;
}
const int N=1e3+5;
int n,m,u,v,l,r,s,t,q;
bool vis[N][N],bj;
void dfs(int u,int mb,int step){
   if(!vis[u][mb])continue;
   if(bj)return;
   if(u==mb){
       bj=true;
       return;
   }
   for(int i = 0;i < e[u].size();i++){
       int v=e[u][i].v,w=e[u][i].id;
       if(step>w)continue;
       dfs(v,mb,step+1);
   } 
}
int main(){
    freopen("journey.in","r",stdin);
    freopen("journey.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >>  m >> q;
    for(int i = 1;i <= m;i++){
        cin >> u >> v;
        e[u].push_back((Point){v,i});
        e[v].push_back((Point){u,i});
        vis[u][v]=vis[v][u]=1;
    }
    for(int k = 1;k <= n;k++)
    	for(int i = 1;i <= n;i++)
    		for(int j = 1;j <= n;j++)
                   if(vis[i][k]&&vis[k][j])
                   	vis[i][j]=true;
    while(q--){
        cin >> l >> r >> s >> t;
        bj=false;
        dfs(s,t,l);
        if(bj)cout << "Yes\n";
        else cout << "No\n";
    }       
    return 0;
}
