#include<bits/stdc++.h>
using namespace std;
vector<int>p;
int vis[10000005];
void init(int x){
	p.push_back(1);
	for(int i=2;i<=x;i++){
		if(vis[i]==0)p.push_back(i),vis[i]=i;
		for(int j=1;j<p.size();j++){
			int s=p[j];
			if(s>vis[i])break;
			if(s*i>x)break;
			vis[s*i]=s;
		}
	}
}
int n; 
int b[10000005];
int s1[2005],tot1;
int s2[2005],tot2;
struct node{
	int to,w,nxt;
}e[8000005];
int head[4005],h[4005],d[4005],S,T,tot=1;
void add(int u,int v,int z){e[++tot]=node{v,z,head[u]};head[u]=tot;e[++tot]=node{u,0,head[z]};head[z]=tot;}
inline bool bfs(){
	queue<int>q;
	memset(d,0,sizeof d);
	q.push(1);
	h[1]=head[1];
	d[1]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u],v;i;i=e[i].nxt){
			v=e[i].to;
			if(!d[v]&&e[i].w){
				d[v]=d[u]+1;
				h[v]=head[v];
				q.push(v);	
				if(n==v)return 1;
			}
		}
	}
	return 0;
}
inline int dfs(int u,int res){
	if(n==u)return res;
	int sum=res;
	for(int i=h[u],v;i&&sum;i=e[i].nxt){
		v=e[i].to;
		h[u]=i; 
		if((d[v]==d[u]+1)&&e[i].w){
			int temp=dfs(v,min(sum,e[i].w));
			if(!temp)d[v]=0;
			sum-=temp;
			e[i].w-=temp;
			e[i^1].w+=temp;
		}
	}
	return res-sum;
}
int Dinic(){
	int res=0;
	while(bfs())res+=dfs(S,1e9);
	return res;
}
signed main(){
	freopen("crazy.in","r",stdin);
	freopen("crazy.out","w",stdout);
	init(10000000);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		b[x]=1;
	}
	for(int i=1;i<=10000001;i++)
		if(b[i]^b[i-1]){
			if(i&1)s1[++tot1]=i;
			else s2[++tot2]=i;
		}
	S=0,T=tot1+tot2+1;
	for(int i=1;i<=tot1;i++)
		for(int j=1;j<=tot2;j++)
			if(vis[abs(s1[i]-s2[j])]==abs(s1[i]-s2[j])&&abs(s1[i]-s2[j])>2)add(i,j+tot1,1);
	for(int i=1;i<=tot1;i++)add(S,i,tot2);
	for(int i=1;i<=tot2;i++)add(i+tot1,T,1);
	int res=Dinic();
	for(int i=1;i<=tot1;i++){
		for(int j=head[i];j;j=e[j].nxt){
			if(e[j].to==S){
				if(e[j].w>0)res-=!(e[j].w&1);
			}
		}
	}
	cout<<tot1+tot2-2*res+((tot1-res)&1)<<endl;
	return 0;
}
