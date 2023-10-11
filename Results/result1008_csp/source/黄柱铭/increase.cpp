#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
const int N=5005;
int n,m;
struct node{
	int v,lst,c;
};
vector<int> V[N];
int vis[N][N],val[N];
vector<int> mp[5005][5005];
int ans;
queue<node> q;
void bfs(int sx){
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	q.push((node){sx,0,0});
	while(!q.empty()){
		int now=q.front().v;
		int lst=q.front().lst;
		int c=q.front().c;
		ans=max(ans,c);
		q.pop();
//		cout << now << " " << lst << "\n";
		int idx=0;
		for(int i=0;i<(int)V[now].size();i++){
			int v=V[now][i];
			idx=0;
			if(c%2==0){
				while(idx<(int)mp[now][v].size() && mp[now][v][idx]<=lst) idx++;
			}else idx=(int)mp[now][v].size()-1;
			
			if(mp[now][v][idx]<=lst || idx>=mp[now][v].size()) continue;
//			cout << v << " " << mp[now][v][idx] << " "; 
			q.push((node){v,mp[now][v][idx],c+1});
		}
//		printf("\n");
	}
}
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	n=read();m=read();
	for(int i=1,u,v,w;i<=m;i++){
		u=read();v=read();w=read();
		mp[u][v].push_back(w);
		mp[v][u].push_back(w);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
				sort(mp[i][j].begin(),mp[i][j].end());
		}
	}
	for(int i=1;i<=n;i++){
		ans=0;
		bfs(i);
//		printf("\n");
		cout << ans << " ";
	}
	return 0;
}

/*
4 6
3 1 2
2 3 1
4 1 5
1 4 3
2 1 6
1 3 4

*/
