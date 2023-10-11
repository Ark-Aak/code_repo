#include<bits/stdc++.h>
using namespace std;
const int N=1.2e5+5;
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
int T,n,m,s[N],t[N];
int id[N];
bool h[N];
inline bool cmp(int x,int y){return s[x]==s[y]?t[x]<t[y]:s[x]<s[y];}
inline void sub_link(){
	for(int i=1;i<=m;i++){
		id[i]=i;
		h[i]=0;
		if(s[i]>t[i]) swap(s[i],t[i]),h[i]=1;
	}
	sort(id+1,id+m+1,cmp);
	int mx=0;
	for(int i=1;i<=m;i++){
		if(t[id[i]]<=mx||(h[id[i]]&&s[id[i]]<=mx)){
			puts("No");
			return;
		}
		mx=max(mx,t[id[i]]);
	}
	puts("Yes");
}
int fa[N][20],lg[N],dep[N],dfn[N],sons[N],idx;
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	fa[p][0]=f;
	dfn[p]=++idx;
	sons[p]=1;
	for(int i=1;i<=lg[dep[p]];i++)
		fa[p][i]=fa[fa[p][i-1]][i-1];
	for(int o=head[p];o;o=nxt[o])
		if(to[o]^f){
			dfs(to[o],p);
			sons[p]+=sons[to[o]];
		}
}
inline int Lca(int x,int y){
	if(dep[x]>dep[y]) swap(x,y);
	int ch=dep[y]-dep[x];
	for(int i=lg[ch];~i;i--)
		if((ch>>i)&1) y=fa[y][i];
	if(x==y) return x;
	for(int i=19;~i;i--)
		if(fa[x][i]^fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
inline bool Son(int x,int fa){return dfn[fa]<=dfn[x]&&dfn[x]<=dfn[fa]+sons[fa]-1;}
inline bool road(int x,int s,int t,int lca){return Son(x,lca)&&(Son(s,x)||Son(t,x));}
inline void sub_55(int kk){
	dfs(1,0);
	for(int i=1,lca;i<=m;i++){
		lca=Lca(s[i],t[i]);
		for(int j=1;j<=m;j++){
			if(i==j) continue;
			if(road(s[j],s[i],t[i],lca)&&road(t[j],s[i],t[i],lca)){
				puts("No");
				return;
			}
			if(Son(t[i],s[i])||Son(s[i],t[i])){
				int mxd=dep[s[i]]>dep[t[i]]?s[i]:t[i];
				if(road(s[j],s[i],t[i],lca)&&Son(s[j],mxd)){
					puts("No");
					return;
				}
			}else if(
			(road(s[j],s[i],t[i],lca)&&Son(t[j],s[i]))||
			(road(t[j],s[i],t[i],lca)&&Son(s[j],t[i]))){
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
bool link;
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	read(T);
	for(int i=1;i<N;i++) lg[i]=lg[i>>1]+1;
	for(int k=1;k<=T;k++){
		read(n);
		for(int i=1;i<=n;i++) head[i]=0;
		tot=idx=0;
		link=1;
		for(int i=1,u,v;i<n;i++){
			read(u),read(v);
			link&=(abs(u-v)==1);
			add(u,v);
			add(v,u);
		}
		read(m);
		for(int i=1;i<=m;i++)
			read(s[i]),read(t[i]);	
		if(link) sub_link();
		else sub_55(k);
	}
	return 0;
}

