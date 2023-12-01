#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+5,Mx=1e6;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) x = (x<<1)+(x<<3)+(ch^48), ch = getchar();
}
int head[N],to[N<<1],nxt[N<<1],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,q,a[N],u,v;
int f[N],top[N],sz[N],son[N],dep[N],idx,dfn[N],xl[N];
void dfs1(int p,int fa){
	sz[p]=1;
	f[p]=fa;
	dep[p]=dep[fa]+1;
	for(int o=head[p];o;o=nxt[o]){
		if(to[o]==fa) continue;
		dfs1(to[o],p);
		sz[p]+=sz[to[o]];
		if(sz[to[o]]>sz[son[p]]) son[p]=to[o];
	}
}
void dfs2(int p,int topf){
	top[p]=topf;
	dfn[p]=++idx;
	xl[idx]=p;
	if(!son[p]) return;
	dfs2(son[p],topf);
	for(int o=head[p];o;o=nxt[o])
		if(to[o]^f[p]&&to[o]^son[p])
			dfs2(to[o],to[o]);
}
struct MRX{int a[2][2];};
inline MRX mul(MRX x,MRX y){
	MRX ans;
	ans.a[0][0]=x.a[0][0]+y.a[0][0];
	ans.a[0][1]=min(min(x.a[0][0]+y.a[0][1],x.a[0][1]+y.a[1][1]),x.a[0][0]+y.a[1][1]);
	ans.a[1][0]=min(min(x.a[1][0]+y.a[0][0],x.a[1][1]+y.a[1][0]),x.a[1][1]+y.a[0][0]);
	ans.a[1][1]=x.a[1][1]+y.a[1][1];
	return ans;
}
struct Tree{
	MRX t[N*3];
	void build(int p,int l,int r,int v){
		if(l==r){
			bool val=(a[xl[l]]>=v);
			t[p]=(MRX){{{val,Mx},{Mx,!val}}};
			return;
		}
		build(2*p,l,mid,v);
		build(2*p+1,mid+1,r,v);
		t[p]=mul(t[2*p],t[2*p+1]);
	}
	void change(int p,int l,int r,int x,int v){
		if(l==r){
			bool val=(a[xl[l]]>=v);
			t[p]=(MRX){{{val,Mx},{Mx,!val}}};
			return;
		}
		if(x<=mid) change(2*p,l,mid,x,v);
		else change(2*p+1,mid+1,r,x,v);
		t[p]=mul(t[2*p],t[2*p+1]);
	}
	MRX query(int p,int l,int r,int lt,int rt){
		if(lt<=l&&r<=rt) return t[p];
		if(lt<=mid&&mid+1<=rt)
			return mul(query(2*p,l,mid,lt,rt),query(2*p+1,mid+1,r,lt,rt));
		return lt<=mid?query(2*p,l,mid,lt,rt):query(2*p+1,mid+1,r,lt,rt);
	}
}T[11];
MRX ans[2][11];
inline int query_up(int x,int y){
	memset(ans,0,sizeof(ans));
	bool xs=0;
	while(top[x]^top[y]){
		if(dep[top[x]]<dep[top[y]]) swap(x,y),xs^=1;
		for(int i=1;i<=10;++i){
			MRX qq=T[i].query(1,1,n,dfn[top[x]],dfn[x]);
			ans[xs][i]=mul(qq,ans[xs][i]);
		}
		x=f[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y),xs^=1;
	for(int i=1;i<=10;++i)
		ans[!xs][i]=mul(T[i].query(1,1,n,dfn[x],dfn[y]),ans[!xs][i]);
	int sum=0,ans1,ans2;
	for(int i=1;i<=10;++i){
		ans1=min(ans[0][i].a[0][0]+ans[1][i].a[0][0],ans[0][i].a[1][1]+ans[1][i].a[1][1]);
		ans2=min(min(ans[0][i].a[0][0]+ans[1][i].a[0][1],ans[0][i].a[1][0]+ans[1][i].a[1][1]),ans[0][i].a[0][0]+ans[1][i].a[1][1]);
		sum+=min(ans1,ans2);
	}
	return sum;
}
void print(int x){
	if(x>9) print(x/10);
	putchar(48+x%10);
}
int main(){
	read(n);
	for(int i=1;i<=n;++i) read(a[i]);
	for(int i=1;i<n;++i){
		read(u),read(v);
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=10;++i) T[i].build(1,1,n,i);
	read(q);
	while(q--){
		read(u);read(a[u]);
		for(int i=1;i<=10;++i) T[i].change(1,1,n,dfn[u],i);
		read(u),read(v);
		print(query_up(u,v));
		if (q != 0) putchar('\n');
	}
	return 0;
} 