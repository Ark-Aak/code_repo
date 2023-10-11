#include<bits/stdc++.h>
#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int N=1e6+5,BN=4e3+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,Q;
int head[BN],nxt[BN<<1],to[BN<<1],ans[BN],tot;
bool jc[BN];
void add(int u,int v){to[++tot]=v,nxt[tot]=head[u],head[u]=tot;}
void dfs(int u,int f,int minn){
	minn=min(minn,u);
	ans[u]=min(ans[u],minn);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u,minn);
	}
	return;
}
int f[N][2],s[N],id[N],tr[N*6],tp;
void deal(int u,int fa){
	s[++tp]=u;
	id[u]=tp;
	int v1=f[u][0],v2=f[u][1];
	if(v1!=fa&&v1) deal(v1,u); 
	if(v2!=fa&&v2) deal(v2,u); 
	return;
}
void build(int x,int l,int r){
	if(l==r){
		tr[x]=s[l];
		return;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	tr[x]=min(tr[ls],tr[rs]);
	return;
}
int query(int x,int l,int r,int L,int R){
	if(l>=L&&r<=R) return tr[x];
	if(r<L||l>R) return 1e6;
	return min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
}
signed main(){
//	fc C:\Users\HP\Desktop\T\network2.out C:\Users\HP\Desktop\T\network2.ans
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read(),Q=read();
	if(n<=4000&&Q<=4000){
		memset(ans,1e6,sizeof ans);
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			add(u,v);
			add(v,u);
		}	
		while(Q--){
			string opt;
			cin>>opt;
			int x=read();
			if(opt=="JC"){
				if(jc[x]) continue;
				jc[x]=1;
				dfs(x,x,x);
			}
			else printf("%lld\n",ans[x]);
		}
	}
	else{
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			if(!f[u][0]) f[u][0]=v;
			else f[u][1]=v;
			if(!f[v][0]) f[v][0]=u;
			else f[v][1]=u;
		}
		int d;
		for(int i=1;i<=n;i++){
			if(!f[i][1]){
				d=i;
				break;
			}
		}
		deal(d,0);
		build(1,1,n);
		int l=1e6,r=0;
		while(Q--){
			string opt;
			cin>>opt;
			int x=read();
			if(opt=="JC"){
				if(jc[x]) continue;
				jc[x]=1;
				l=min(l,id[x]);
				r=max(r,id[x]);
			}
			else printf("%lld\n",query(1,1,n,min(l,id[x]),max(r,id[x])));			
		}
	}
	return 0; 
}
