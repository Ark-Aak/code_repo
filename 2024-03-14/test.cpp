#include<bits/stdc++.h>

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
}
using namespace std;
using namespace IO;
const int N=1e6+5;
string s,t,p;
int ls,lt,lp,ans[N],Oth;
vector<pair<int,int> > e[N];
vector<int> Q1[N],Q2[N];
struct Kmp{
    int nxt[N],sum[N],flg[N],lst[N];
    string s,t,p;
    int init() {
        int j=0;
        for(int i=2;i<=lp;i++) {
            while(j && p[i]!=p[j+1]) j=nxt[j];
            if(p[i]==p[j+1]) j++;
            nxt[i]=j;
        }
        j=0;
        for(int i=1;i<=lt;i++) {
            while((j==lp) || (j && t[i]!=p[j+1])) j=nxt[j];
            if(t[i]==p[j+1]) j++;
            if(j==lp) Oth++;
        }
        return j;
    }
    void sol(int op) {
        for(int i=1;i<=lp;i++) sum[i]=(sum[nxt[i]]+flg[lp-i]);
        int res=0;
        for(int i=0,j=0;i<=ls;i++) {
            while((j==lp) || (j && s[i]!=p[j+1])) j=nxt[j];
            if(s[i]==p[j+1]) j++;
            lst[i]=j;
            if(j==lp) j=nxt[j],res++;
            if(!op) ans[i]+=res+sum[j];
            else ans[ls-i]+=res+sum[j];
        }
    }

}S,T;
int nxt[N],dfn[N],lst[N],cnt,vis[N];
struct BIT{
    int sum[N];
    int lowbit(int x) {
        return x&(-x);
    }
    void add(int x,int k) {
        for(int i=x;i<=cnt;i+=lowbit(i)) sum[i]+=k;
    }
    int query(int x) {
        int ans=0;
        for(int i=x;i;i-=lowbit(i)) ans+=sum[i];
        return ans;
    }
}ST;
void dfs1(int x) {
    dfn[x]=++cnt;
    for(auto i:Q2[x]) dfs1(i);
    lst[x]=cnt;
}
void dfs2(int x) {
    if(x && vis[x+lt] && lp-(x+lt)) {
        ST.add(dfn[lp-(x+lt)],1);
        ST.add(lst[lp-(x+lt)]+1,-1);
    }
    for(auto i:e[x]) ans[i.second]+=ST.query(dfn[i.first]);
    for(auto i:Q1[x]) dfs2(i);
    if(x && vis[x+lt] && lp-(x+lt)) {
        ST.add(dfn[lp-(x+lt)],-1);
        ST.add(lst[lp-(x+lt)]+1,1);
    }
}
signed main() {
#ifndef KAxdd
#ifndef ONLINE_JUDGE
    freopen("lgs.in","r",stdin);
    freopen("lgs.out","w",stdout);
#endif
#endif
    cin>>s>>t>>p;
    ls=s.size(),lt=t.size(),lp=p.size();
    S.s=" "+s; S.t=" "+t; S.p=" "+p;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    reverse(p.begin(),p.end());
    T.s=" "+s; T.t=" "+t; T.p=" "+p;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    reverse(p.begin(),p.end());
    s=" "+s; t=" "+t; p=" "+p;
    int jx=S.init(),jy=T.init();Oth/=2;
    if(jx==lp) jx=S.nxt[jx];
    if(jy==lp) jy=T.nxt[jy];

    while(jx) {
        T.flg[jx]++;
        jx=S.nxt[jx];
    }
    while(jy) {
        S.flg[jy]++;
        jy=T.nxt[jy];
    }
    S.sol(0); T.sol(1);
    if(lt<lp) {
        int j=0;
        for(int i=2;i<=lt;i++) {
            while(j && S.t[i]!=S.t[j+1]) j=nxt[j];
            if(S.t[i]==S.t[j+1]) j++;
            nxt[i]=j;
        }
        j=0;
        for(int i=1;i<=lp;i++) {
            while((j==lt) ||(j && S.p[i]!=S.t[j+1])) j=nxt[j];
            if(S.p[i]==S.t[j+1]) j++;
            if(j==lt) vis[i]=1;
        }
        for(int i=1;i<=lp;i++) {
            Q1[S.nxt[i]].push_back(i);
            Q2[T.nxt[i]].push_back(i);
        }
        dfs1(0);
        for(int i=0;i<=ls;i++) {
            int l=S.lst[i],r=T.lst[ls-i];
            if(l && r) e[l].push_back({r,i});
        }
        dfs2(0);
    }
    int l=0,r=0,maxn=0,cnt=0;
    for(int i=0;i<=ls;i++) {
        if(maxn<ans[i]) {
            l=i; r=i; cnt=0;
            maxn=ans[i];
        }
        if(maxn==ans[i]) r=i,cnt++;
    }
    printf("%d %d %d %d\n",maxn+Oth,cnt,l,r);
    return 0;
}
