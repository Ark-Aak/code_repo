#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll t,mxa,mxb,a[N],b[N],ans[N][N];
ll fp(ll x,ll y){
    ll ans=1;
    while(y){
        if(y&1)ans=ans%mod*x%mod;
        y>>=1;
        x=x%mod*x%mod;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>b[i];
        mxa=max(mxa,a[i]);
        mxb=max(mxb,b[i]);
    }
    for(int i=1;i<=mxa;i++){
        for(int j=1;j<=mxb;j++){
            ans[i][j]=ans[i-1][j]%mod+ans[i][j-1]%mod-ans[i-1][j-1]%mod+(((i+j)*fp(__gcd(i,j),mod-2))-2)%mod;
        }
    }
    for(int i=1;i<=t;i++){
        cout<<ans[a[i]][b[i]]<<endl;
    }
    return 0;
}