#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll n,k,a[55][55],b[N],f[N];
bool vis[N];
ll w[N];
struct qwq{
    ll ed,val;
};
vector<qwq> v[N];
priority_queue<pair<ll,ll> >q;
ll ans=INT_MAX;
void dij(){
    for(int i=1;i<=n*3;i++)f[i]=__LONG_LONG_MAX__;
    f[1]=0;
    q.push({0,1});
    while(!q.empty()){
        ll t=q.top().second;
        q.pop();
        if(vis[t])continue;
        vis[t]=1;
        if(t<n){
            for(auto i:v[t]){
                if(f[i.ed]>f[t]){
                    f[i.ed]=f[t];
                    q.push({-f[i.ed],i.ed});
                    w[i.ed]=i.val;
                }
            }
            continue;
        }
        if(t<2*n){
            for(auto i:v[t]){
                if(f[i.ed]>f[t]+abs(w[t]+i.val)){
                    f[i.ed]=f[t]+abs(w[t]+i.val);
                    //cout<<i.ed<<" "<<f[t]+abs(w[t]+i.val)<<"\n";
                    q.push({-f[i.ed],i.ed});
                    w[i.ed]=0;
                }
            }
            continue;
        }
        if(t<3*n){
            for(auto i:v[t]){
                if(f[i.ed]>f[t]){
                    f[i.ed]=f[t];
                    q.push({-f[i.ed],i.ed});
                    w[i.ed]=w[t];
                }
            }
            continue;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n;i++){
        v[i].push_back({b[i]+n+n,i});
        v[b[i]+n].push_back({i,-i});
    }
    for(int i=1;i<=k;i++){
        string s;
        cin>>s;
        s=" "+s;
        for(int j=1;j<=k;j++){
            if(s[j]=='1')v[i+n+n].push_back({j+n,0});
        }
    }
    dij();
    if(f[n]<INT_MAX)cout<<f[n];
    else cout<<-1;
    return 0;
}