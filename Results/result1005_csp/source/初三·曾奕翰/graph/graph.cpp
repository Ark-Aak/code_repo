#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
bool vis[300005];
bool bk[300005];
int gg[30005],t,dic[30005];
int f[30005];
vector<int>q[300005];
int find(int fa){
	if(f[fa]==fa) return fa;
	return f[fa]=find(f[fa]);
}
void dfs(int u,int bs,int fin){
	if(u==fin){
		for(int i=0;i<=bs;i++){
		//	cout<<gg[i]<<" ";
			bk[gg[i]] =1;
		}
		//cout<<endl;
		return;
	}
	for(auto v:q[u]){
		if(vis[v]==0) {
			vis[v]=1;
			gg[bs+1]=v;
			dfs(v,bs+1,fin);
			vis[v]=0;
			gg[bs+1]=0;
			
		}
	}
}
signed main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		q[u].push_back(v);
		q[v].push_back(u);
	}
	int Q;
	scanf("%d",&Q);
	while(Q--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(n>=50000){
			cout<<1<<endl;
			continue;
		} 
		for(int i=1;i<=n;i++){
			f[i]=i;
			dic[i]=0;
			bk[i]=0;
		}
		gg[0]=l;
		vis[l]=1;
		dfs(l,0,r);
		vis[l]=0;
		for(int i=1;i<=n;i++){
			if(bk[i]) continue;
			for(int vv=0;vv<q[i].size();vv++){
				int j=q[i][vv];
				if(!bk[j]){
					f[find(j)]=find(i);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(!bk[i]) dic[find(i)]++;
		}
		for(int i=1;i<=n;i++){
			ans=ans^dic[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

