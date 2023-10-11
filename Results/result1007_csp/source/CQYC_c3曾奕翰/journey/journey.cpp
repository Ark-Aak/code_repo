#include<bits/stdc++.h> 
using namespace std;
int n,m,k;
int u[200005],v[200005];
vector<pair<int,int> >q[1005];
bool vis[1005];
bool flag=0;
void dfs(int x,int to,int gg,int kk,int l,int r){
	if(kk<l&&kk!=0) return;
	if(gg>r&&gg!=0) return;
	if(x==to){
		if(gg<=r){
			flag=1;
		}
		return;
	}
	for(int j=0;j<q[x].size();j++){
		int v=q[x][j].first,w=q[x][j].second;
		if(vis[v]) continue;
		if(w<gg) continue;
		vis[v]=1;
		if(kk==0) 
			dfs(v,to,w,w,l,r);
		else dfs(v,to,w,kk,l,r);
		vis[v]=0;
	}
}
int main() {
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u[i],&v[i]);
		q[u[i]].push_back(make_pair(v[i],i));
		q[v[i]].push_back(make_pair(u[i],i));
	}
	while(k--){
int l,r,s,t;
		scanf("%d%d%d%d",&l,&r,&s,&t);
		if(l==r){
			if(u[l]==s&&v[l]==t){
				cout<<"Yes"<<endl;
				continue;
			}
			if(u[l]==t&&v[l]==s){
				cout<<"Yes"<<endl;
				continue;
			}
			cout<<"No"<<endl;
			continue;
		}
		flag=0;
		vis[s]=1;
		dfs(s,t,0,0,l,r);
		vis[s]=0;
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 10

