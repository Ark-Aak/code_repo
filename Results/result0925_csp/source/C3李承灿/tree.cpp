#include<bits/stdc++.h>
#define int long long
#define N 10005
#define mod 1000000007
using namespace std;
int n,k;
int tot,head[N],nxt[N],to[N];
int f[N],h[N],ans;
inline void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
inline int Find(int x){
	return x==f[x]?x:f[x]=Find(f[x]);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1,a,b;i<n;i++){
		scanf("%lld %lld",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) f[j]=j,h[j]=0;
		int s=0;
		for(int j=i;j<=n;j++){
			s++;
			h[j]=1;
			for(int o=head[j];o;o=nxt[o]){
				if(h[to[o]]==1&&f[Find(to[o])]!=Find(j)){
					f[Find(to[o])]=Find(j);
					s--;
				}
			}
			if(k==1) ans=(ans+s)%mod;
			else ans=(ans+s*s)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}


