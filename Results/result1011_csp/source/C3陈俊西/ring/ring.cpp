#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=25;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,mod,a[N],b[N],c[N],id[N],ans;
bool vis[N];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++) b[i]=a[i],c[i]=id[i];
		for(int i=1;i<=n;i++){//val	
			int w=c[i];
			int vl,vr,idl,idr;
			
			if(w==1) vl=b[n],idl=n;
			else vl=b[w-1],idl=w-1;
			
			if(w==n) vr=b[1],idr=1;
			else vr=b[w+1],idr=w+1;
		
			if(min(vl,vr)<i&&i<max(vl,vr)){
				ans++;
				return;
			} 
			swap(b[idl],b[idr]);
			swap(c[vl],c[vr]);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			id[i]=x;
			a[x]=i;
			
			dfs(x+1);
			
			vis[i]=0;
			id[i]=0;
			a[x]=0;
		}
	}
	return;
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read(),mod=read();
	if(n&1){
		ans=1;
		for(int i=2;i<=n;i++)
			ans=(ans*i)%mod;
	}
	else dfs(1);
	printf("%lld",ans%mod);
	return 0;
}
