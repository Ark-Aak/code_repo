//100!!!!!!!!!!!!!!!!!!!!!!!!!! 
//but input(max) 3.4s
#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
int n,q,a,b,res,gc,pl,head,dm=MX,dep[MX];
int fa[MX][22],mn[MX][22];
vector<int> v[MX];char op[6];
void add(int t){dm=min(dm,t);} 
void dfs(int t){
	for(auto i:v[t]){
		if(dep[i]) continue;
		dep[i]=dep[t]+1;
		fa[i][0]=t;dfs(i); 
	}
}
signed main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	scanf("%d%d",&n,&q);dep[1]=1;
	for(int i=1;i<=n;i++){mn[i][0]=i;}
	for(int i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}dfs(1);
	for(int i=1;i<=20;i++){
	for(int j=1;j<=n;j++){
		fa[j][i]=fa[fa[j][i-1]][i-1];
		mn[j][i]=min(mn[j][i-1],mn[fa[j][i-1]][i-1]);
	}}
	for(int o=1;o<=q;o++){
		scanf("%s%d",&op,&a);
		//cout<<dm<<' ';
		if(op[0]=='J'){add(a);
			if(!head){head=a;continue;}
			if(dep[head]<dep[a]){swap(head,a);}
			gc=dep[head]-dep[a];
			for(int i=20;i>=0;i--){
			if(gc&(1<<i)){
				add(mn[fa[head][0]][i]);
				head=fa[head][i];
			}}
			for(int i=20;i>=0;i--){
				if(fa[head][i]!=fa[a][i]){
					add(mn[head][i]);
					add(mn[a][i]);
					head=fa[head][i];
					a=fa[a][i];
				}
			}
			if(a!=head){
				add(mn[head][1]);
				head=fa[head][0];
			} 
		}else{
			res=min(dm,a);pl=head;
			if(dep[pl]<dep[a]){swap(pl,a);}
			gc=dep[pl]-dep[a];
			for(int i=20;i>=0;i--){
			if(gc&(1<<i)){
				res=min(res,mn[fa[pl][0]][i]);
				pl=fa[pl][i];
			}}
			for(int i=20;i>=0;i--){
				if(fa[pl][i]!=fa[a][i]){
					res=min(res,mn[pl][i]);
					res=min(res,mn[a][i]);
					pl=fa[pl][i];
					a=fa[a][i];
				}
			}
			if(a!=pl)
				res=min(res,mn[pl][1]);
			printf("%d\n",res);
		}
	}
	return 0;
} 
