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
void dfs(ll x,ll val,ll t,ll root){
    for(auto y:v[x]){
        if(y.val>val){
            
        } 
    }
}
bool cmp(qwq a,qwq b){
    return a.val<b.val;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    cin>>n>>m;
    while(m--){
        ll x,y,z;
        cin>>x>>y>>z;
        v[x].push_back({y,z});
        v[y].push_back({x,z});
    }
    for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end(),cmp); 
    for(int i=1;i<=n;i++)dfs(i,INT_MIN,1,i);
    for(int i=1;i<=n;i++)cout<<f[i]<<" ";
    return 0;
}