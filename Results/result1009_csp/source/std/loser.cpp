#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Node{int v,nt;};

struct Info
{
    int sum,mn;
    Info(int sum=0,int mn=0):sum(sum),mn(mn){}
};

struct Splay
{
    Info val[2],el[2];
    int tag;
};

Info res,ans,ans1,ans2;
Splay tr[400005];
Node pl[200005];
int hd[100005],cnt;
int w[100005],dfn[100005],idfn[100005],dft,len;
int siz[100005],son[100005],dep[100005],f[100005],top[100005];
int n,q;

inline void add(int u,int v)
{
    pl[++cnt].nt=hd[u];
    pl[cnt].v=v;
    hd[u]=cnt;
}

inline void dfs(int u,int fa)
{
    f[u]=fa;
    dep[u]=dep[fa]+1;
    siz[u]=1;

    for(int i=hd[u];i;i=pl[i].nt)
    {
        int v=pl[i].v;

        if(v==fa)
            continue;

        dfs(v,u);

        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])
            son[u]=v;
    }
}

inline void getdfn(int u,int fa)
{
    dfn[u]=++dft;
    idfn[dft]=u;
    
    if(son[fa]==u)
        top[u]=top[fa];
    else
        top[u]=u;

    if(son[u])
        getdfn(son[u],u);

    for(int i=hd[u];i;i=pl[i].nt)
    {
        int v=pl[i].v;

        if(v==fa||v==son[u])
            continue;

        getdfn(v,u);
    }
}

inline int lc(int k){return k<<1;}

inline int rc(int k){return k<<1|1;}

inline Info update(Info x,Info y,int op)
{
    if(op)
        swap(x,y);
    return Info(x.sum+y.sum,min(x.mn,x.sum+y.mn));
}

inline void combine(int k)
{
    tr[k].val[0]=update(tr[lc(k)].val[0],tr[rc(k)].val[0],0);
    tr[k].val[1]=update(tr[lc(k)].val[1],tr[rc(k)].val[1],1);
    tr[k].el[0]=update(tr[lc(k)].el[0],tr[rc(k)].el[0],0);
    tr[k].el[1]=update(tr[lc(k)].el[1],tr[rc(k)].el[1],1);
}

inline void build(int k,int l,int r)
{
    if(l==r)
    {
        tr[k].val[0]=tr[k].val[1]=Info(w[idfn[l]],min(0,w[idfn[l]]));
        tr[k].el[0]=tr[k].el[1]=Info(-w[idfn[l]],min(0,-w[idfn[l]]));

        return;
    }

    int mid=(l+r)>>1;

    build(lc(k),l,mid);
    build(rc(k),mid+1,r);

    combine(k);
}

inline void pushdown(int k)
{
    if(!tr[k].tag)
        return;

    tr[lc(k)].tag^=1;
    swap(tr[lc(k)].val[0],tr[lc(k)].el[0]);
    swap(tr[lc(k)].val[1],tr[lc(k)].el[1]);

    tr[rc(k)].tag^=1;
    swap(tr[rc(k)].val[0],tr[rc(k)].el[0]);
    swap(tr[rc(k)].val[1],tr[rc(k)].el[1]);

    tr[k].tag=0;
}

inline void flip(int k,int l,int r,int ql,int qr)
{
    if(ql<=l&&r<=qr)
    {
        tr[k].tag^=1;
        swap(tr[k].val[0],tr[k].el[0]);
        swap(tr[k].val[1],tr[k].el[1]);

        return;
    }

    pushdown(k);

    int mid=(l+r)>>1;

    if(ql<=mid)
        flip(lc(k),l,mid,ql,qr);
    if(mid<qr)
        flip(rc(k),mid+1,r,ql,qr);

    combine(k);
}

inline void query(int k,int l,int r,int ql,int qr,int op)
{
    if(ql<=l&&r<=qr)
    {
        res=update(res,tr[k].val[op],op);

        return;
    }

    pushdown(k);

    int mid=(l+r)>>1;

    if(ql<=mid)
        query(lc(k),l,mid,ql,qr,op);
    if(mid<qr)
        query(rc(k),mid+1,r,ql,qr,op);
}

int main()
{
    freopen("loser.in","r",stdin);
    freopen("loser.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin>>n>>q;

    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;

        add(u,v);
        add(v,u);
    }

    for(int i=1;i<=n;i++)
    {
        cin>>w[i];
        w[i]=1-(w[i]<<1);
    }

    dfs(1,0);
    getdfn(1,0);

    build(1,1,n);

    while(q--)
    {
        int op,x,y;
        cin>>op>>x>>y;

        len=dep[x]+dep[y];

        if(op==1)
        {
            while(top[x]!=top[y])
            {
                if(dep[top[x]]<dep[top[y]])
                    swap(x,y);

                flip(1,1,n,dfn[top[x]],dfn[x]);
                x=f[top[x]];
            }

            if(dep[x]<dep[y])
                swap(x,y);

            flip(1,1,n,dfn[y],dfn[x]);
        }
        
        if(op==2)
        {
            ans1=ans2=Info();

            while(top[x]!=top[y])
            {
                if(dep[top[x]]>dep[top[y]])
                {
                    res=Info();
                    query(1,1,n,dfn[top[x]],dfn[x],1);
                    ans1=update(ans1,res,0);
                    x=f[top[x]];
                }
                else
                {
                    res=Info();
                    query(1,1,n,dfn[top[y]],dfn[y],0);
                    ans2=update(ans2,res,1);
                    y=f[top[y]];
                }
            }

            if(dep[x]>dep[y])
            {
                res=Info();
                query(1,1,n,dfn[y],dfn[x],1);
                ans1=update(ans1,res,0);
                len-=dep[y]+dep[y]-1;
            }
            else
            {
                res=Info();
                query(1,1,n,dfn[x],dfn[y],0);
                ans2=update(ans2,res,1);
                len-=dep[x]+dep[x]-1;
            }

            ans=update(ans1,ans2,0);

            len+=ans.mn;
            ans.sum-=ans.mn;
            len-=ans.sum;

            cout<<len<<'\n';
        }
    }

    return 0;
}