#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,m,f[N],g[N],ma[N],ans[N];
struct qwq{
    ll ed,val;
};
vector<qwq> v[N];
void dfs(ll x,ll val,ll t){
    for(auto y:v[x]){
        if(y.val>val){
            dfs(y.ed,y.val,t+1);
            f[x]=max(g[y.ed]+1,f[x]);
            g[x]=min(f[y.ed]+1,max(g[x],1ll));
        } 
        if(x==0){
            ans[y.ed]=max(f[y.ed],ans[y.ed]);
            f[y.ed]=0;
            g[y.ed]=INT_MAX;
        }
    }
    if(f[x]==0&&g[x]>=INT_MAX)f[x]=g[x]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("increase.in","r",stdin);
    freopen("increase.out","w",stdout);
    cin>>n>>m;
    while(m--){
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    for(int i=1;i<=n;i++)v[0].push_back({i,0});
    memset(g,0x3f,sizeof(g));
    dfs(0,INT_MIN,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
    return 0;
}