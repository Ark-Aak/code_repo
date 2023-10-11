#include<bits/stdc++.h>
#define inf LONG_LONG_MAX
#define fir first
#define sec second
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define Pr(i,j) pair<i,j>
#define PB(i) push_back(i)
#define MP(i,j) make_pair(i,j)
#define Fo(i,j) for(auto i:j)
#define mem(i,j) memset(i,j,sizeof(i))
#define FO(i,j,k) for(int i=j;i;i=k)
#define FFF(i,j,k) for(auto i=j;i!=k;++i)
#define For(i,j,k) for(int i=j;i<=k;++i)
#define FoR(i,j,k) for(int i=j;i^k;++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define int long long
#define Mod 1000000007
#define N 5005 // ***
int n,ans;
int a[N],s[N],k[N];
void dfs(int u){
	if(u>n){
		mem(k,0);
		int sum;
		For(i,1,n)k[s[i]]=1;
		For(i,0,n){
			if(!k[i]){
				sum=i;
				break;
			}
		}ans+=sum;
		ans%=Mod;	
//		For(i,1,n)cout<<s[i]<<' ';
//		cout<<sum<<endl;
		return;
	}
	For(i,0,a[u]){
		s[u]=i;
		dfs(u+1);
	}
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	read(n);
	For(i,1,n)read(a[i]);
	sort(a+1,a+1+n);
	dfs(1);
	cout<<ans;
	return 0;
}
//int n,ans,all=1,Max;
//int a[N],k[N],t[N];
//int inv[N],finv[N],fac[N];
//int ksm(int a,int b){
//	int res=1;
//	while(b){
//		if(b&1)res=res*a%Mod;
//		a=a*a%Mod;
//		b>>=1;
//	}return res;
//}
//int C(int n,int m){
//	if(n<m)return 0;
//	return fac[n]*finv[m]%Mod*finv[n-m]%Mod;
//}
//int init(int n){
//	fac[0]=1;
//	For(i,1,n)fac[i]=fac[i-1]*i%Mod;
//	finv[n]=ksm(fac[n],Mod-2);
//	FOR(i,n,1)finv[i-1]=finv[i]*i%Mod;
//	For(i,0,n)inv[i]=ksm(i,Mod-2);
//}
//struct X{
//	int x,s;
//};
//X f[N];
//X Get(int n,int m){
//	if(m==1){
//		int s=1,ans=0;
//		For(i,1,n)s=s*a[i]%Mod;
//		For(i,1,n)ans=(ans+s*inv[a[i]]%Mod)%Mod;
//		return (X){ans,s};
//	}
//	X x=Get(n-1,m-1);
//	return (X){(x.x*(n-1)%Mod+x.s)%Mod,x.s*a[n]%Mod};
//}
//signed main(){
//	read(n);Max=n+1;init(n+n);
//	For(i,1,n)read(a[i]);
//	sort(a+1,a+1+n);t[n]=a[n];
//	FOR(i,n-1,1)t[i]=t[i+1]*a[i];
//	
////	For(i,1,n)all=all*(a[i]+1)%Mod;
//	
//	For(i,1,n)k[min(n,a[i])]++;
//	FOR(i,n,0)k[i]+=k[i+1];
//	
//	For(i,1,Max)Max=min(Max,k[i]+i);
//	
////	For(i,0,n)cout<<k[i]<<' ';cout<<endl;
////	cout<<Max<<' '<<all<<endl<<endl;
//	For(i,1,n)f[i]=Get(n,i);
//	For(i,1,n)cout<<f[i].x<<' ';cout<<endl<<endl;
////	For(i,1,n)cout<<f[i].s<<' ';cout<<endl<<endl;
//	For(i,1,Max){
//		int res=1,tot=1;
////		res=k[i-1]*t[k[i-1]-1];
//		FOR(j,i-1,0){
////			res*=(k[j]-tot);
//			res%=Mod;tot++;
////			cout<<res<<endl;
//		}res*=f[i].x;res%=Mod;
//		ans+=res*i;ans%=Mod;
//		cout<<i<<' '<<res<<endl<<endl;
//	}write(ans);
//	return 0;
//}
////Max?
