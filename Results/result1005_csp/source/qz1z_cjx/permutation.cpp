#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 105
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll n,k,iknow;
namespace make_tools{
	ll circle_size=0;// size of circle 
	const ll MaxSize=1000000;
	struct Array{  
		ll num[Nx]; // a[i]
		ll& operator[](ll x){ return num[x]; };
		friend bool operator==(Array x,Array y){
			rep(i,1,n) if(x[i]!=y[i]) return false;
			return true;
		}
	} f0, f1, fn ,q ,p;
	bool main1(bool id_1){
		rep(i,1,n) f0[i]=q[i]=read();
		rep(i,1,n) f1[i]=p[i]=read();
		rep(i,1,MaxSize){
			rep(j,1,n) fn[f0[j]]=f1[j];
			memcpy(f0.num,f1.num,sizeof f1.num);
			memcpy(f1.num,fn.num,sizeof fn.num);
			if(f0==q&&f1==p) 
			return circle_size=i-1,true;
		}
		return false ;
	}
} // namespace make_tools
namespace Studio{
	using namespace make_tools;//
	bool main2(bool id_2){
		if(!id_2) return false;
		ll pos=k%iknow;
		rep(i,1,n) f0[i]=q[i],f1[i]=p[i];
		if(pos==1) {
			rep(j,1,n) printf("%lld ",f1[j]);
			return true;
		}
		rep(i,2,MaxSize){
			rep(j,1,n) fn[f0[j]]=f1[j];
			memcpy(f0.num,f1.num,sizeof f1.num);
			memcpy(f1.num,fn.num,sizeof fn.num);
			if(i==pos) {
				rep(j,1,n) printf("%lld ",f1[j]);
				return true; 
			}
		}
		return false ;
	}
} // namespace Studio
#define tools//
//#define tools_check//
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read(),k=read();
	#ifdef tools
		using namespace make_tools;
		bool flag=main1(true) ;
		#ifdef tools_check
		if(!flag) return printf("No Circle"),0;
		printf("\n%lld\n",circle_size);
		printf("\n----------------\n\n");
		#endif
		if(flag) iknow=circle_size;
	#endif
	using namespace Studio; 
	main2(flag); 
	return 0;
 } 
