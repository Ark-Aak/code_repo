#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll int
#define Nx 1000050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll n,num[Nx],f[Nx][12],po[Nx];
char s[Nx],a[Nx];
inline void init(){
	po[0]=1;
	rep(i,1,n) po[i]=(po[i-1]*10)%11;
}
inline ll dfs(ll dig,ll past){
	if(dig>n) return !past;
	if(f[dig][past]!=-1) return f[dig][past];
	ll flag1=dfs(dig+1,past);
	ll flag2=dfs(dig+1,(past+num[dig]*po[n-dig]%11)%11);
	ll res;
	if(s[dig]=='o') res=(flag1&flag2);
	else res=(flag1|flag2);
	return f[dig][past]=res;
}
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	memset(f,-1,sizeof(f));
	n=read();
	init();
	scanf("%s",a+1);
	scanf("%s",s+1);
	rep(i,1,n) num[i]=a[i]-'0';
	if(dfs(1,0)) printf("yoimiya");
	else printf("oimiya");
	return 0;
}
