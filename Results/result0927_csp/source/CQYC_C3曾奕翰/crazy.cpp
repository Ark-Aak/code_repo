#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[10005];
int maxx,tot,ans,answer=1e9;
int p[10005];
//char s[1000005];
//int l0,r0,l1,r1;
void solve1(){
	ans=0;
	for(int i=1;i<=tot;i+=2){
		if(p[tot]==1) ans+=2;
		else if(p[tot]&1) ans+=3;
		else ans+=2;
		
	}
	answer=min(ans,answer);
}
void solve2(){
	ans=0;
	for(int i=1;i<=tot;i+=4){
		if(a[tot+1]%2==0) ans+=2;
		else ans+=3;
	}
	ans+=(tot+1)/2;
	answer=min(ans,answer);
}
signed main(){
	freopen("crazy.in","r",stdin);
	freopen("crazy.out","w",stdout);
	int T=1;
	//scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			maxx=max(maxx,a[i]);
		}
		sort(a+1,a+n+1);
		p[1]=a[1];
		tot=1;
		for(int i=2;i<=n;i++){
			if(a[i]!=a[i-1]+1){
				p[tot]=a[i-1]-p[tot]+1;
				p[++tot]=a[i]-a[i-1]-1;
				p[++tot]=a[i];
			}
		}
		p[tot]=a[n]-p[tot]+1;
		solve1();
		solve2();
		cout<<answer;
		//dfs(,0,1,tot);
	}
	return 0;
}
