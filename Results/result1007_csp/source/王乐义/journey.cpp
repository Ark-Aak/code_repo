#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
struct A{
	int x,id;
};
vector<A>e[1003];
bool ans;
int l,r,s,t;
int n,m,q;
int b[1003];
void dfs(int x,int sj){
//	cout<<x<<"\n";
	b[x]=1;
	if(ans)return;
	if(sj>r)return;
	if(x==t&&sj<=r){
		ans=1;
		return;
	}
	for(int i=0;i<e[x].size();i++){
		if(e[x][i].id<sj)continue;
		if(b[e[x][i].x])continue;
		b[e[x][i].x]=1;
		dfs(e[x][i].x,e[x][i].id);
	}
}
int main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,i});
		e[v].push_back({u,i});
	}
	for(int i=1;i<=q;i++){
		cin>>l>>r>>s>>t;
		if(l==r){
			ans=0;
			for(int i=0;i<e[s].size();i++){
				if(e[s][i].id==l&&e[s][i].x==t)ans=1;
			}
			if(s==t)ans=1;
			cout<<(ans?"Yes\n":"No\n");
		}
		else{
			for(int i=1;i<=n;i++)b[i]=0;
			ans=0;
			dfs(s,l);
			cout<<(ans?"Yes\n":"No\n");
		}
	}
	return 0; 
}
