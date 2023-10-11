#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
vector<ll> v[N];
ll n,m;
namespace st1{
    ll f[N][35],dep[N],dfn[N],bel[N],siz[N],son[N],fa[N],top[N],cnt,tot;
    ll id[N],lg[N];
    vector<ll> mp;
    void dfs1(ll x,ll fat,ll d){
        dep[x]=d;
        fa[x]=fat;
        siz[x]=1;
        for(int i=0;i<v[x].size();i++){
            ll y=v[x][i];
            if(y==fat)continue;
            dfs1(y,x,d+1);
            siz[x]+=siz[y];
            if(siz[y]>siz[son[x]])son[x]=y;
        }
    }
    void dfs2(ll x,ll tp){
        top[x]=tp;
        bel[x]=++cnt;
        id[cnt]=x;
        if(!son[x])return ;
        dfs2(son[x],tp);
        for(int i=0;i<v[x].size();i++){
            ll y=v[x][i];
            if(y==fa[x]||y==son[x])continue ;
            dfs2(y,y);
        }
    }
    ll ask(ll l,ll r){
        ll q=lg[r-l+1];
        return min(f[l][q],f[r-(1<<q)+1][q]);
    }
    void st(){
        for(int i=1;i<=cnt;i++)f[i][0]=id[i];
        for(int i=2;i<=cnt;i++)lg[i]=lg[i>>1]+1;
        for(int i=1;i<=lg[cnt];i++){
            for(int j=1;j+(1<<i)-1<=cnt;j++){
                f[j][i]=min(f[j][i-1],f[j+(1<<(i-1))][i-1]);
            }
        }
    }
    ll qr(ll x,ll y){
        ll ans=INT_MAX;
        while(top[x]!=top[y]){
            if(dep[top[x]]<dep[top[y]])swap(x,y);
            ans=min(ans,ask(bel[top[x]],bel[x]));
            x=fa[top[x]];
        }
        if(dep[x]>dep[y])swap(x,y);
        ans=min(ans,ask(bel[x],bel[y]));
        return ans;
    }
    void solve(){
        dfs1(1,0,1);
        dfs2(1,1);
        st();
        string s;
        while(m--){
            cin>>s;
            ll x;
            cin>>x;
            if(s=="JC")mp.push_back(x);
            else{
                ll ans=INT_MAX;
                for(auto t:mp)ans=min(ans,qr(x,t));
                cout<<ans<<endl;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("network.in","r",stdin);
    freopen("network.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    st1::solve();
    return 0;
}