//O(n*(2^n)) 50pts
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,p,mod,o[10005],u[10005],f[22][1050000];
int gt(int l){return 1ll<<(l-1ll);}
int dfs(int t,int c,int lst){
	if(f[lst][c]+1) return f[lst][c];
	//cout<<t<<' ';for(int i=1;i<=n;i++) cout<<!!(c&gt(i));cout<<'\n';
	if(t>n){
		if(o[n]<o[1] && o[n-1]<o[n]){return 1;}
		if(o[n]>o[1] && o[n-1]>o[n]){return 1;}
		return 0;
	}
	int res=0;
	for(int i=1;i<n;i++){
		if(c&gt(i)) continue;
		//for(int j=1;j<t;j++){cout<<o[j]<<' ';}cout<<i<<'\n';
		if(o[t-2]<o[t-1] && o[t-1]<i){res+=u[n-t];continue;}
		if(i<o[t-1] && o[t-1]<o[t-2]){res+=u[n-t];continue;}
		o[t]=i;res+=dfs(t+1,c|gt(i),i);o[t]=0;
	}return f[lst][c]=res;
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n>>mod;u[0]=1;
	for(int i=1;i<=n;i++) u[i]=(u[i-1]*i)%mod;
	if(n%2){cout<<u[n];return 0;}
	o[0]=o[1]=n;
	memset(f,-1,sizeof(f));
	cout<<(dfs(2,gt(n),n)*n)%mod;
	/*for(int i=1;i<=20;i++){
		p=0;n=i;dfs(1);
		cout<<p<<' ';
	}*/
	return 0;
}

