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
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define N 1005
#define Mod (1<<32)
int n,m,c,ans;
int h[N],f[N][10005];
int k[N][10005];
vector<int>a[N];
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	read(n),read(m),read(c);
	For(i,1,n)read(h[i]);
	For(i,1,m){
		int u,v;
		read(u),read(v);
//		a[u].PB(v);
		a[v].PB(u);
	}k[1][0]=1;
	For(t,1,5000){
		For(i,1,n){
			Fo(j,a[i])
				if(k[j][t-1])
				f[i][t]=max(f[i][t],f[j][t-1]+h[i]),k[i][t]=1;
		}ans=max(ans,f[1][t]-(c*t*t));
	}
//	For(i,1,10)cout<<f[1][i]<<" ";cout<<endl;
	cout<<ans;
    return 0;
}
