#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
vector<int>to[200005];
vector<int>b[200005],c[200005];
long double f[200005],eps=1e-10;
bool check(double x){
	for(int i=2;i<=n;i++)f[i]=-1e18;
	for(int i=1;i<=n;i++){
		for(int j=0;j<to[i].size();j++){
			f[i]=max(f[i],f[to[i][j]]+b[i][j]*1.00-x*c[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) cout << f[i] << " ";
	cout << endl << endl;
	return f[n]>=0;
}
signed main(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,B,C;
		scanf("%lld %lld %lld %lld",&u,&v,&B,&C);
		to[v].push_back(u);
		b[v].push_back(B);
		c[v].push_back(C);
	}
	long double l=0,r=2e9;
	while(l+eps<r){
		long double mid=(l+r)*0.5;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-eps;	
		}
	}
	printf("%.9Lf",l);
	return 0;
}
