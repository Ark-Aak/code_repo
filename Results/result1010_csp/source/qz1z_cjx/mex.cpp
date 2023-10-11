#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 5050
#define Mx 5050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll Mod=1e9+7;
ll n,B[Nx],used[Nx],mx;
inline ll work(){
	rep(i,0,mx)
		if(!used[i]) return i;
	return mx+1;
}
inline ll dfs(ll x){
	if(x>n) return work();
	ll res=0;
	rep(i,0,B[x]) 
		used[i]++,res+=dfs(x+1),used[i]--;
	return res;
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	rep(i,1,n=read()) mx=max(mx,B[i]=read());
	if(n<=7) printf("%lld",dfs(1)),exit(0);
	return 0;
}
