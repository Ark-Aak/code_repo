#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1005,Maxm=2e5+5;
int n,m,q;
int head[Maxn],to[Maxm<<1],nxt[Maxm<<1],ti[Maxm<<1],cnt1;
inline void add(int u,int v,int i){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	ti[cnt1]=i;
	head[u]=cnt1;
}
int vis[Maxn],f[Maxn];
int e[Maxn][Maxn];
struct Node{
	int u,data;
	bool operator<(const Node&a)const{
		return a.data<data;
	}
};
priority_queue<Node>heap;
inline void solve30(){
	for(int k=1;k<=q;k++){
		int l=read(),r=read(),s=read(),t=read();
		heap.push({s,l});
		if(l==r){
			if(e[s][t]==l)printf("Yes\n");
			else printf("No\n");
			continue;
		}
		for(int i=1;i<=n;i++)f[i]=m+1;
		f[s]=l;
		while(heap.size()){
			Node tmp=heap.top();
			heap.pop();
			int u=tmp.u;
			if(vis[u]==k)continue;
			vis[u]=k;
			for(int i=head[u];i;i=nxt[i]){
				int y=to[i];
				if(f[u]>ti[i]||ti[i]>r)continue;
				if(f[y]>ti[i]){
					f[y]=ti[i];
					heap.push({y,f[y]});
				}
			}
		}
		if(f[t]<=r)printf("Yes\n");
		else printf("No\n");
	}
}
int F[Maxn][Maxn];
inline void solve11(){
	for(int s=1;s<=n;s++){
		for(int i=1;i<=n;i++)f[i]=m+1;
		f[s]=1;int r=m;
		heap.push({s,1});
		while(heap.size()){
			Node tmp=heap.top();
			heap.pop();
			int u=tmp.u;
			if(vis[u]==s)continue;
			vis[u]=s;
			for(int i=head[u];i;i=nxt[i]){
				int y=to[i];
				if(f[u]>ti[i]||ti[i]>r)continue;
				if(f[y]>ti[i]){
					f[y]=ti[i];
					heap.push({y,f[y]});
				}
			}
		}
		for(int i=1;i<=n;i++)F[s][i]=f[i];
	}
	while(q--){
		int l=read(),r=read(),s=read(),t=read();
		if(F[s][t]<=r)printf("Yes\n");
		else printf("No\n");
	}
}
int main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	n=read();m=read();q=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v,i);add(v,u,i);
		e[u][v]=e[v][u]=i;
	}
	if(m<=1005&&q<=1005||n<=50)solve30();
	else solve11();
	return 0;
}

