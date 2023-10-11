#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 100005
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll inf=LONG_LONG_MAX;
ll N,tot,ans;
char s[Nx],c[Nx];
map<char,ll> mp,a,vis;
//#define tools//
ll calc(){
	ll pos=0,cnt=1;
	rep(i,0,N-1){
		if(a[s[i]]<=pos) cnt++;
		pos=a[s[i]];
	}
	#ifdef tools
	if(cnt<ans){
		rep(i,1,tot) rep(j,1,tot)
			if(a[c[j]]==i) putchar(c[j]);
		putchar(10);
	} 
	#endif
	return cnt;
}
void dfs(ll x){
	if(x>tot){
		ans=min(ans,calc());
		return ;
	} 
	rep(i,1,tot){
		if(!vis[c[i]]) {
			vis[c[i]]=1;
			a[c[i]]=x;
			dfs(x+1);
			vis[c[i]]=0;
		}
	}
}
int main()
{	
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	scanf("%s",s);
	N=strlen(s);
	rep(i,0,N-1) if(!mp[s[i]]) mp[s[i]]=1,c[++tot]=s[i];
	ans=inf;
	dfs(1);
	printf("%lld",ans);
	return 0;
}
