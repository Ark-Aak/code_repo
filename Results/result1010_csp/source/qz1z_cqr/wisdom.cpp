//100
#include<bits/stdc++.h>
#define int long long
#define MX 1000005
using namespace std;
int n,m,k,a,b,res,w[MX],h[MX],mod=1000000007ll;string op;
int gmod(int pp){return pp%mod;}
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) h[i]=1;
	for(int i=1;i<=m;i++) w[i]=1;
	for(int i=1;i<=k;i++){
		cin>>op>>a>>b;
		if(op[0]=='R')
			h[a]=gmod(h[a]*b);
		else
			w[a]=gmod(w[a]*b);
	}a=b=0;
	for(int i=1;i<=m;i++){
		a=gmod(a+w[i]);
		b=gmod(b+w[i]*i);
		//cout<<w[i]<<' ';
	}a=gmod(a*m);
	//cout<<'\n'<<a<<' '<<b<<'\n';
	for(int i=1;i<=n;i++){
		res=gmod(res+gmod(b+a*(i-1ll))*h[i]);
		//cout<<h[i]<<' ';
	}//cout<<'\n';
	cout<<res;
	return 0;
} 
