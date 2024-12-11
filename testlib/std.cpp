#include<bits/stdc++.h>
#define N 262150
#define S 520
#define M 100005
#define P 511
#define D 100000
using namespace std;
int read(){
	int x=0,f=1,ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=(ch=='-')?-1:1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
int n,q,v[N],w[N];
int f[S][M];
bool check(int x,int base){return x>>base&1;}
int main(){
	n=read();
	for(int i=1;i<=n;++i) v[i]=read(),w[i]=read();
	for(int i=1;i<=n && i<=P;++i){
		for(int j=0;j<=D;++j) f[i][j]=f[i>>1][j];
		for(int j=w[i];j<=D;++j) f[i][j]=max(f[i][j],f[i>>1][j-w[i]]+v[i]);
	}
	for(int i=1;i<=n && i<=P;++i) for(int j=1;j<=D;++j) f[i][j]=max(f[i][j],f[i][j-1]);
	q=read();
	while(q--){
		int x=read(),l=read(),ans=0;
		vector<int>g;
		for(;x>P;x>>=1) g.push_back(x);
		for(int s=0;s<(1<<g.size());++s){
			int res=0,sum=0;
			for(int i=0;i<g.size();++i) if(check(s,i)) res+=v[g[i]],sum+=w[g[i]];
			if(sum<=l) ans=max(ans,res+f[x][l-sum]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
