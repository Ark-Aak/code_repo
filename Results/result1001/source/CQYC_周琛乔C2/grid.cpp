#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int T,n,m,g[805][805];
long long ans;
inline long long solve(){
	read(n),read(m);
	if(n<m) swap(n,m);
	if(m==1) return 0;
	ans=0;
	if(m==2){
		for(int i=2;i<=n;i++) ans+=1ll*(i+1)*(n-i+1)*n;
		return ans<<1;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	for(int k=1;k<=n;k++)
	for(int l=1;l<=m;l++)
		ans+=g[abs(i-k)][abs(j-l)]*(1ll*n*m-g[abs(i-k)][abs(j-l)]);
	return ans;
}
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	read(T);
	while(T--) printf("%lld\n",solve());
	return 0;
}

