#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,m;
int res[5005];
vector<int>w;
int g[5005][5005];
int f[5005][5005];
int sum[5005];
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		res[x]++;
	}
	for(int i=1;i<=n;i++)
		if(res[i])w.push_back(i);
	sum[0]=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
//		cout<<i<<endl;
		for(int j=0;j<w.size();j++){
//			cout<<"j"<<endl;
			if(i-w[j]>=1){
//				cout<<sum[i-1]-sum[i-w[j]-1]<<"*"<<res[w[j]]<<"-"<<(g[j][i-1]-g[j][i-w[j]-1])<<endl;
				f[i][j]=(((sum[i-1]-sum[i-w[j]-1])*res[w[j]]%mod)-(g[j][i-1]-g[j][i-w[j]-1]+mod)%mod+mod)%mod;
				g[j][i]=(g[j][i-1]+f[i][j])%mod;
				sum[i]=(sum[i]+f[i][j])%mod;
			}else{
//				cout<<sum[i-1]<<"*"<<res[w[j]]<<"-"<<g[j][i-1]<<endl;
				f[i][j]=((sum[i-1]*res[w[j]]%mod)-g[j][i-1]%mod+mod)%mod;
				g[j][i]=(g[j][i-1]+f[i][j])%mod;
				sum[i]=(sum[i]+f[i][j])%mod;
			}
		}
//		cout<<sum[i]<<endl;
	}
	cout<<sum[n]-sum[n-1];
	return 0;
}/*
20 30
12 3 11 8 2 1 10 4 3 3 7 19 18 18 5 10 4 3 9 15 9 15 13 9 10 4 20 3 17 6 
*/
