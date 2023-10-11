#include<bits/stdc++.h>
#define ll long long
#define N 5005
#define endl "\n" 
using namespace std;
const ll mod=998244353;
ll f[N][N],n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("random.in","r",stdin);
    freopen("random.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]=='1')f[i][j+1]=1;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(!f[i][j]&&!f[j][i])continue;
            for(int k=j+1;k<=n;k++){
                if(f[i][j]&&f[j][k]&&f[k][i])ans++;
                if(f[i][k]&&f[k][j]&&f[j][i])ans++;
                ans%=mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
