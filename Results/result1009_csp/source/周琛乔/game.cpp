#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int T,n,m,sum[20][20];
int dfs(int x,int y,int addx,int addy){
	if(x==1&&y==1) return 0;
	if(x==1&&y==m) return 0;
	if(x==n&&y==1) return 0;
	if(x==n&&y==m) return 0;
	bool add=0;
	if(x==1||x==n) addx*=-1,add=1;
	if(y==1||y==m) addy*=-1,add=1;
	return dfs(x+addx,y+addy,addx,addy)+add;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	for(n=2;n<=11;n++)
	for(m=2;m<=11;m++)
		sum[n][m]=(1ll*dfs(2,2,1,1)+sum[n-1][m]+sum[n][m-1]-sum[n-1][m-1])%mod;	
	read(T);
	while(T--){
		read(n),read(m);
		printf("%d\n",sum[n+1][m+1]);
	}
	return 0;
}

