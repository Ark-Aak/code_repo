//100
#include<bits/stdc++.h>
#define MX 100005
using namespace std;
int n,x,y,ans,cnt,p[MX][5],l[MX*2][5],ck[MX*2],fa[MX*2];
int find(int o){return fa[o]=(fa[o]==o?o:find(fa[o]));}
void merge(int xx,int yy){fa[xx]=yy;}
struct eg{int c,u,v;}s[MX];
bool cmp(eg xx,eg yy){return xx.c<yy.c;}
void dfs(int t,int color){
	if(ck[t]) return;
	ck[t]=color;
	dfs(p[l[t][0]][l[t][1]^1],color);
	dfs(p[l[t][2]][l[t][3]^1],color);
}
signed main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		fa[i*2-1]=i*2-1;fa[i*2]=i*2;
		scanf("%d%d%d%d%d",&s[i].c,&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
		for(int j=0;j<4;j++){
			if(!l[p[i][j]][0]){
				l[p[i][j]][0]=i;
				l[p[i][j]][1]=j;
			}else{
				l[p[i][j]][2]=i;
				l[p[i][j]][3]=j;
			}
		}
	}
	for(int i=1;i<=n*2;i++)
	if(!ck[i]) dfs(i,++cnt);
	for(int i=1;i<=n;i++){
		s[i].u=ck[p[i][0]];
		s[i].v=ck[p[i][2]];
		//cout<<s[i].c<<' '<<s[i].u<<' '<<s[i].v<<'\n';
	}
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		x=find(s[i].u);
		y=find(s[i].v);
		if(x!=y){
			merge(x,y);
			ans+=s[i].c;
		}
	}printf("%d",ans);
	return 0;
} 
