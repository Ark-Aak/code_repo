#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
bitset<N> a[30];
ll n,m,ans=INT_MAX;
void dfs(ll x){
    if(x==n+1){
        ll sum=0;
        for(int i=1;i<=m;i++){
            ll cnt=0;
            for(int j=1;j<=n;j++)if(a[j][i])cnt++;
            if(cnt>n-cnt)sum+=n-cnt;
            else sum+=cnt;
        }
        ans=min(ans,sum);
        return ;
    }
    if(x<=10){
        for(int i=0;i<=1;i++){
            a[x].flip();
            dfs(x+1);
        }
        return ;
    }
    dfs(x+1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        s=" "+s;
        for(int j=1;j<=m;j++)a[i][j]=(s[j]-'0');
    }
    dfs(1);
    cout<<ans;
    return 0;
}