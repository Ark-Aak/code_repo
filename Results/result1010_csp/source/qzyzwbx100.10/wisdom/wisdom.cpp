#include<bits/stdc++.h>
using namespace std;
long long n,m,k,h[1000007],l[1000007],p,w,sumh,sum,ans;
int main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=max(m,n);i++){
		h[i]=l[i]=1;
	}
	for(int i=1;i<=k;i++){
		char ch;
		cin>>ch;
		cin>>p>>w;
		if(ch=='C'){
			l[p]=l[p]*w%1000000007;
		}
		else{
			h[p]=h[p]*w%1000000007;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=(sum+((i-1)*m+1)%1000000007*h[i]%1000000007)%1000000007;
		sumh+=h[i];
		sumh%=1000000007;
	}
	for(int i=1;i<=m;i++)
	{
		ans=(ans+sum*l[i]%1000000007)%1000000007;
		sum+=sumh;
		sum%=1000000007;
	}
	cout<<ans<<endl;
	return 0;
}
