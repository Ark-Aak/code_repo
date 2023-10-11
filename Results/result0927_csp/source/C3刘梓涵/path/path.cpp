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
#define Mod 998244353
int n,t,ans=1e16;
int a[N],s[N],f[N][N];
signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
    mem(f,0x3f);
    read(n);read(t);
    For(i,1,n)read(a[i]);
    For(i,1,n)s[i]=s[i-1]+a[i];
    For(i,1,n)
    For(j,0,t){
        int Max=a[i];
        if(j==0){
            For(k,1,i)Max=max(a[k],Max);
            f[i][j]=Max*i-s[i];
            continue;
        }
        FOR(k,i-1,1){
            f[i][j]=min(f[i][j],f[k][j-1]+Max*(i-k)-(s[i]-s[k]));
            Max=max(Max,a[k]);
        }
    }
    For(i,0,t)ans=min(ans,f[n][i]);
    cout<<ans;
    return 0;
}
