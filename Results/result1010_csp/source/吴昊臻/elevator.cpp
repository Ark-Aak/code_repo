#include<bits/stdc++.h>
using namespace std;
int n,k,x[500005],w[2000005],zz[500005],mx,tem,lst=1,p,pp,ppp,ww,www;
long long dp[500005];
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x[i],w[x[i]]++,mx=max(x[i],mx);
	zz[0]=0;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		zz[i]=zz[i-1];
		dp[i]=dp[i-1];
		if(x[i]==x[i-1]) continue; 
		if(zz[i-1]*(x[i]-lst)+(x[i]-1)*min(k,w[x[i]]+zz[i-1])<(x[i]-1)*min(k-zz[i-1],w[x[i]])+(x[i]-lst)+2*zz[i-1]*(lst-1)&&(w[x[i]]+zz[i-1]<=k||w[x[i]]>k))
			if(w[x[i]]>k)
				dp[i]=dp[i-1]+(n-i+1+zz[i-1]-ww)*(x[i]-lst),www=k-zz[i],w[x[i]]-=k-zz[i],zz[i]=k,p++,cout<<1<<" "<<dp[i]<<'\n';
			else
				dp[i]=dp[i-1]+(n-i+1+zz[i-1])*(x[i]-lst),zz[i]+=w[x[i]],cout<<2<<" "<<dp[i]<<'\n';
			else
				dp[i]=dp[i-1]+(n-i+1+zz[i-1])*(lst-1)+(n-i+1)*(x[i]-1),zz[i]=w[x[i]],pp++,cout<<3<<" "<<dp[i]<<'\n';
		if(zz[i]==k)
				dp[i]+=(x[i]-1)*k+2*(x[i]-1)*(n-i),zz[i]=0,ppp++,cout<<4<<" "<<dp[i]<<'\n';
		if(p==1) i--,p--,ww+=www;
		else ww=0; 
		lst=x[i];
	}
	dp[n]+=zz[n]*(lst-1);
	cout<<dp[n];
}	
/*
3 1
10 5 2

*/
