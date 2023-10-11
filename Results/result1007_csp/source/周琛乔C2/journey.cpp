#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=2e5+5,K=1e6+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int head[M],to[M<<1],nxt[M<<1],tot,pre[M];
inline void add(int x,int y){
	if(pre[x]==y) return;
	pre[x]=y;
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
vector<int> G[N],Q[M];
int n,m,q,u[M],v[M],l,r,s[K],t;
bool ans[K];
int vis[M],st;
void dfs(int p){
	vis[p]=st;
	for(int o=head[p];o;o=nxt[o])
		if(vis[to[o]]^st) dfs(to[o]);
}
inline int lower_bd(int x,int v){
	int l=0,r=G[x].size()-1,mid,ans=-1;
	while(l<=r){
		mid=(l+r>>1);
		if(G[x][mid]>=v) ans=mid,r=mid-1;
		else l=mid+1; 
	}return ans;
}
int main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=1;i<=m;i++){
		read(u[i]),read(v[i]);
		G[u[i]].push_back(i);
		G[v[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<G[i].size();j++)
		add(G[i][j-1],G[i][j]);
	for(int i=1,a,b;i<=q;i++){
		read(l),read(r);
		read(a),read(b);
		if(l==r){
			ans[i]=((u[l]==a&&v[l]==b)||(u[l]==b&&v[l]==a));
			continue;
		}
		t=lower_bd(a,l);
		s[i]=lower_bd(b,r);
		if(s[i]!=-1&&G[b][s[i]]>r) --s[i];
		if(t>=0&&s[i]>=0){
			s[i]=G[b][s[i]];
			Q[G[a][t]].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(!Q[i].size()) continue;
		st=i;
		dfs(i);
		for(int j=0;j<Q[i].size();j++)
			ans[Q[i][j]]=(vis[s[Q[i][j]]]==st);
	}
	for(int i=1;i<=q;i++) puts(ans[i]?"Yes":"No");
	return 0;
}

