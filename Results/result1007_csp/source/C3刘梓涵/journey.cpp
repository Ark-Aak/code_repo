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
#define N 1005
#define QwQ 1000005
#define Mod 998244353
#define int long long
struct Node{
	int v,i;
};
struct Edge{
	int f,e;
};
int n,m,Q;
int vis[N][N],vi[N];
vector<Node>a[N];
vector<Edge>f[N][N];
bool cmp(Edge a,Edge b){return a.f<b.f;}
void dfs(int u,int time){
	vi[u]=1;
	if(!a[u].size())return ;
	FoR(j,0,a[u].size()){
		int v=a[u][j].v,t=a[u][j].i;
//		cout<<u<<"->"<<v<<' '<<t<<endl;
		if(vis[u][v]||vi[v]||t<time)continue;
		vis[u][v]=1;
		if(vis[v][u]){
			f[u][v].PB(((Edge){t,j}));
			For(i,1,n)if(f[v][i].size()&&f[v][i][0].f>t){
				f[u][i].PB(((Edge){f[v][i][0].f,j}));
			}
			continue;
		}
		dfs(v,t);
//		cout<<u<<"->"<<v<<endl;
		f[u][v].PB(((Edge){t,j}));
		For(i,1,n)if(f[v][i].size()){
			f[u][i].PB(((Edge){f[v][i][0].f,j}));
		}
	}vi[u]=0;
	For(i,1,n)
	sort(f[u][i].begin(),f[u][i].end(),cmp);
}
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n),read(m),read(Q);
	For(i,1,m){
		int u,v;
		read(u),read(v);
		a[u].PB(((Node){v,i}));
		a[v].PB(((Node){u,i}));
	}
	For(i,1,n)
		dfs(i,0);
	while(Q--){
		int l,r,s,t,kkk=0;
		read(l),read(r);
		read(s),read(t);
		Fo(v,a[t]){
		if(s==v.v)kkk=1;
			FoR(i,0,f[s][v.v].size()){
//				cout<<s<<"->"<<v.v<<' '<<f[s][v.v][i].e<<" "<<f[s][v.v][i].f<<endl;
				if(a[s][f[s][v.v][i].e].i>=l){
					if(r>=f[s][v.v][i].f)kkk=1;
					break;
				}
			}if(kkk)break;
		}
		if(kkk)puts("Yes");
		else puts("No");
	}/*
	For(i,1,n){
		For(j,1,n){
			cout<<i<<"->"<<j<<endl;
			FoR(k,0,f[i][j].size()){
				cout<<f[i][j][k].f<<' ';
			}cout<<endl;
		}cout<<endl;
	}cout<<endl;
	For(i,1,n){
		For(j,1,n){
			FoR(k,0,f[i][j].size()){
				cout<<f[i][j][k].e<<' ';
			}cout<<endl;
		}cout<<endl;
	}cout<<endl;*/
    return 0;
}

