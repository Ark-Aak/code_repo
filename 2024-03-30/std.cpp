
#include<bits/stdc++.h>
#define ll long long
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
    void print(_Tp x) {
        if(x<0) x=(~x+1),putchar('-');
        if(x>9) print(x/10);
        putchar(x%10+'0');
    }
}
using namespace std;
using namespace IO;
const int N=2.5e5+5,Inf=1e9;
int n,k,b[N],Rt[N],c[N],len;
ll a[N];
struct Sgt_tree {
    #define mid ((l+r)>>1)
    ll sum[N*80];
    int cnt[N*80],ls[N*80],rs[N*80],tot=0;
    void modify(int rt,int &x,int l,int r,int pos) {
        x=++tot;
        sum[x]=sum[rt]; cnt[x]=cnt[rt];
        ls[x]=ls[rt]; rs[x]=rs[rt];
        if(l==r) {
            sum[x]+=c[pos];
            cnt[x]++;
            return ;
        }
        if(pos<=mid) modify(ls[rt],ls[x],l,mid,pos);
        else modify(rs[rt],rs[x],mid+1,r,pos);
        sum[x]=(sum[ls[x]]+sum[rs[x]]);
        cnt[x]=(cnt[ls[x]]+cnt[rs[x]]);
    }
    ll query(int A,int B,int l,int r,int K) {
        if(l==r) return min(cnt[A]-cnt[B],K)*c[l];
        int res=cnt[rs[A]]-cnt[rs[B]];
        if(res<K) return sum[rs[A]]-sum[rs[B]]+query(ls[A],ls[B],l,mid,K-res);
        else return query(rs[A],rs[B],mid+1,r,K);
    }
    int querykth(int A,int B,int l,int r,int K) {
        if(l==r) return l;
        int res=cnt[rs[A]]-cnt[rs[B]];
        if(res<K) return querykth(ls[A],ls[B],l,mid,K-res);
        else return querykth(rs[A],rs[B],mid+1,r,K);
    }
}T;
struct SgtTree2 {
    #define ls ((x<<1))
    #define rs ((x<<1)|1)
    #define mid ((l+r)>>1)
    int laz[N<<2];
    void build(int x,int l,int r) {
        laz[x]=1e9;
        if(l==r) return ;
        build(ls,l,mid); build(rs,mid+1,r);
    }
    void pushdown(int x) {
        laz[ls]=min(laz[ls],laz[x]);
        laz[rs]=min(laz[rs],laz[x]);
        laz[x]=1e9;
    }
    void modify(int x,int l,int r,int L,int R,int pos) {
        if(L<=l && r<=R) {
            laz[x]=min(laz[x],pos);
            return ;
        }
        if(laz[x]<1e9) pushdown(x);
        if(L<=mid) modify(ls,l,mid,L,R,pos);
        if(mid<R) modify(rs,mid+1,r,L,R,pos);
    }
    int query(int x,int l,int r,int pos) {
        if(l==r) return laz[x];
        if(laz[x]<1e9) pushdown(x);
        if(pos<=mid) return query(ls,l,mid,pos);
        else return query(rs,mid+1,r,pos);
    }
}S;
int kth=0;
ll Maxn[N],ans=-1e18;
vector<int> pos[N];
void solve(int l,int r,int ql,int qr) {
    if(l>r) return ;
    int p=0; Maxn[mid]=-1e18;
    for(int i=max(mid+k-1,ql);i<=qr;i++) {
        ll Val=T.query(Rt[i],Rt[mid-1],1,Inf,k);
        if(1ll*Val-(a[i]-a[mid-1])>Maxn[mid]) {
            Maxn[mid]=Val-(a[i]-a[mid-1]);
            pos[mid].clear();
        }
        if(1ll*Val-(a[i]-a[mid-1])==Maxn[mid]) pos[mid].push_back(i),p=i;
    }
    ans=max(ans,Maxn[mid]);
    solve(l,mid-1,ql,p);
    solve(mid+1,r,p,qr);
}
signed main() {
#ifndef KAxdd
#ifndef ONLINE_JUDGE
    /* freopen("sequence.in","r",stdin); */
    /* freopen("sequence.out","w",stdout); */
#endif
#endif
    read(n,k);
    for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1];
    for(int i=1;i<=n;i++) read(b[i]),c[i]=b[i];
    sort(c+1,c+n+1);
    len=unique(c+1,c+n+1)-c-1;
    for(int i=1;i<=n;i++) b[i]=lower_bound(c+1,c+len+1,b[i])-c;
    for(int i=1;i<=n;i++) T.modify(Rt[i-1],Rt[i],1,Inf,b[i]);
    solve(1,n-k+1,1,n);
    S.build(1,1,n);
    for(int i=1;i<=n;i++) {
        if(Maxn[i]<ans) continue;
        for(auto j:pos[i]) {
			cout << i << " " << j << " " << T.querykth(Rt[j], Rt[i - 1], 1, Inf, k) << endl;
            S.modify(1,1,n,i,j,T.querykth(Rt[j],Rt[i-1],1,Inf,k));
        }
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) {
        if(b[i]>=S.query(1,1,n,i)) printf("1");
        else printf("0");
    }
    return 0;
}
/*
5 3
3 5 2 3 6
2 1 5 2 3
*/
