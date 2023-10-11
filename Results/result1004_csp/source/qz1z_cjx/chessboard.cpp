#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 2050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll n,m;
char a[Nx][Nx];
inline bool checktype1(ll x,ll y){
	if(a[x][y-1]=='0'&&a[x-1][y]=='0'&&a[x-1][y-1]=='1') return true;
	if(a[x-1][y]=='0'&&a[x][y+1]=='0'&&a[x-1][y+1]=='1') return true;
	if(a[x][y+1]=='0'&&a[x+1][y]=='0'&&a[x+1][y+1]=='1') return true;
	if(a[x+1][y]=='0'&&a[x][y-1]=='0'&&a[x+1][y-1]=='1') return true;
	return false;
}
inline bool checktype2(ll x,ll y){
	if(a[x][y-1]=='1'&&a[x-1][y]=='1'&&a[x-1][y-1]=='0') return true;
	if(a[x-1][y]=='1'&&a[x][y+1]=='1'&&a[x-1][y+1]=='0') return true;
	if(a[x][y+1]=='1'&&a[x+1][y]=='1'&&a[x+1][y+1]=='0') return true;
	if(a[x+1][y]=='1'&&a[x][y-1]=='1'&&a[x+1][y-1]=='0') return true;
	return false;
}
namespace solve_round_1{
	bool vis[Nx][Nx],flag;
	ll tx[]={0,-1,-1,-1,0,1,1,1,0};
	ll ty[]={0,-1,0,1,1,1,0,-1,-1};
	inline void dfs(ll x,ll y){
		vis[x][y]=1;
		if(x<1||x>n||y<1||y>m||!flag) return ;
		rep(i,1,8){
			ll _x=x+tx[i],_y=y+ty[i];
			if(a[_x][_y]=='?'&&!vis[_x][_y])
				dfs(_x,_y);
		}
		bool type1=checktype1(x,y),type2=checktype2(x,y);
		if(type1&&type2) { flag=false; return ; }
		if(type1) a[x][y]='0';
		else if(type2) a[x][y]='1';
		else a[x][y]='1';
	}
	inline void main(){
		flag=true;
		rep(i,1,n) rep(j,1,m) {
			if(checktype1(i,j)&&a[i][j]=='1') flag=false;
			if(checktype2(i,j)&&a[i][j]=='0') flag=false;
		}
		rep(i,1,n) rep(j,1,m) 
			if(a[i][j]=='?'&&!vis[i][j]) dfs(i,j);
		if(!flag) return (void)printf("No");
		else printf("Yes\n");
		rep(i,1,n){
			rep(j,1,m) putchar(a[i][j]);
			putchar(10);
		}
	}
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n) scanf("%s",a[i]+1);
	solve_round_1::main();
	return 0;
}

