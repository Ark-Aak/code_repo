#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,ans;
int head[N],nxt[N<<1],to[N<<1],deg[N],tot;
void add(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
int fa[N],s[N],tp;
bool vis[N];
int find(int x){
	if(fa[x]==x) return x;
	fa[x]=find(fa[x]);
	return fa[x];
}
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);
		add(v,u);
		deg[u]++,deg[v]++;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			int res=0;
			for(int j=1;j<=n;j++) fa[j]=j,vis[j]=0;
			
			for(int j=i;j<=n;j++){
				int cnt=0;
				vis[j]=1;
				tp=0;
				for(int k=head[j];k;k=nxt[k]){
					int v=to[k];
					int f=find(v);
					if(vis[f]) s[++tp]=f;
				}
				if(!tp) res++;
				else{
					res-=(tp-1);
					fa[j]=s[tp];
					for(int k=1;k<tp;k++) fa[s[k]]=s[tp];		
				}
				ans=(ans+res*res)%mod;
			}	
		}
		printf("%lld",ans);	
	}
	else{
		int x;
		for(int i=1;i<=n;i++)
			if(deg[i]>1) x=i; 
		for(int i=1;i<=n;i++){
			if(i>x){
				int len=n-i+1;
				ans=(ans+len*(len+1)%mod*(2*len+1)%mod*ksm(6,mod-2)%mod)%mod;
			}
			else{
				int len=x-i;
				ans=(ans+len*(len+1)%mod*(2*len+1)%mod*ksm(6,mod-2)%mod)%mod;
				ans=(ans+n-x+1)%mod;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}	
// n(n+1)(2n+1)/6
