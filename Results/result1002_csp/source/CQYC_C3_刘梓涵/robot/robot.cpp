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
#define N 200005
#define Mod 147744151
#define int long long
struct Rob{
        int p,q;
    }a[N];
int T,n,m;
int dep[N],f[N],dfn[N],siz[N],son[N],low[N],dfstime;
vector<int>e[N];
void clear(){
    For(i,1,n)e[i].clear();
    mem(dep,0),mem(f,0);mem(son,0);
}
void dfs1(int u){
    siz[u]=1;dep[u]=dep[f[u]]+1;
    dfn[u]=++dfstime;
    Fo(v,e[u]){
        if(v==f[u])continue;
        f[v]=u;dfs1(v);
        if(siz[son[u]]<siz[v])son[u]=v;
        siz[u]+=siz[v];
    }return;
}
void dfs2(int u,int l){
    low[u]=l;
    if(son[u])dfs2(son[u],l);
    Fo(v,e[u])
    if(v!=f[u]&&v!=son[u]){
        dfs2(v,v);
    }
}
int lca(int x,int y){
    while(low[x]!=low[y]){
        if(dep[low[x]]>dep[low[y]])
            swap(x,y);
        y=f[low[y]];
    }if(dep[x]>dep[y])swap(x,y);
    return x;
}
bool cnm(int a,int b,int x,int y){
    if(lca(a,b)==a&&lca(x,y)==x)return 1;
    if(lca(a,b)==b&&lca(x,y)==y)return 1;
    return 0;
}
bool rnm(int a,int b,int x,int y){
    if(lca(a,x)==x&&lca(b,y)==b)return 1;
    return 0;
}
bool check(Rob x,Rob y){
    int lx=lca(x.p,x.q);
    int ly=lca(y.p,y.q);
    if(lx==ly){
        if(cnm(x.p, y.p, x.q, y.q))return 1;
        if(cnm(x.p, y.q, x.q, y.p))return 1;
    }
    if(dep[lx]>dep[ly])
        swap(x,y),swap(lx,ly);
    if(ly==y.p||ly==y.q){
        if(ly==y.q)swap(y.p,y.q);//y.p==ly
        if(rnm(y.p,y.q,lx,x.p))return 1;
        if(rnm(y.p,y.q,lx,x.q))return 1;
    }
    return 0;
}
bool ccf(int x,Rob a){
    int l=lca(a.p,a.q);
    if(lca(x,l)==l){
        if(lca(x,a.p)==x)return 1;
        if(lca(x,a.q)==x)return 1;
    }return 0;
}
bool checkJJ(Rob x,Rob y){
    if(ccf(x.q,y)&&ccf(y.q,x))return 1;
    if(ccf(x.p,y)&&ccf(y.p,x))return 1;
    return 0;
}
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
    read(T);
    while(T--){
        int kkk=0;
        clear();//****
        read(n);
        FoR(i,1,n){
            int u,v;
            read(u),read(v);
            e[u].PB(v),e[v].PB(u);
        }
        dfs1(1),dfs2(1,1);
//        cout<<lca(3,4)<<endl;
        read(m);
        For(i,1,m){
            read(a[i].p);
            read(a[i].q);
            cout<<lca(a[i].p,a[i].q)<<endl;
        }
        For(i,1,m){
            if(kkk)break;
            For(j,i+1,m){
                if(kkk)break;
                if(check(a[i],a[j])||checkJJ(a[i],a[j])){
                    kkk=1;
                    puts("No");
                    break;
                }
            }
        }
        if(!kkk)puts("Yes");
    }
    return 0;
}
/*
1
10
1 2
2 3
3 4
3 5
2 6
6 7
4 8
7 9
8 10
3
9 4
1 6
3 1
*/
