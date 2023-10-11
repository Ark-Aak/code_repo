#include<bits/stdc++.h>
#define mid ((l+r)>>1)
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1e6+5;
int top[N],id[N],siz[N],son[N],fa[N],dep[N],cnt,vis[N],book[N],val[N];
vector<int> V[N];
int n,q;
void dfs1(int x,int f){
	dep[x]=dep[f]+1;
	siz[x]=1;
	fa[x]=f;
	int fat=-1;
	for(int i=0;i<(int)V[x].size();i++){
		int v=V[x][i];
		if(v==f) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>fat) fat=siz[v],son[x]=v;
	}
}
void dfs2(int x,int f,int tp){
	top[x]=tp;id[x]=++cnt;
	val[cnt]=x;
	if(!son[x]) return;
	dfs2(son[x],x,tp);
	for(int i=0;i<(int)V[x].size();i++){
		int v=V[x][i];
		if(v==f || v==son[x]) continue;
		dfs2(v,x,v);
	}
}
int a[N*4];
void pushup(int x){
	a[x]=min(a[x<<1],a[x<<1|1]);
}
void build(int x,int l,int r){
	if(l==r){
		a[x]=val[l];
		return;
	}
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
//	cout << "#" << l << " " << "#" << r << "\n"; 
	pushup(x);
}
int query(int x,int l,int r,int lt,int rt){
	if(l>=lt && r<=rt){
		return a[x];
	}
	int res=1e9;
	if(lt<=mid) res=min(res,query(x<<1,l,mid,lt,rt));
	if(rt> mid) res=min(res,query(x<<1|1,mid+1,r,lt,rt));
	return res;
}
int answer(int u,int v){
	int ans=1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans=min(ans,query(1,1,n,id[top[u]],id[u]));
		u=fa[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	ans=min(ans,query(1,1,n,id[u],id[v]));
	return ans;
}

string s;
int idx,nxt[N],nxt2[N],tot2,tot;
void change(int x){
	if(!vis[top[x]]) nxt[++tot]=top[x];
	if( dep[vis[top[x]]] < dep[x]) vis[top[x]]=x;
	if(!book[top[x]]){
		nxt2[++tot2]=top[x];
		book[top[x]] = x;
	}else{
		if( dep[book[top[x]]] > dep[x]) book[top[x]]=x;
	}
	
}int ans=1e9;
signed main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();q=read();
	for(int i=1,u,v;i<n;i++){
		u=read();v=read();
		V[u].push_back(v);
		V[v].push_back(u);
	}
	dfs1(1,1);
	dfs2(1,1,1);
	build(1,1,n);
	while(q--){
		cin >> s;idx=read();
		if(s[0]=='J'){
			change(idx);
		}else{
			ans=1e9;
			for(int i=1;i<=tot;i++) ans=min(ans,answer(idx,vis[nxt[i]]));
			for(int i=1;i<=tot2;i++) ans=min(ans,answer(idx,book[nxt2[i]]));
			
			printf("%d\n",ans);
		}
	}
	return 0;
}
/*
5 9
1 3
5 3
2 4
4 3
JC 4
Query 5
Query 4
JC 2
Query 5
JC 1
Query 5
Query 1
Query 4
*/

