#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
int n,k,tot,ans;
// l0,r0,l1,r1;
vector<int>q[400005];
//int f[400005];
//int siz[400005];
bool vis[400005],bk[400005];
int minx=1e15,weicen;/*
void findwei(int x,int fa){
	siz[x]=1;
	for(auto v:q[x]){
		if(v==fa) continue;
		findwei(v,x);
		siz[x]+=siz[v];
	}
	if(abs((n-siz[x])-siz[x])<minx){
		minx=abs((n-siz[x])-siz[x]);
		weicen=x;
	}
}
void dfs(int x,int fa){
	f[x]=fa;
	for(auto v:q[x]){
		if(v==fa) continue;
		dfs(v,x);
	}
}*/
int gg[400005];
int pp[400005];
void work(int x){
	for(int i=1;i<x;i++){
		pp[i]+=x-i;
	}
	for(int i=1;i<=n-x;i++){
		pp[i]+=(n-x-i+1);
	}
	pp[1]+=x*(n-x+1);
	for(int i=1;i<=n;i++){
		ans+=i*i*pp[i]%Mod;
		ans%=Mod;
	}
	cout<<ans;
	return;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		q[u].push_back(v);
		q[v].push_back(u);
		gg[u]++;
		gg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(gg[i]==n-1){
			work(i);
			return 0;
		}
	}
	//findwei(1,0);
	//dfs(weicen,0);
	for(int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		memset(bk,false,sizeof(bk));
		tot=0;
		for(int j=i;j<=n;j++){
			tot++;
			bk[j]=1;
			for(auto v:q[j]){
				if(bk[v]) tot--;
			}
			if(k==2)ans+=tot*tot;
			if(k==1)ans+=tot;
			///cout<<tot<<" ";
			ans%=Mod;
		}
		//cout<<endl;
		ans%=Mod;
	}
	cout<<ans;
	return 0;
}
/*
  
  10 5
  0101011001
  9 5
  111010000
 */
