#include<bits/stdc++.h>
using namespace std;
int n,m,q,a,b,res,pt;bool c[1005],d[1005],e[1005];
vector<int> v[1005];
void dfs(int t){
	if(t==b){
		d[t]=1;
		return;
	}/*		cout<<t<<':';
		for(int i=1;i<=n;i++){cout<<c[i];}cout<<' ';
		for(int i=1;i<=n;i++){cout<<e[i];}cout<<' ';
		for(int i=1;i<=n;i++){cout<<d[i];}cout<<'\n';*/
	for(auto i:v[t]){
		if(c[i]) continue;
		if(e[i]){d[t]|=e[i];continue;}
		c[i]=e[i]=++pt;dfs(i);
		d[t]|=d[i];c[i]=0;
	}/*cout<<t<<'[';
		for(int i=1;i<=n;i++){cout<<c[i];}cout<<' ';
		for(int i=1;i<=n;i++){cout<<e[i];}cout<<' ';
		for(int i=1;i<=n;i++){cout<<d[i];}cout<<'\n';*/
}
int dfs2(int t){
	d[t]=1;int cnt=1;
	for(auto i:v[t]){
		if(d[i]) continue;
		cnt+=dfs2(i);
	}return cnt;
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}cin>>q;
	while(q--){
		cin>>a>>b;res=0;pt=1;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		c[a]=e[a]=1;dfs(a);d[a]=1;
		//for(int i=1;i<=n;i++){cout<<d[i];}cout<<' ';
		for(int i=1;i<=n;i++){
			if(d[i]) continue;
			res^=dfs2(i);
		}cout<<res<<'\n';
	}
	return 0;
} 
