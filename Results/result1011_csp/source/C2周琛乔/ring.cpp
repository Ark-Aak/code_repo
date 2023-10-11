#include<bits/stdc++.h>
using namespace std;
const int N=1145;
inline void read(int &x){
	int f=1;x=0;char c=getchar();
	while(!isdigit(c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,M,v[N],vis[N],tmp[N];
long long ans;
void dfs(int x){
	if(x==n+1){
		bool ok=0;
		for(int i=1;i<=n;i++) tmp[i]=vis[i];
		for(int i=1,j,a,b;i<=n&&!ok;i++){
			j=vis[i];
			a=(j>1?(j-1):n);
			b=(j<n?(j+1):1);
			if(min(v[a],v[b])<i&&max(v[a],v[b])>i) ok=1;
			vis[v[a]]=b;
			vis[v[b]]=a;
			swap(v[a],v[b]);
		}
		ans+=ok;
		for(int i=1;i<=n;i++) vis[i]=tmp[i],v[tmp[i]]=i;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=x;
			v[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	read(n),read(M);
	if(n&1){
		ans=1;
		for(int i=2;i<=n;i++) ans=ans*i%M;
		printf("%lld",ans);
		return 0;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}

