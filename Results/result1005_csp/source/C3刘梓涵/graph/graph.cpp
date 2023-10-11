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
#define N 100005
#define Mod 998244353
#define int long long
int n,m,Q;
vector<int>e[N];
struct Sub2{
    int k[N],vis[N],a[N],x,y;
    void Find(int u,int cnt){
		a[cnt++]=u;
        if(u==y){
        	k[x]=1;
            For(i,1,cnt-1)k[a[i]]=1;
            return ;
        }
        vis[u]=1;
        Fo(v,e[u]){
            if(vis[v])continue;
            Find(v,cnt);
        }
    }
    int dfs(int u,int cnt){
        int res=1;
        vis[u]=cnt;
        Fo(v,e[u]){
            if(vis[v]||k[v])continue;
            res+=dfs(v,cnt);
        }return res;
    }
    void main(){
        while(Q--){
            int ans=0,cnt=0;
            mem(k,0);mem(vis,0);
            read(x),read(y);
            Find(x,0);mem(vis,0);
            For(i,1,n)if(!vis[i]&&!k[i]){
            	int s=dfs(i,++cnt);
//            	cout<<s<<endl;
            	ans^=s;
			}
//            For(i,1,n)cout<<k[i]<<' ';cout<<endl;
//			For(i,1,n)cout<<vis[i]<<' ';cout<<endl;
            write(ans);puts("");
        }exit(0);
    }
}Sub2;
struct Sub3{
    int a[N],ans,kkk,x,y;
    int siz[N],sum[N];
    void Find(int u,int fa,int cnt){
    	if(kkk)return;
		a[cnt++]=u;
        if(u==y){
        	int res=siz[x];
        	ans^=sum[x];
//        	cout<<sum[x]<<endl;
            For(i,1,cnt-1){
            	ans^=(sum[a[i]]^res);
//            	cout<<(sum[a[i]]^res)<<endl;
            	res+=siz[a[i]];
			}ans^=res;
//			cout<<res<<endl;
            return ;
        }
        Fo(v,e[u]){
            if(v==fa)continue;
            Find(v,u,cnt);
        }
    }
    void dfs(int u,int fa){
        siz[u]=1;
		Fo(v,e[u]){
        	if(v==fa)continue;
        	dfs(v,u);
        	siz[u]+=siz[v];
        	sum[u]^=siz[v];
		}
    }
    void main(){
    	dfs(1,0);
//    	For(i,1,n)cout<<sum[i]<<' ';cout<<endl;
        while(Q--){
            ans=0,kkk=0;
            read(x),read(y);
            Find(x,0,0);
            write(ans);puts("");
        }exit(0);
    }
}Sub3;
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);	
    read(n),read(m);
    For(i,1,m){
        int u,v;
        read(u),read(v);
        e[u].PB(v),e[v].PB(u);
    }read(Q);
    if(n<=1000&&m<=2000&&Q<=1000)Sub2.main();
	else if(n==m+1) 
		Sub3.main();
	else Sub2.main();
    return 0;
}
/*
10 9
1 2
1 3
2 4
2 5
3 6
3 7
3 8
8 9
5 10
10
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
2 3
*/
