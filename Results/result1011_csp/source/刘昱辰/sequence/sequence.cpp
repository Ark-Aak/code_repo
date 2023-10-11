#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll phi[N],p[N],tot,n,m;
ll f[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
    cin>>n>>m;
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(!phi[i]) p[++tot]=i,phi[i]=i-1; 
        for(int j=1;j<=tot;j++){
            if(i*p[j]>n)break;
            if(i%p[j]==0){
                phi[i*p[j]]=phi[i]*p[j];
                break;
            }else phi[i*p[j]]=phi[i]*(p[j]-1);
        }      
    }
    for(int i=1;i<=n;i++){
    	phi[i]+=n-i;
    	cout<<phi[i]<<" ";
	}
	for(int i=1;i<=m;i++)f[0][i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=f[i-1][j]*phi[j];
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++){
		ans+=f[n][i];
	}
	cout<<ans;
    return 0;
}
