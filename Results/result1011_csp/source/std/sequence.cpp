#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
int n,m;
int f[22][N],g[22];
int dp[N];

int ID(int x){
    return (x & 1ll)?mod-1:1;
}

int main(){
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) f[1][i]=1;
    for(int t=2;t<=20;t++){
        for(int i=1;i<=m;i++){
            for(int j=i*2;j<=m;j+=i){
                f[t][j]=(f[t][j]+f[t-1][i])%mod;
            }
        }
    }
    for(int t=1;t<=20;t++){
        for(int i=1;i<=m;i++) g[t]=(g[t]+f[t][i])%mod;
    }
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=i-1;j>=i-20 && j>=0;j--){
            dp[i]=(dp[i]+mod-1ll*dp[j]*g[i-j]%mod)%mod;
        }
    }
    cout<<1ll*ID(n)*dp[n]%mod;
}