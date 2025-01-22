#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int N=5e5+5;
int t[N<<2],mn[N<<2],laz[N<<2];
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)

void build(int x,int l,int r){
    if(l==r){
        t[x]=mn[x]=l;
        return;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    t[x]=max(t[ls],t[rs]);
    mn[x]=min(mn[ls],mn[rs]);
}
inline void down(int x,int k){
    t[x]+=k;
    mn[x]+=k;
    laz[x]+=k;
}
void pushdown(int x){
    down(ls,laz[x]);
    down(rs,laz[x]);
    laz[x]=0;
}

int query_L(int x,int l,int r,int k){
    if(l==r) return l;
    pushdown(x);
    if(t[ls]>=k) return query_L(ls,l,mid,k);
    else return query_L(rs,mid+1,r,k);
}
int query_R(int x,int l,int r,int k){
    if(l==r) return l;
    pushdown(x);
    if(mn[rs]<=k) return query_R(rs,mid+1,r,k);
    else return query_R(ls,l,mid,k);
}
void update(int x,int l,int r,int L,int R,int k){
    if(l>=L&&r<=R){
        down(x,k);
        return;
    }
    pushdown(x);
    if(L<=mid) update(ls,l,mid,L,R,k);
    if(R>mid) update(rs,mid+1,r,L,R,k);
    t[x]=max(t[ls],t[rs]);
    mn[x]=min(mn[ls],mn[rs]);
}
int query(int x,int l,int r,int k){
    if(l==r) return t[x];
    pushdown(x);
    if(k<=mid) return query(ls,l,mid,k);
    return query(rs,mid+1,r,k);
}
int n;
signed main(){
    n=read();
    build(1,1,N-5);
    for(int i=1;i<=n;i++){
        int l=read(),r=read();
        int L=query_L(1,1,N-5,l),R=query_R(1,1,N-5,r);
        if(L<=R) update(1,1,N-5,L,R,1);
    }
    int Q=read();
    while(Q--){
        int x=read();
        printf("%lld\n",query(1,1,N-5,x));
    }
    return 0;
}
