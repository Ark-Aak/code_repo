#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;
int r[1000005],s[1000005];
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	int n,m,k;
	n=in,m=in,k=in;
	for(int i=1;i<=1e6;i++) r[i]=1;
	for(int i=1;i<=1e6;i++) s[i]=1;
	for(int i=1;i<=k;i++) {
		char c;
		int x,y;
		cin>>c;
		x=in,y=in;
		if(c=='R') r[x]=(r[x]*y)%mod;
		else s[x]=(s[x]*y)%mod;
	}
	int cnt=0,w=1,sum=0,ans=0;
	for(int i=1;i<=n;i++) cnt=(cnt+w*r[i])%mod,w=(w+m)%mod;
	for(int i=1;i<=n;i++) sum=(sum+r[i])%mod;
	for(int i=1;i<=m;i++) {
		ans=(ans+cnt*s[i])%mod;
		cnt=(cnt+sum)%mod;
	}
	printf("%lld",ans);
	return 0;
}

