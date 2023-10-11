//20
#include<bits/stdc++.h>
using namespace std;
string str;
int N,n,m,res=500000000,c[25],p[25][200005];
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;N=(1<<n);
	for(int i=1;i<=n;i++){
		cin>>str;
		for(int j=1;j<=m;j++)
			p[i][j]=str[j-1]-'0'; 
	}
	for(int o=0;o<N;o++){
		int ans=0;
		for(int i=1;i<=m;i++){
			int cnt=0;
			for(int j=0;j<n;j++)
				cnt+=(p[j+1][i]^(!!(o&(1<<j))));
			ans+=min(n-cnt,cnt);
		}
		res=min(res,ans);
	}cout<<res;
	return 0;
} 
