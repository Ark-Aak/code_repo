#include<bits/stdc++.h>
#define int long long
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
}
#define N 200005
#define Mod 1000000007
int n,m,ans;
int d[N];
signed main(){
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
    cin>>n>>m;
    For(i,1,m){
    	int u,v;
    	cin>>u>>v;
    	d[u]++,d[v]++;
	}
//	if(n<=2000){
		For(i,1,n)
		For(j,1,n)
		ans=(ans+((d[i]^d[j])*(d[i]|d[j])%Mod)*(d[i]&d[j])%Mod)%Mod;
		cout<<ans/2;
//	}
    return 0;
}
