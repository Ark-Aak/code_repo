#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int s,t,n,m;
vector<int>G[3];
ll f[3][N];
inline int dist(int x,int y){return max(0,y-x-s);}
inline ll calc(int k,int x){
	int p=lower_bound(G[k].begin(),G[k].end(),x)-G[k].begin();
	return f[k][p]+dist(x,G[k][p]);
}
namespace file{
	string IN,OUT,s;
	inline void std(){
		freopen("name.txt","r",stdin);
		cin>>s;
		IN=s+".in",OUT=s+".out";
		freopen(IN.c_str(),"r",stdin);
		freopen(OUT.c_str(),"w",stdout);
	}
	inline void data(){
		freopen("name.txt","r",stdin);
		cin>>s;
		IN=s+".in",OUT=s+".out";
		freopen(IN.c_str(),"w",stdout);
	}
}
char opt[5];
signed main(){
//	file::std();
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	scanf("%d %d %d %d",&s,&t,&n,&m);
	for(int x,y,i=1;i<=n;++i){
		scanf("%d %s",&x,&opt);
		if(opt[1]=='M') y=3;
		else if(opt[1]=='N') y=2;
		else y=1;
		if(x<t) for(int j=0;j<y;++j) G[j].push_back(x);
	}
	for(int i=0;i<3;++i){
		G[i].push_back(t);
		sort(G[i].begin(),G[i].end());
		for(int j=G[i].size()-2;~j;--j)
			f[i][j]=f[i][j+1]+dist(G[i][j],G[i][j+1]);
	}
	for(int x,i=1;i<=m;++i){
		scanf("%d",&x);
		if(calc(0,x)) printf("-1\n");
		else printf("%lld %lld\n",calc(1,x),calc(2,x)-calc(1,x));
	}	
}
