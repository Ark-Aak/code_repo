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
#define int long long
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
int n,sum;
int f[N],g[N],ans[N];
int ff[N],gg[N],ss[N];
int siz[N];
vector<int>a[N];
void dfs1(int u,int fa){
    siz[u]=1;
    Fo(v,a[u]){
        if(v==fa)continue;
        dfs1(v,u);
        siz[u]+=siz[v];
    }return ;
}
void dfs2(int u,int fa){
//    f[u]=u;
	g[u]=siz[u]*(siz[u]-1);
    Fo(v,a[u]){
        if(v==fa)continue;
        dfs2(v,u);
        g[u]-=(siz[v]+1)*siz[v];
    }
    Fo(v,a[u])if(v!=fa)
        f[u]+=f[v]+v*g[v]/2;
	f[u]+=u*(siz[u]-1);
    return ;
}
//g_u=\sum_v (siz_u-siz_v-1)*siz_v
//f_u=\sum_v f_v+v*g_v/2+u*siz_v
void solve(int u,int fa){
//    if(u!=1&&u!=2)return;
//    if(u==5)cout<<siz[fa]<<endl;

    if(u!=1){
        int y=fa,x=u;
        g[y]-=siz[x]*(siz[y]-1);
//        cout<<g[y]<<' '<<siz[x]*(siz[y]-1)<<endl;

        g[y]-=(siz[y]-siz[x])*siz[x];
        g[y]+=(siz[x]+1)*siz[x];
//        cout<<g[y]<<' '<<siz[x]*(siz[y]-siz[x]-1)*siz[x]<<endl;

        f[y]-=f[x]+x*g[x]/2;
        f[y]-=y*siz[x];

        int sx=siz[x];
        siz[y]-=siz[x];
        siz[x]+=siz[y];
//        g[x]+=(siz[x]-siz[y]-1)*siz[y];
        g[x]-=sx*(sx-1);
        g[x]+=siz[x]*(siz[x]-1);
        g[x]-=siz[y]*(siz[y]+1);

        f[x]+=f[y]+y*g[y]/2;
        f[x]+=x*siz[y];
        ans[x]=(f[x]+x*g[x]/2)*2+sum;
    }
//    if(u==2)cout<<ans[2]<<' '<<g[2]<<' '<<f[2]<<' '<<siz[2]<<endl;
//    if(u==5)cout<<ans[5]<<' '<<g[5]<<' '<<f[5]<<' '<<siz[5]<<endl;
    //siz_x siz_y fx fy gx gy
    Fo(v,a[u]){
        if(v==fa)continue;
        int ffu=f[u],ggu=g[u],ssu=siz[u];
        int ffv=f[v],ggv=g[v],ssv=siz[v];
        solve(v,u);
        f[u]=ffu;f[v]=ffv;
        g[u]=ggu;g[v]=ggv;
        siz[u]=ssu;siz[v]=ssv;
    }
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
    read(n);
    FoR(i,1,n){
        int u,v;
        read(u),read(v);
        a[u].PB(v),a[v].PB(u);
    }sum=(1+n)*n/2;
    dfs1(1,0);
    dfs2(1,0);
    ans[1]=(f[1]+1*g[1]/2)*2+sum;

//    cout<<ans[1]<<" "<<g[1]<<' '<<f[1]<<" "<<siz[1]<<endl;
    /*
    dfs1(5,0);
    dfs2(5,0);
    ans[5]=(f[5]+5*g[5]/2)*2+sum;
//    For(i,1,n)cout<<f[i]<<endl;
    cout<<ans[2]<<' '<<g[2]<<' '<<f[2]<<' '<<siz[2]<<endl;
    cout<<ans[5]<<' '<<g[5]<<" "<<f[5]<<' '<<siz[5]<<endl;
    */


    
    For(i,1,n)ff[i]=f[i];
    For(i,1,n)gg[i]=g[i];
    For(i,1,n)ss[i]=siz[i];
//    Fo(v,a[1])
    solve(1,0);
//    For(i,1,n)cout<<ans[i]<<endl;
//    cout<<ans[1]<<' '<<g[1]<<' '<<f[1]<<' '<<siz[1]<<endl;
//    cout<<ans[2]<<' '<<g[2]<<" "<<f[2]<<' '<<siz[2]<<endl;
    For(i,1,n)write(ans[i]),putchar(' ');
    
    return 0;
}
