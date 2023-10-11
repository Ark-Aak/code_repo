#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int head[N],to[N<<1],nxt[N<<1],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n;
long long ans[N],sz[N];
void dfs1(int p,int fa){
	sz[p]=1;
	for(int o=head[p],v;o;o=nxt[o]){
		v=to[o];
		if(v^fa){
			dfs1(v,p);
			ans[1]+=sz[p]*sz[v]*p;
			sz[p]+=sz[v];
		}
	}
}
void dfs2(int p,int fa){
	if(p!=1){
		ans[p]=ans[fa]+1ll*(n-sz[p])*sz[p]*p-1ll*(n-sz[p])*sz[p]*fa;
	}
	for(int o=head[p];o;o=nxt[o])
		if(to[o]^fa) dfs2(to[o],p);
}
void print(long long x){
	if(x>9) print(x/10);
	putchar(48+x%10);
}
int main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	read(n);
	for(int i=1,u,v;i<n;i++){
		read(u),read(v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++,putchar(' '))
		print(ans[i]*2+1ll*(1+n)*n/2);
	return 0;
}

