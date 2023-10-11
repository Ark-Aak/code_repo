#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans;
int a[10005],b[10005],c[10005],d[10005];
int r(int x){
	if(x==0) return n;
	if(x==n+1) return 1;
	return x;
}
void dfs(int x){
	if(x>n){
		for(int i=1;i<=n;i++) c[i]=a[i],d[i]=b[i];
		for(int i=1;i<=n;i++){
			if((a[r(b[i]-1)]<i&&i<a[r(b[i]+1)])||(a[r(b[i]-1)]>i&&i>a[r(b[i]+1)])){
				ans++;
				break;
			}
			swap(a[r(b[i]-1)],a[r(b[i]+1)]);
			b[a[r(b[i]-1)]]=r(b[i]-1);
			b[a[r(b[i]+1)]]=r(b[i]+1);
		}
		if(ans>=m) ans-=m;
		for(int i=1;i<=n;i++) a[i]=c[i],b[i]=d[i];
		return;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=x;
			a[x]=i;
			dfs(x+1);
			b[i]=0;
		}
	}
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	if(n<=10){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	if(n&1){
		int res=6;
		for(int i=5;i<=n;i+=2) res=res*i%m*(i-1)%m;
		printf("%lld",res);
		return 0;
	}
	return 0;
}


