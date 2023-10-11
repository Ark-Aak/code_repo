#include<bits/stdc++.h>
#define reg register
const int N=392702,mod=1e9+7;
struct node{
	int u,v;
	bool operator<(const node &i) const{
		return u<i.u;
	}
}a[N];
int f[N],g[N],n,k,ans,sum,res;
int R() {
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
void swap(reg int &a,reg int &b) {
	reg int t=a;
	a=b,b=t;
}
inline int Mod(reg int x) {
	return x>=mod?x-mod:x;
}
void frev(reg int x,reg int v) {
	for(reg int i=x;i<=n;i+=i&-i) f[i]=Mod(f[i]+v);
}
void grev(reg int x,reg int v) {
	for(reg int i=x;i<=n;i+=i&-i) g[i]=Mod(g[i]+v);
}
int fsum(reg int x) {
	reg int s=0;
	for(reg int i=x;i;i&=i-1) s=Mod(s+f[i]);
	return s;
}
int gsum(reg int x) {
	reg int s=0;
	for(reg int i=x;i;i&=i-1) s=Mod(s+g[i]);
	return s;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=R(),k=R();
	for(reg int i=1;i<n;++i) {
		a[i]=(node){R(),R()};
		if(a[i].u>a[i].v) swap(a[i].u,a[i].v);
	}
	if(k==1) {
		for(reg int i=1;i<n;++i) ans=(ans+1ll*a[i].u*(n-a[i].v+1))%mod;
		return !printf("%lld\n",((1ll*(n+1)*n>>1)*(n+1)-1ll*n*(n+1)*(n<<1|1)/6+mod-ans)%mod);
	}
	std::sort(a+1,a+n);
	for(reg int i=1;i<n;++i) {
		res=(res+1ll*a[i].u*(n-a[i].v+1))%mod;
		sum=(sum+1ll*a[i].u*(n-a[i].v+1)*(n+a[i].v-a[i].u+1))%mod;
		ans=(ans+1ll*fsum(a[i].v)*(n-a[i].v+1)+gsum(n-a[i].v))%mod;
		frev(a[i].v,a[i].u),grev(n-a[i].v+1,1ll*a[i].u*(n-a[i].v+1)%mod);
	}
	printf("%lld\n",(1ll*n*(n+1)*(n<<1|1)/6%mod*(n+1)+mod-(1ll*n*(n+1)>>1)%mod*((1ll*n*(n+1)>>1)%mod)%mod+(ans<<1)+mod-sum+res)%mod);
}
