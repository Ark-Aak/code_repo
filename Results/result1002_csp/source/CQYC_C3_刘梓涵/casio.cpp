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
#define N 30050005
#define Mod 147744151
//#define int long long
int Q,P,tot;
int p[N],k[N],m[N];
vector<int>ans;
inline void E(int n){
    k[0]=k[1]=0;
    For(i,2,n){
        if(!k[i])p[++tot]=i;
        for(int j=1;j<=tot&&(long long)(p[j]*i)<=n;++j){
            k[i*p[j]]=1;m[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}
signed main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
    read(Q);read(P);
    E(N-5);
    For(i,2,N-5)
    if(!k[i]||m[i]>P)
        ans.PB(i);
    while(Q--){
        int n,s;
        read(n);
        s=lower_bound(ans.begin(),ans.end(),n)-ans.begin();
        write(ans[s]);puts("");
    }
    return 0;
}
