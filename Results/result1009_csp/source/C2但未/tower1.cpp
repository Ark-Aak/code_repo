#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=5e4+55+5;
int n,k;
int b[Maxn];
int head[Maxn],nxt[Maxn<<2],to[Maxn<<2],cnt1;
inline void add(int u,int v){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	head[u]=cnt1;
}
int f[Maxn];
struct node{
	int u,data;
	inline bool operator<(const node&a)const{
		return a.data<data;
	}
};
priority_queue<node>heap;
vector<int>e[55];
int vis[Maxn];
inline void solve40(){
	for(int i=1;i<=n;i++){
		read(b[i]);
		add(b[i],i);
	}
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++){
			int d;scanf("%1d",&d);
			if(d)e[i].push_back(j);
		}
	memset(f,0x7f,sizeof f);
	f[1]=0;
	heap.push({1,0});
	while(heap.size()){
		node tmp=heap.top();
		heap.pop();
		int u=tmp.u;
		if(vis[u])continue;
		vis[u]=1;
		for(auto y:e[b[u]]){
			for(int j=head[y];j;j=nxt[j]){
				int v=to[j];
				if(u!=v&&f[v]>f[u]+abs(u-v)){
					f[v]=f[u]+abs(u-v);
					heap.push({v,f[v]});
				}
			}
		}
	}
	printf("%d\n",f[n]>=1e9?-1:f[n]);
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n);read(k);
	if(n<=1000){
		solve40();
		return 0;
	}
	return 0;
}
