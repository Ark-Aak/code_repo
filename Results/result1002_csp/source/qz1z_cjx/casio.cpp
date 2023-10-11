#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll int
#define Nx 30000050
using namespace std;
//---------------------------------// 
ll read(){
    ll x=0,f=0;char ch;
    while(!isdigit(ch=getchar())) f|=ch=='-';
    while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return f?-x:x;
}
//---------------------------------//
ll T,P,nxt[Nx],lastCasio;
ll prime[15000050],isprime[Nx],tot;
inline void Eural(ll lim){
	rep(i,2,lim){
		if(!isprime[i]) prime[++tot]=i;
		for(ll j=1;j<=tot&&i*prime[j]<=lim;j++){
			isprime[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
ll casio[Nx],t;
inline void alsoErual(ll lim){
    ll pos=-1;
	rep(i,1,tot) if(prime[i]>P){pos=i; break;} 
	if(pos==-1) return ;
	rep(i,pos,tot) casio[prime[i]]=1;
	rep(i,prime[pos],lim) if(casio[i])
		for(ll j=pos;j<=tot&&i*prime[j]<=lim;j++){
			casio[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
}
int main()
{ 
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	T=read(),P=read();
	Eural(30000001),alsoErual(30000001);
	drp(i,30000001,2)  {
		if((!isprime[i])||casio[i]) lastCasio=i;
		nxt[i]=lastCasio;
	}
	rep(i,1,T) printf("%d\n",nxt[read()]);
	return 0;
}
