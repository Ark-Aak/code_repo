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
#define Mod 998244353
#define int long long
int n,m,s,l,cnt,ans,f[2][N];
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	f[0][1]=1;l=1;
	For(i,1,n){
		For(j,1,m){
			f[i&1][j]=l;
			for(int k=j+j;k<=m;k+=j)
				f[i&1][j]=(f[i&1][j]-f[i-1&1][k]+Mod)%Mod;
			s+=f[i&1][j];
			s%=Mod;
		}l=s;s=0;
//		cout<<i<<':'<<endl;
//		For(j,1,m)cout<<f[i&1][j]<<' ';
//		cout<<endl;
	}
	For(i,1,m)ans=(ans+f[n&1][i])%Mod;
	write(ans);
	return 0;
}

