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
#define FoR(i,j,k) for(int i=j;i^(k);++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
#define int long long
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
#define Mod 998244353
int n,m,ans=inf;
int a[55][55],s[55];
char J[55][55];
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	read(n),read(m);
	For(i,1,n)cin>>J[i]+1;
	For(i,1,n)
	For(j,1,m){
		if(J[i][j]=='1')a[i][j]=1;
	}
	For(i,1,n)
	For(j,1,m)
		if(a[j][i])
		s[i]|=1<<j-1;
	FoR(i,0,1<<n){
		int res=0;
		For(j,1,m){
			int sum=__builtin_popcount(s[j]^i);
			res+=min(sum,n-sum);
		}ans=min(ans,res);
	}write(ans);
	return 0;
}

