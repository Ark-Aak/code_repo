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
#define N 1000005
#define Mod 998244353
#define int long long
struct Node{
	int u,x;
	friend bool operator<(Node a,Node b){
		return a.x>b.x;
	}
};
int n,k,a[N],vis[N],dis[N];
char t[55][55];
vector<int>e[N],w[55];
priority_queue<Node>q;
void dj(){
	For(i,2,n)dis[i]=inf;
	q.push((Node){1,0});
	while(!q.empty()){
		if(dis[n]==n-1)break;
		Node now=q.top();q.pop();
		if(vis[now.u])continue;
		vis[now.u]=1;
		Fo(i,w[a[now.u]])
			Fo(j,e[i])
				if(dis[j]>dis[now.u]+abs(now.u-j)){
					dis[j]=dis[now.u]+abs(now.u-j);
					q.push((Node){j,dis[j]});
				}
	}
}
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n),read(k);
	For(i,1,n)read(a[i]),e[a[i]].PB(i);
	For(i,1,k)scanf("%s",t[i]+1);
	For(i,1,k)For(j,1,k)
		if(t[i][j]=='1')
		w[i].PB(j);
	dj();
	if(dis[n]==inf)puts("-1");
	else write(dis[n]);
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
