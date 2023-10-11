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
#define N 1000005
#define Mod 1000000007
#define int long long
struct Query{
	int x,i;
}x[1005],y[1005];
int n,m,k,totx,toty,ans;
int a[N],b[N];
int r[N],s[N];
int ksm(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%Mod;
		a=a*a%Mod;
		b>>=1;
	}return res;
}
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	int inv2=ksm(2,Mod-2);
	read(n),read(m),read(k);
	For(i,1,max(n,m))r[i]=1,s[i]=1;
	a[1]=(1+m)*m%Mod*inv2%Mod;ans=a[1];
	b[1]=(1+(n-1)*m%Mod+1)*n%Mod*inv2%Mod;
	For(i,2,n){
		a[i]=(a[i-1]+m*m%Mod)%Mod;
		ans=(ans+a[i])%Mod;
	}
	For(i,2,m)b[i]=(b[i-1]+n)%Mod;
	For(i,1,k){
		char opt;
		int xx,yy;
		scanf("%c",&opt);
		read(xx),read(yy);
		if(opt=='R')r[xx]=r[xx]*yy%Mod;
		else s[xx]=s[xx]*yy%Mod;
	}
	For(i,1,n)
	if(r[i]!=1)
		x[++totx].x=r[i],
		x[totx].i=i;
	For(i,1,m)
	if(s[i]!=1)
		y[++toty].x=s[i],
		y[toty].i=i;
//	cout<<totx<<' '<<toty<<endl;
//	cout<<ans<<endl;
	For(i,1,totx)ans=(ans-a[x[i].i]+a[x[i].i]*x[i].x+Mod)%Mod;
	For(i,1,toty)ans=(ans-b[y[i].i]+b[y[i].i]*y[i].x+Mod)%Mod;
//	cout<<ans<<endl;
	For(i,1,totx)
	For(j,1,toty){
		int now=(x[i].i-1)*m%Mod+y[j].i;now%=Mod;
//		cout<<x[i].i<<' '<<y[i].i<<" "<<now<<endl;
//		if(!x[i].x||!y[j].x)ans=(ans-(max(x[i].x,y[j].x)-1)*now%Mod+Mod)%Mod;
		ans=(ans-now*x[i].x%Mod-now*y[j].x%Mod+now+x[i].x*y[j].x%Mod*now%Mod+2*Mod)%Mod;
	}
	write(ans);puts("");
//	cout<<n<<' '<<m<<" "<<k<<endl;
//	For(i,1,n)cout<<a[i]<<' ';cout<<endl;
//	For(i,1,n)cout<<r[i]<<' ';cout<<endl;
//	For(i,1,m)cout<<b[i]<<' ';cout<<endl;
//	For(i,1,m)cout<<s[i]<<' ';cout<<endl;
	return 0;
}

