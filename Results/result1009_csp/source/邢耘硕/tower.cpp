#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,k,color[N],f[105][105];
struct Point{
	int v,val;
};
vector <int> cnt[105];
vector <Point> e[N];
int dis[N];
struct cmp{
	bool operator()(Point x,Point y){
		return x.val>y.val;
	} 
};
priority_queue <Point,vector<Point>,cmp> q;
int flag[105][105]; 
void add(int x,int y){
	for(int i = 0;i < cnt[x].size();i++)
		for(int j = 0;j < cnt[y].size();j++)
			e[cnt[x][i]].push_back((Point){cnt[y][j],abs(cnt[x][i]-cnt[y][j])});
}
bool vis[N]; 
void dij(){
	memset(vis,false,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push((Point){1,0});
	while(!q.empty()){
		Point head=q.top();
		q.pop();
		if(vis[head.v])continue;
		vis[head.v]=1;
		for(int i = 0;i < e[head.v].size();i++){
			int v1=e[head.v][i].v,w=e[head.v][i].val;
			if(dis[v1]>dis[head.v]+w){
				dis[v1]=dis[head.v]+w;
				q.push((Point){v1,dis[v1]});
			}
		}
	}
}
char op[105][105];
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> color[i];
		cnt[color[i]].push_back(i);
	}
	for(int i = 1;i <= k;i++){
		for(int j = 1;j <= k;j++){
			cin >> op[i][j];
			if(op[i][j]=='1')flag[i][j]=1;	
		}
	}
	for(int i = 1;i <= k;i++)
		for(int j = 1;j <= k;j++)
			if(op[i][j]=='1')
				add(i,j);
	dij();
	if(dis[n]!=0x3f3f3f3f)cout << dis[n];
	else cout << -1;
	return 0;
}
