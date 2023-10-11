#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e5+5;
int n,q;
int head[Maxn],to[Maxn<<1],nxt[Maxn<<1],val[Maxn],cnt1;// jiu4 yao4 yi4 dian3 fen1 kan1 xiao3 yi4 dian3
inline void add(int u,int v,int w){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	val[cnt1]=w;
	head[u]=cnt1;
}
struct Node{
	int u,data;
	bool operator<(const Node&a)const{
		return a.data<data;
	}
};
priority_queue<Node>heap;
int f[Maxn];
int vis[Maxn];
signed main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int w=read();
		add(2*i-1,2*i,w);add(2*i,2*i-1,w);
	}
	for(int i=1;i<n;i++){
		int x=read(),y=read(),w1=read(),w2=read();
		//add(x,y,0);
		add(2*x-1,2*y-1,w1);add(2*x,2*y,w2);
		swap(x,y);
		add(2*x-1,2*y-1,w1);add(2*x,2*y,w2);
	}
	q=read();n<<=1;
	for(int k=1;k<=q;k++){
		int u=read(),v=read();
		for(int i=1;i<=n;i++)f[i]=1e18;
		f[u]=0;
		heap.push({u,0});
		while(heap.size()){
			Node tmp=heap.top();
			heap.pop();
			int x=tmp.u;
			if(vis[x]==k)continue;
			vis[x]=k;
			for(int i=head[x];i;i=nxt[i]){
				int y=to[i];
				if(f[y]>val[i]+f[x]){
					f[y]=val[i]+f[x];
					heap.push({y,f[y]});
				}
			}
		}
		printf("%lld\n",f[v]);
	}
	return 0;
}

