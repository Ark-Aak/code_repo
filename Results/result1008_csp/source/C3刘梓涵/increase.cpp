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
#define Mod 998244353
#define int long long
struct Edge{
	int u,v;
}e[N];
struct Node{
	int v,w;
};
int n,m,ans[N];
int f[N][2][2],vis[N];
vector<Node>a[N];
void dfs(int E){
	vis[E]=1;
	int u=e[E].u,Max=0,Min=1e16;
	Fo(v,a[u])
	if(v.w>E){
		if(!vis[v.w])dfs(v.w);
		if(e[v.w].u==u){
			Max=max(Max,f[v.w][1][0]);
			Min=min(Min,f[v.w][1][1]);
		}else{
			Max=max(Max,f[v.w][0][0]);
			Min=min(Min,f[v.w][0][1]);
		}
	}
	if(Min==1e16&&Max==0)
		Min=0,Max=0;
	f[E][0][1]=Max+1;
	f[E][0][0]=Min+1;
//	cout<<"u"<<E<<":"<<Max<<' '<<Min<<endl;
	u=e[E].v,Max=0,Min=1e16;
	Fo(v,a[u])
	if(v.w>E){
		if(!vis[v.w])dfs(v.w);
		if(e[v.w].u==u){
			Max=max(Max,f[v.w][1][0]);
			Min=min(Min,f[v.w][1][1]);
		}else{
			Max=max(Max,f[v.w][0][0]);
			Min=min(Min,f[v.w][0][1]);
		}
	}
	if(Min==1e16&&Max==0)
		Min=0,Max=0;
	f[E][1][1]=Max+1;
	f[E][1][0]=Min+1;
//	cout<<"v"<<E<<":"<<Max<<' '<<Min<<endl;
	return;
}
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	read(n),read(m);
	For(i,1,m){
		int u,v,w;
		read(u),read(v),read(w);
		a[u].PB(((Node){v,w}));
		a[v].PB(((Node){u,w}));
		e[w].u=u,e[w].v=v;
	}
	For(i,1,m)
	if(!vis[i])
		dfs(i);
	For(i,1,n)
	Fo(j,a[i]){
		if(e[j.w].u==i)
			ans[i]=max(ans[i],f[j.w][1][0]);
		else ans[i]=max(ans[i],f[j.w][0][0]);
	}
	For(i,1,n)printf("%lld ",ans[i]);
//	For(i,1,m)
//	cout<<f[i][0][0]<<' '<<f[i][0][1]<<' '
//		<<f[i][1][0]<<' '<<f[i][1][1]<<endl;
    return 0;
}


