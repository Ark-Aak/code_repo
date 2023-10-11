#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 1000050
#define Mx 1050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll P=1e9+7;
ll N,M,K,inv,R[Mx],C[Mx],fac1[Nx],fac2[Nx],vis1[Nx],vis2[Nx],ans,sum;
inline ll id(ll t,ll s){ return ((t-1)*M%P+s)%P; }
inline ll qpow(ll x,ll k){ return k>0?(ll)pow(x,k&1)*qpow(x*x%P,k>>1)%P:1ll; }
inline ll calc(ll A1,ll An,ll n){ return (A1+An)%P*n%P*inv%P; }
inline void solve(){
	rep(i,1,R[0]) ans=(ans+fac1[R[i]]*(calc(id(R[i],1),id(R[i],M),M))%P)%P;	
	rep(i,1,C[0]) ans=(ans+fac2[C[i]]*(calc(id(1,C[i]),id(N,C[i]),N))%P)%P;
	rep(i,1,R[0]) rep(j,1,C[0]){
		ans=(ans+(fac1[R[i]]*fac2[C[j]]%P-(fac1[R[i]]+fac2[C[j]])+P)%P*id(R[i],C[j])%P)%P;
		sum=(sum+id(R[i],C[j]))%P;
	}
	return (void)printf("%lld",(sum+ans)%P);
}
int main()
{	
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	char c;
	N=read(),M=read(),K=read();
	inv=qpow(2,P-2);
	sum=calc(1,id(N,M),N*M%P);
	rep(i,1,max(N,M)) fac1[i]=fac2[i]=1;
	rep(i,1,K){
		scanf("%c",&c);
		ll X=read(),Y=read();
		if(c=='R'){
			if(!vis1[X]) sum=(sum-calc(id(X,1),id(X,M),M)+P)%P,vis1[X]=1,R[++R[0]]=X;
			fac1[X]=(fac1[X]*Y%P);
		} else {
			if(!vis2[X]) sum=(sum-calc(id(1,X),id(N,X),N)+P)%P,vis2[X]=1,C[++C[0]]=X;
			fac2[X]=(fac2[X]*Y%P);
		}
	}
	solve();
	return 0;
}
