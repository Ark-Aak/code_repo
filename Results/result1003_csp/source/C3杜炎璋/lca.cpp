#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;
vector<int> q[500005];
int sz[500005],f[500005],ans[500005];
void dfs1(int x,int fa) {
	sz[x]=1;
	for(int i=0;i<q[x].size();i++) {
		int to=q[x][i];
		if(to==fa) continue;
		dfs1(to,x);
		f[x]+=x*(sz[x]-1)*(sz[to]);
		sz[x]+=sz[to];
		f[x]+=f[to];
	}
	f[x]+=x*(sz[x]-1);
} 
void dfs2(int x,int fa,int s,int nsz) {
	ans[x]=nsz*x+f[x]+x*nsz*(sz[x]-1)+s;
	for(int i=0;i<q[x].size();i++) {
		int to=q[x][i];
		if(to==fa) continue;
		int s1=ans[x]-f[to]-(nsz+sz[x]-sz[to]-1)*(sz[to])*x-sz[to]*x;
		int n1=nsz+sz[x]-sz[to];
		dfs2(to,x,s1,n1);
	}
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	int n;
	n=in;
	for(int i=1;i<n;i++) {
		int x,y;
		x=in,y=in;
		q[x].push_back(y);
		q[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0,0,0);
	for(int i=1;i<=n;i++) {
		int cnt=2ll*ans[i]+(n+1)*n/2;
		out(cnt,' ');
	}
	return 0;
}

/*
7
1 2
1 3
3 5
3 4
4 6
1 7
*/

