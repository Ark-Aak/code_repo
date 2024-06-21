#include <bits/stdc++.h>
#define pii pair<int,int>
#define rg register
#define me(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define FOR(i,k,t,p) for(rg int i(k) ; i <= t ; i += p)
#define ROF(i,k,t,p) for(rg int i(k) ; i >= t ; i -= p)
using namespace std ;
const int N = 5e5+5 ;
int n,m,q,p,w,top,pos,las ;
signed rt[N] ;
int base = 147744151,pw[N],ppw[N] ;
vector<int>a[N],que ;
struct Node{signed l,r;int h1,w,base,tag ;}tr[N*20] ;
#define w(x) tr[x].w
#define h1(x) tr[x].h1
#define tag(x) tr[x].tag
#define base(x) tr[x].base
#define mid (le+ri>>1)
#define fin cin
#define fout cout
inline void update(int x,int le,int ri)
{
    w(x) = (0ll+w(tr[x].l)+w(tr[x].r))%p ;
    h1(x) = (1ll*h1(tr[x].l)*base(tr[x].r)%p+h1(tr[x].r))%p,base(x) = 1ll*base(tr[x].l)*base(tr[x].r)%p ;
}
inline void down(int x,int le,int ri)
{
    if(!tag(x)) return ;
    w(tr[x].l) = (w(tr[x].l)+1ll*(mid-le+1)*tag(x)%p)%p,w(tr[x].r) = (w(tr[x].r)+1ll*(ri-mid)*tag(x)%p)%p ;
    tag(tr[x].l) = (0ll+tag(x)+tag(tr[x].l))%p,tag(tr[x].r) = (0ll+tag(x)+tag(tr[x].r))%p ;
    h1(tr[x].l) = (h1(tr[x].l)+1ll*pw[mid-le+1]*tag(x)%p)%p,h1(tr[x].r) = (h1(tr[x].r)+1ll*pw[ri-mid]*tag(x)%p)%p,tag(x) = 0 ;
}
inline pii Add(pii x,pii y) {return {(1ll*x.first*y.second%p+y.first)%p,1ll*x.second*y.second%p} ;} ;
void Build(signed &x,int le = 1,int ri = n)
{
    x = ++top ; if(le == ri)
    {
        w(x) = h1(x) = a[pos][le],base(x) = base ; return ;
    }
    Build(tr[x].l,le,mid),Build(tr[x].r,mid+1,ri),update(x,le,ri) ;
}
void Modify(int x,int k,int L,int R,int le = 1,int ri = n)
{
    if(le >= L && ri <= R) {w(x) = (w(x)+1ll*k*(ri-le+1)%p)%p,tag(x) = (0ll+tag(x)+k)%p,h1(x) = (h1(x)+1ll*k*pw[ri-le+1]%p)%p ; return ;} down(x,le,ri) ;
    if(L <= mid) Modify(tr[x].l,k,L,R,le,mid) ; if(mid < R) Modify(tr[x].r,k,L,R,mid+1,ri) ; update(x,le,ri) ;
}
void Swap(signed &x,signed &y,int L,int R,int le = 1,int ri = n)
{
    // print(x,y,le,ri,L,R),enter ; if(!x) return ;
    if(le >= L && ri <= R) {swap(x,y) ; return ;} down(x,le,ri),down(y,le,ri) ;
    if(L <= mid) Swap(tr[x].l,tr[y].l,L,R,le,mid) ; if(mid < R) Swap(tr[x].r,tr[y].r,L,R,mid+1,ri) ; update(x,le,ri),update(y,le,ri) ;
}
int Queryw(int x,int L,int R,int le = 1,int ri = n)
{
    if(le >= L && ri <= R) return w(x) ; down(x,le,ri) ; int res = 0 ;
    if(L <= mid) res = Queryw(tr[x].l,L,R,le,mid) ; if(mid < R) res = (0ll+res+Queryw(tr[x].r,L,R,mid+1,ri))%p ; update(x,le,ri) ; return res ;
}
pii Queryh1(int x,int L,int R,int le = 1,int ri = n)
{
    // print(L,R,le,ri),enter ;
    if(le >= L && ri <= R) {return {h1(x),base(x)} ;} ; down(x,le,ri) ; pii res = {0,1} ;
    if(L <= mid) res = Queryh1(tr[x].l,L,R,le,mid) ; if(mid < R) res = Add(res,Queryh1(tr[x].r,L,R,mid+1,ri)) ; update(x,le,ri) ; return res ;
}
void Solve(){
    int op,l,r,x,y,k ; fin>>op ;
    if(op == 1) fin>>x>>l>>r,fout<<Queryw(rt[x],l,r)<<'\n';
    if(op == 2)
    {
    	fin>>x>>l>>r>>k;

		if (r - l + 1 <= k) return fout << "infinity loop!\n"s, void();

        if(Queryw(rt[x],l,l+k-1) != Queryw(rt[x],l+k,l+k)) fout<<"infinity loop!\n"s ;
        else
        {
            if(l+k == r) {fout<<"where is self?\n"s ; return ;}
           int chk = Queryh1(rt[x],l,r-k-1).first == (2ll*Queryh1(rt[x],l+k,r-1).first-Queryh1(rt[x],l+k+1,r).first+p)%p ;
           fout<<(chk ? "where is self?\n"s : "infinity loop!\n"s) ;
        }
    }
    if(op == 3) fin>>x>>l>>r>>k,Modify(rt[x],k,l,r) ;
    if(op == 4) fin>>x>>y>>l>>r,Swap(rt[x],rt[y],l,r) ;
}
signed main()
{
	fin>>n>>m>>q>>p;
    FOR(i,1,m,1)
    {
        a[i].resize(n+5) ;
        FOR(j,1,n,1) fin>>a[i][j] ;
    }
    ppw[0] = 1 ;
    FOR(i,1,n,1) pw[i] = (1ll*pw[i-1]*base+1)%p,ppw[i] = 1ll*ppw[i-1]*base%p ;
    FOR(i,1,m,1) pos = i,Build(rt[i]) ; while(q--) Solve() ;
    return 0 ;
}
