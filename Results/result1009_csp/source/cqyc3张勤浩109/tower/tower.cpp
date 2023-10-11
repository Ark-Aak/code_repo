#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+7,inf=1e9;
int n,k,w[Maxn],dis[Maxn];
vector<int>G[110],e[Maxn];
struct node{
	int u,val,stp;
	friend bool operator<(const node x,const node y){
		return x.val>y.val;
	}
};
priority_queue<node>q;
bool vis[Maxn];
inline void Dijkstra(int s){
	for(int i=0;i<=n;i++) dis[i]=inf;
	dis[s]=0;
	q.push((node){s,0,0});
	while(!q.empty()){
		node tp=q.top();q.pop();
		if(tp.stp>=k) break;
		if(vis[tp.u]) continue;
		vis[tp.u]=1;
		for(auto i:G[w[tp.u]]){
			for(auto j:e[i]){
				if(tp.u!=j){
					//cout<<"test "<<tp.u<<" "<<j<<' '<<i<<endl;
					if(dis[j]>dis[tp.u]+abs(j-tp.u)){
						dis[j]=dis[tp.u]+abs(j-tp.u);
						q.push((node){j,dis[j],tp.stp+1});
					}
				}
			}
		}
	}
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]),e[w[i]].push_back(i);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++){
			int kd;scanf("%1d",&kd);
			if(kd) G[i].push_back(j);
		}
	Dijkstra(1);
	if(dis[n]!=inf) printf("%d\n",dis[n]);
	else printf("-1");
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/

