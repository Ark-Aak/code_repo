#include<bits/stdc++.h>
#define ll long long
#define N 1005
using namespace std;
const ll mod=1e9+7;
ll n,m,c,a[N],f[N][N],ti[N],ans;
vector<ll>v[N];
void dfs(ll x,ll fa,ll t){
    f[x][t]=f[fa][t-1]+a[x];
    if(f[x][t]-c*t*t<0)return ;
    if(x==1)ans=max(ans,f[x][t]-c*t*t);
    for(int i=0;i<v[x].size();i++)dfs(v[x][i],x,t+1);
    return ;
}
int main(){
    freopen("trade.in","r",stdin);
    freopen("trade.out","w",stdout);
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++)cin>>a[i];
    while(m--){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}