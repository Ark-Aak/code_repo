#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	ll m,q;
	read(),m=read(),q=read();
	rep(i,1,m) read(),read();
	rep(i,1,q){
		read(),read();
		if(read()==read()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
