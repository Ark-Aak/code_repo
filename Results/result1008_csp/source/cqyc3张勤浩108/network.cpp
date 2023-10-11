#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch<'0'||ch>'9')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	} 
	template<typename T>
	inline void write(T x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

const int Maxn=1e6+7;
int n,Q; 
vector<int>e[Maxn];
int f[Maxn][21],Log[Maxn],dep[Maxn];
int lstq,depMin,nws=1e9,dp[Maxn][21],llc;

void DFS1(int u,int ft){
	f[u][0]=ft;
	if(ft!=0) dp[u][0]=min(ft,u);
	else dp[u][0]=u;
	dep[u]=dep[ft]+1;
	for(int i=1;i<=20;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int i=1;i<=20;i++) dp[u][i]=min(dp[dp[u][i-1]][i-1],dp[u][i-1]);
	for(auto v:e[u]) if(v!=ft) DFS1(v,u);
}

inline int getMinLCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int sodayo=min(u,v);
	for(int i=Log[dep[u]];i>=0;i--)
		if(dep[f[u][i]]>=dep[v])
			sodayo=min(sodayo,dp[u][i]),u=f[u][i];
	if(u==v) return sodayo;
	
	for(int i=Log[dep[u]];i>=0;i--)
		if(f[u][i]!=f[v][i])
			sodayo=min(sodayo,min(dp[u][i],dp[v][i])),
			u=f[u][i],v=f[v][i];	
	return min(dp[u][0],sodayo);
}
inline int getLCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int sodayo=min(u,v);
	for(int i=Log[dep[u]];i>=0;i--)
		if(dep[f[u][i]]>=dep[v])
			sodayo=min(sodayo,dp[u][i]),u=f[u][i];
	if(u==v) return u;
	for(int i=Log[dep[u]];i>=0;i--)
		if(f[u][i]!=f[v][i])
			sodayo=min(sodayo,min(dp[u][i],dp[v][i])),
			u=f[u][i],v=f[v][i];	
	return f[u][0];
}
inline void Merge(int x,int y){
	nws=min(nws,getMinLCA(x,y));
}
inline int query(int x,int y){
	int res=getMinLCA(x,y);
	return res;
}
int ss[Maxn],cct;

int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	qread(n),qread(Q);
	for(int i=2;i<=Maxn-7;i++) Log[i]=Log[i>>1]+1;
	for(int i=1,u,v;i<n;i++)
		qread(u),qread(v),
		e[u].push_back(v),
		e[v].push_back(u);
	DFS1(1,0);
	while(Q--){
		char opt[10];
		int x;
		scanf("%s%d",opt,&x);
		if(opt[0]=='J'){
			ss[++cct]=x;
			for(int i=max(cct-20,1);i<cct;i++) Merge(ss[i],x);
		}
		else{
			int ans=1e9;
			for(int i=1;i<=min(cct,20);i++)
				ans=min(ans,min(query(ss[i],x),nws));
			for(int i=max(cct-20,1);i<=cct;i++)
				ans=min(ans,min(query(ss[i],x),nws));
			write(ans);
			putchar('\n');
		}
	}
	return 0;
}

/*
12 3
9 1
1 6
6 8
6 7
1 3
3 5
3 4
4 2
4 10
10 11
10 12
JC 11
JC 12
Query 4

5 9
1 3
5 3
2 4
4 3
JC 4
Query 5
Query 4
JC 2
Query 5
JC 1
Query 5
Query 1
Query 4
*/
