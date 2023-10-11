#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=1005,M=2e5+5;
int val[N][N];
int tot,vis[N],tag[N][N];
int n,m,p;
vector<int> V[N];

void bfs(int l,int r,int s,int t){
	memset(vis,-1,sizeof(vis));
	memset(tag,0,sizeof(tag));
	queue<int> q;
	q.push(s);
	vis[s]=l-1;
	tag[s][s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(x==t) return;
		for(int i=0;i<(int)V[x].size();i++){
			int v=V[x][i];
			if(val[x][v]<vis[x] || tag[x][v]) continue;
			tag[x][v]=tag[v][x]=1;
			vis[v]=vis[x]+1;
			q.push(v);
		}
	}
}int l,r,s,t;
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	n=read();m=read();p=read();
	for(int i=1,u,v;i<=m;i++){
		u=read();
		v=read(); 
		val[u][v]=val[v][u]=i;
		V[u].push_back(v);
		V[v].push_back(u);
	}
//	cout << val[301][856] << "\n";
	for(int i=1;i<=p;i++){
		l=read();r=read();s=read();t=read();
		bfs(l,r,s,t);
		if(vis[t]==-1 || vis[t]>r) cout << "No\n";
		}else cout << "Yes\n";
		

	}
	return 0;
}


