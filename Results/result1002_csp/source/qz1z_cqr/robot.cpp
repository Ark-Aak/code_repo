#include<bits/stdc++.h>
#define MX 120005
using namespace std;
int T,n,m,a,b,p[MX],q[MX],fa[MX],st[MX],dep[MX],rd[MX];
vector<int> v[MX],o[MX],e[MX];queue<int> qe;
void dfs(int t){
	for(auto i:v[t]){
		if(fa[t]==i) continue;
		dep[i]=dep[t]+1;
		fa[i]=t;dfs(i);
	}
}
void add(int x,int y){
	if(x==y) return;
	e[y].push_back(x);
	rd[x]++;
}
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout); 
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			v[i].clear();o[i].clear();e[i].clear();
			st[i]=fa[i]=rd[i]=dep[i]=0;
		}
		for(int i=1;i<n;i++){
			scanf("%d%d",&a,&b);
			v[a].push_back(b);
			v[b].push_back(a);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p[i],&q[i]);
			st[p[i]]=i;
		}
		dfs(1);
		for(int i=1;i<=m;i++){
			a=p[i];b=q[i];
			if(dep[a]<dep[b]) swap(a,b);
			while(dep[a]>dep[b]){
				o[a].push_back(i);
				if(st[a])
					add(i,st[a]);
				a=fa[a];
			}
			while(a!=b){
				o[a].push_back(i);
				o[b].push_back(i);
				if(st[a])
					add(i,st[a]);
				if(st[b])
					add(i,st[b]);
				a=fa[a];b=fa[b];
			}o[a].push_back(i);
			if(st[a])
				add(i,st[a]);
		}
		/*for(int i=1;i<=n;i++){
			cout<<i<<": ";
			for(auto j:o[i]){cout<<j<<' ';}cout<<'\n';
		}*/
		for(int i=1;i<=m;i++)
			for(auto j:o[q[i]]){add(i,j);}
		for(int i=1;i<=m;i++){
			/*cout<<i<<": ";
			for(auto j:e[i]){cout<<j<<' ';}cout<<'\n';*/
			if(!rd[i]) qe.push(i);
		}
		while(qe.size()){
			int t=qe.front();
			m--;qe.pop();
			for(auto i:e[t]){
				rd[i]--;
				if(!rd[i])
					qe.push(i);
			}
		}
		if(m) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
} 
