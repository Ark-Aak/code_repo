#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
#define ls(x) ((x<<1))
#define rs(x) ((x<<1)|1)
#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

namespace IO{
    template<typename T>
    void read(T &x){
        char ch=getchar();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getchar();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    template <typename _Tp>
    void write(_Tp x) {
        if(x<0) x=(~x+1),putchar('-');
        if(x>9) write(x/10);
        putchar(x%10+'0');
    }
}
using namespace std;
using namespace IO;
const int N=2e6+5,mod=998244353,KAddx=114;
int  n,vax[N];
int ans=0;
struct SGT1{
int mn[N],mx[N],lz1[N],lz2[N],tr[N],lz[N];
inline void pushup(int x){
    mn[x]=min(mn[ls(x)],mn[rs(x)]);
    mx[x]=max(mx[ls(x)],mx[rs(x)]);
    tr[x]=tr[ls(x)]+tr[rs(x)];
}
void build(int x,int l,int r){
	lz1[x]=1e18;lz2[x]=-1e18;
	if(l==r){mn[x]=mx[x]=tr[x]=vax[l];return;}
	int mid=(l+r)>>1;
	build(ls(x),l,mid);build(rs(x),mid+1,r);
    pushup(x);
}
inline void down1(int x,int l,int r,int k){
	lz1[x]=k;lz2[x]=-1e18;
    mn[x]=mx[x]=k;
    tr[x]=(r-l+1)*k;
}
inline void down2(int x,int l,int r,int k){
	lz2[x]=k;lz1[x]=1e18;
    mx[x]=mn[x]=k;
    tr[x]=(r-l+1)*k;
}
inline void pushdown(int x,int l,int r){
	int mid=(l+r)>>1;
	if(lz1[x]!=1e18){
		down1(ls(x),l,mid,lz1[x]);
		down1(rs(x),mid+1,r,lz1[x]);
		lz1[x]=1e18;
	}
	if(lz2[x]!=-1e18){
		down2(ls(x),l,mid,lz2[x]);
		down2(rs(x),mid+1,r,lz2[x]);
		lz2[x]=-1e18;
	}
}
void upd1(int x,int l,int r,int L,int R,int k){
	pushdown(x,l,r);
	if(mx[x]<k) return;
	if(mn[x]>=k&&L<=l&&r<=R){
ans+=abs(tr[x]-(r-l+1)*k);down1(x,l,r,k);return;}
	int mid=(l+r)>>1;
	if(L<=mid)upd1(ls(x),l,mid,L,R,k);
	if(R>mid)upd1(rs(x),mid+1,r,L,R,k);
	pushup(x);
}
void upd2(int x,int l,int r,int L,int R,int k){
	pushdown(x,l,r);
	if(mn[x]>k) return;
	if(mx[x]<=k&&L<=l&&r<=R){
	ans+=abs(tr[x]-(r-l+1)*k);down2(x,l,r,k);return;}
	int mid=(l+r)>>1;
	if(L<=mid)upd2(ls(x),l,mid,L,R,k);
	if(R>mid)upd2(rs(x),mid+1,r,L,R,k);
	pushup(x);
}
}t1;
signed main(){
	read(n);
	for(int i=1;i<=n;i++) read(vax[i]),vax[i]=vax[i]-i;
	t1.build(1,1,n);
	int Q;ans=0; read(Q);
	while(Q--){
		int t,g;read(t,g);
		t1.upd1(1,1,n,1,t,g-t);
		t1.upd2(1,1,n,t,n,g-t);
	}
	printf("%lld\n",ans);
	return 0;
}
