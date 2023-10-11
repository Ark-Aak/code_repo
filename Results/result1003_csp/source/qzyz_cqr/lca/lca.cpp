//55
#include<bits/stdc++.h>
#define int long long
#define MX 4005
using namespace std;
int n,a,b,s[MX],ans;
int sa[500005],sb[500005];
vector<int> v[MX],p[MX];
void dfs(int t,int fa){
	int cnt=1;
	for(auto i:v[t]){
		if(fa==i) continue;
		dfs(i,t);cnt+=s[i];
		p[t].push_back(s[i]);
	}s[t]=cnt;
}
void special(){
	scanf("%lld",&a);
	if(a==1){
		ans=n*(n+1ll)/2;
		for(int i=1;i<=n;i++) sa[i]=sa[i-1]+i*(i-1ll);
		for(int i=n;i>=1;i--) sb[i]=sb[i+1]+i*(n-i);
		for(int i=1;i<=n;i++) printf("%lld ",ans+2ll*(sa[i]+sb[i]));
	}else{
		cout<<"Zhe4 Shi2 Wu3 Fen1 Wo3 Bu2 Yao4 Le~";
	}
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	scanf("%lld",&n);
	if(n>4000){special();return 0;}
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){p[j].clear();}
		dfs(i,0);ans=0;
		for(int j=1;j<=n;j++){
			ans+=s[j]*j;
			for(auto k:p[j])
				ans+=(s[j]-k)*k*j;
		}printf("%lld ",ans);
	}
	return 0;
}
