#include<bits/stdc++.h>
using namespace std;
struct color{
	int tot,point[50005];
};
color col[100];
int n,k,colo[50005],dis[50005],b[50005],ccol[100][100];
int dijkstra(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[1]=0;
	priority_queue<pair<int,int> >q;
	q.push({0,1});
	while(!q.empty()){
		pair<int,int> t=q.top();
		q.pop();
		int u=t.second,diss=-t.first;
		if(b[u]){
			continue;
		}
		b[u]=1;
		for(int i=1;i<=n;i++){
			if(ccol[colo[u]][colo[i]])
				if(dis[i]>diss+abs(i-u)){
					dis[i]=diss+abs(i-u);
					q.push({-dis[i],i});
				}
		}
	}
	if(dis[n]==0x3f3f3f3f){
		dis[n]=-1;
	}
	return dis[n];
}
int main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>colo[i];
		col[colo[i]].point[++col[colo[i]].tot]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			char ch;
			cin>>ch;
			ccol[i][j]=ch-'0';
		}
	}
	cout<<dijkstra()<<endl;
	return 0;
}
