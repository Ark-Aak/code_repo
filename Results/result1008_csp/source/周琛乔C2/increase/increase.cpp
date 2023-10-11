#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e5+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int head[M<<2],to[M<<3],nxt[M<<3],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m,cntp;
struct node{int u,v,w;}a[M];
inline bool cmp(node x,node y){return x.w<y.w;}
vector<int> G[N];
int f[M<<2][2];
int F(int p,bool s){
	if(f[p][s]!=-1) return f[p][s];
	f[p][s]=(s?(2e9):0);
	for(int o=head[p];o;o=nxt[o]){
		if(!s) f[p][0]=max(f[p][0],F(to[o],0^(p<2*m)));
		else f[p][1]=min(f[p][1],F(to[o],1^(p<2*m)));
	}
	if(f[p][s]==2e9) f[p][s]=0;
	f[p][s]+=(p<=m*2-1);
	return f[p][s];
}
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	read(n),read(m);
	cntp=m<<1;
	for(int i=1;i<=m;i++){
		read(a[i].u),read(a[i].v);
		read(a[i].w);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		G[a[i].u].push_back((i-1)*2);
		G[a[i].v].push_back(i*2-1);
	}
	for(int i=1;i<=n;i++)
		for(int j=G[i].size()-1;~j;j--){
			++cntp;
			if(j&&G[i][j]/2==G[i][j-1]/2){
				add(cntp,G[i][j]),add(cntp,G[i][j-1]);
				if(j!=G[i].size()-1){
					add(cntp,cntp-1);
					add(G[i][j]^1,cntp-1);
					add(G[i][j-1]^1,cntp-1);
				}
				--j;
			}else{
				add(cntp,G[i][j]);
				if(j!=G[i].size()-1){
					add(cntp,cntp-1);
					add(G[i][j]^1,cntp-1);
				}
			}
		}
	memset(f,-1,sizeof(f));
	for(int i=1,ans;i<=n;i++){
		ans=0;
		for(int j=0;j<G[i].size();j++)
			ans=max(ans,F(G[i][j],0));
		printf("%d ",ans);
	}
	return 0;
}

