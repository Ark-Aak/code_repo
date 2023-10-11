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
#define N 500005
#define Mod 147744151
#define int long long
struct Node{
        int l,r;
    }a[N];
int n,m,Q;
int x[N],k[N];
struct SegmentTr{
    int t[N<<2];
    void Modify(int x,int l,int r,int L,int R,int v){
        if(L<=l&&r<=R){
            t[x]+=v;
            return ;
        }
        if(L<=mid)Modify(ls,l,mid,L,R,v);
        if(R>mid)Modify(rs,mid+1,r,L,R,v);
        t[x]=t[ls]+t[rs];
    }
    int Query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[x];
        int res=0;
        if(L<=mid)res+=Query(ls,l,mid,L,R);
        if(R>mid)res+=Query(rs,mid+1,r,L,R);
        return res;
    }
}T;
signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);	
    read(n),read(Q);
    For(i,1,n)read(a[i].l),read(a[i].r);
//    sort(a+1,a+1+n,cmp);
    while(Q--){
        int ans=0;
        read(m);
        For(i,1,m)read(x[i]),T.Modify(1,1,n,x[i],x[i],1);
        For(i,1,n)
            if(T.Query(1,1,n,a[i].l,a[i].r)%2==1)
				ans++;
        printf("%lld\n",ans);
        For(i,1,m)T.Modify(1,1,n,x[i],x[i],-1);
    }
    return 0;
}
/*
2
3 5 7
6 5 10
8 6 3
9 7 8

1
-4 5 6
-3 -3 3
 */
/*
5 2
4 5
3 5
2 4
1 3
5 5
4
1 2 3 4
1
4

5 2
4 5
3 5
2 4
2 3
5 5
2
2 5
3
1 2 5
*/
