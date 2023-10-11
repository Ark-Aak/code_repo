#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+7,inf=1e9;
int n,m,f[Maxn][2];
vector<pair<int,int> >e[Maxn];
int DFS(int u,int w,int stp){
	
	for(auto v:e[u]){
		if(v.second>w){
			f[v.first][0]=min(f[v.first][0],DFS(v.first,v.second,stp+1));
			f[v.first][1]=max(f[v.first][1],DFS(v.first,v.second,stp+1));
			f[u][1]=max(f[u][1],f[v.first][0]);
			f[u][0]=min(f[u][0],f[v.first][1]);
			//cout<<u<<" "<<v.first<<" "<<f[u][0]<<" "<<f[u][1]<<endl;
		}
	}
	return stp;
}
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(make_pair(v,w));
		e[v].push_back(make_pair(u,w));
	}
	
	
	for(int i=1;i<=n;i++){
	 for(int j=0;j<=n;j++) f[j][0]=inf;
		memset(f,0,sizeof 0);
		DFS(i,0,0);
		cout<<f[i][1]<<endl;
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

