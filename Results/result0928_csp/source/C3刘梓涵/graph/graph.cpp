#include<bits/stdc++.h>
#define int long long
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
#define Mod 1000000007
struct Node{
        int a,b,i;
    }x[N],y[N];
int n,ans,vis[N];
int k[N],fa[N],p[N];
vector<int>a[N];
bool cmp1(Node a,Node b){
    if(a.a==b.a)return a.b<b.b;
    return a.a<b.a;
}
bool cmp2(Node a,Node b){
    if(a.b==b.b)return a.a<b.a;
    return a.b<b.b;
}
int find(int x){
    if(fa[x]==x)return x;
    return fa[x]=find(fa[x]);
}
void dfs(int u){
	vis[u]=1;
	Fo(v,a[u])
	if(!vis[v])
	dfs(v);
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
    read(n);
    For(i,1,n){
        read(x[i].a),read(x[i].b);
//        x[i].i=i;y[i]=x[i];
    }
//    For(i,1,n)fa[i]=i;
//    sort(x+1,x+1+n,cmp1);
//    sort(y+1,y+1+n,cmp2);
//    For(i,1,n)
//        if(x[i].a==x[i+1].a){
//            int j=i+1,f=find(i);
//            while(x[j].a==x[i].a)
//                fa[find(j)]=f,j++;
//            i=j;
//        }
//    For(i,1,n)
//        if(y[i].b==y[i+1].b){
//            int j=i+1,f=find(i);
//            while(y[j].b==y[i].b)
//                fa[find(j)]=f,j++;
//            i=j;
//        }
//    For(i,1,n)k[x[i].i]=i;
//    For(i,1,n){
//        p[i]=p[i-1];
//        if(k[i])
//    }
	For(i,1,n)
	For(j,i+1,n){
		if(x[i].a<=x[j].a&&x[i].b<=x[j].b)a[i].PB(j),a[j].PB(i);
		if(x[i].a>=x[j].a&&x[i].b>=x[j].b)a[i].PB(j),a[j].PB(i);
	}
	For(i,1,n)
	if(!vis[i])
	dfs(i),ans++;
	cout<<ans;
    return 0;
}
