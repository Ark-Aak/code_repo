#include<bits/stdc++.h>
#define db doub
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
#define N 1000005
#define Mod 1000000007
int n,top;
int a[N],l[N],r[N],st[N];
signed main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
    read(n);
    For(i,1,n)read(a[i]);
    For(i,1,n){
        while(a[i]>=a[st[top]]&&top>0)top--;
        l[i]=st[top]+1;st[++top]=i;
    }top=0;
    FOR(i,n,1){
        while(a[i]>=a[st[top]]&&top>0)top--;
        if(top)r[i]=st[top]-1;
        else r[i]=n;
        st[++top]=i;
    }
    For(i,1,n)cout<<r[i]-l[i]<<endl;
    return 0;
}
