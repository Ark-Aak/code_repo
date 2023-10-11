#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
int head[2000005],to[2000005],nxt[2000005],tot;
int id[1000005],wt[1000005],siz[1000005],top[1000005],f[1000005],son[1000005],cnt,dep[1000005];
int a[4000005],minn;
int n,q;
namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;
void add(int x,int y) {
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void dfs1(int x,int fa) {
	siz[x]=1;
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=nxt[i]) {
		if(to[i]==fa) continue;
		dfs1(to[i],x);
		siz[x]+=siz[to[i]];
		if(siz[son[x]]<siz[to[i]]) son[x]=to[i];
	}
}
void dfs2(int x,int topf) {
	id[x]=++cnt;
	wt[id[x]]=x;
	top[x]=topf;
	if(son[x]) dfs2(son[x],topf);
	for(int i=head[x];i;i=nxt[i]) {
		if(to[i]==f[x] || to[i]==son[x]) continue;
		dfs2(to[i],to[i]); 
	}
}
void build(int x,int l,int r) {
	if(l==r) {
		a[x]=wt[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	a[x]=min(a[ls],a[rs]);
}
void query(int x,int l,int r,int L,int R) {
	if(r<l) return ;
	if(L<=l && r<=R) {
		minn=min(minn,a[x]);
		return ;
	}
	if(L<=mid) query(ls,l,mid,L,R);
	if(mid<R) query(rs,mid+1,r,L,R);
	a[x]=min(a[ls],a[rs]);
}
int solve(int x,int y) {
	int res=1e9;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		minn=1e9;
		query(1,1,n,id[top[x]],id[x]);
		res=min(res,minn);
		x=f[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	minn=1e9;
	query(1,1,n,id[x],id[y]);
	return min(minn,res);
}
int lca(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return x;
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=in,q=in;
	for(int i=1;i<n;i++) {
		int x,y;
		x=in,y=in;
		add(x,y),add(y,x);
	} 
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	int rt=0,ans=1e9;
	while(q--) {
		int x;
		string s;
		cin>>s;
		x=in;
		if(s[0]=='J') {
			if(!rt) rt=x;
			rt=lca(rt,x);
			ans=min(ans,solve(rt,x));
		} else {
			out(min(ans,solve(lca(x,rt),x)),'\n');
		} 
	}
	return 0;
}
