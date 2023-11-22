#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

namespace fastio{
	struct{template<typename T>operator T(){
		T x=0;char f=0,c=getchar();
		while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
		while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
		return f?-x:x;
	}}in;int stk[39],tp;
	template<typename T>void out(T x,char c=0){
		if(x<0)putchar('-'),x=-x;
		do stk[tp++]=x%10;while(x/=10);
		while(tp)putchar(stk[--tp]^48);
		if(c)putchar(c);
	}
}using fastio::in;using fastio::out;

const int N = 200005;
vector<int> g[N];
int ans[N];
int c[N];
int n,q;

namespace Vblock{
	const int M = 500;
	vector<int> t[N/M+1];
	int c[N];

	void build(){
		for(int k=N/M;~k;k--)
			t[k].resize(1);
	}

	void add(int x){
		int y = x/M;
		if(c[x]>=t[y].size())
			t[y].resize(c[x]+1);
		t[y][c[x]]--;
		if(t[y].size()==(++c[x]))
			t[y].push_back(1);
		else
			t[y][c[x]]++;
	}
	void del(int x){
		int y = x/M;
		t[y][c[x]]--;
		if(t[y].size()>1&&!t[y].back())
			t[y].pop_back();
		t[y][--c[x]]++;
	}
	int query(){
		int mx = 0;
		for(int k=N/M;~k;k--)
			mx = max(mx,(int)t[k].size()-1);
		for(int k=0;;k++)
			if(mx==t[k].size()-1)
				for(int j=k*M;j<(k+1)*M;j++)
					if(c[j]==mx)
						return j;
		return -1;
	}
}

int l[N],p[N],siz[N],son[N],idx;
void dfs1(int u){
	l[u] = ++idx;
	p[idx] = u;
	siz[u] = 1;
	for(int v:g[u]){
		if(l[v])
			continue;
		dfs1(v);
		siz[u] += siz[v];
		if(siz[v]>siz[son[u]])
			son[u] = v;
	}
}

int dfn[N],nfd[N];
void dfs2(int u,int father){
	for(int v:g[u])
		if(v!=father&&v!=son[u])
			dfs2(v,u);
	if(son[u])
		dfs2(son[u],u);
	nfd[++idx] = u;
	dfn[u] = idx;
}

int d[N];

class inquiry{
	public:
		int l,r,block,id;

		bool operator < (const inquiry &tmp)const{
			if(block!=tmp.block)
				return l<tmp.l;
			if(block&1)
				return r>tmp.r;
			return r<tmp.r;
		}
}qus[N];

void move(int x,int y){
	if(l[x]+siz[x]<=l[y]||l[y]+siz[y]<=l[x]){
		for(int k=l[x];k<l[x]+siz[x];k++)
			Vblock::del(c[p[k]]);
		for(int k=l[y];k<l[y]+siz[y];k++)
			Vblock::add(c[p[k]]);
	}
	else{
		for(int k=l[x];k<l[y];k++)
			Vblock::del(c[p[k]]);
		for(int k=l[y];k<l[x];k++)
			Vblock::add(c[p[k]]);
		for(int k=l[x]+siz[x];k<l[y]+siz[y];k++)
			Vblock::add(c[p[k]]);
		for(int k=l[y]+siz[y];k<l[x]+siz[x];k++)
			Vblock::del(c[p[k]]);
	}
}


int main(){
	freopen("diedmd.in","r",stdin); 
	freopen("diedmd.out","w",stdout); 
	n = in,q = in;
	for(int k=1;k<=n;k++)
		c[k] = in;
	for(int k=1;k<n;k++){
		int a = in,b = in;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(1);
	idx = 0;
	dfs2(1,0);
	auto cost = [](int x,int y){
		if(l[x]+siz[x]<=l[y]||l[y]+siz[y]<=l[x])
			return siz[x]+siz[y];
		return abs(l[x]-l[y])+abs(l[x]+siz[x]-l[y]-siz[y]);
	};
	for(int k=2;k<=n;k++)
		d[k] = d[k-1]+cost(nfd[k-1],nfd[k]);
	
	int block = d[n]/sqrt(q)+1;
	for(int k=1;k<=q;k++){
		int x = dfn[(int)in],y = dfn[(int)in];
		if(x>y)
			swap(x,y);
		qus[k] = {x,y,d[x]/block,k};
	}
	sort(qus+1,qus+1+q);
	Vblock::build();
	for(int k=1;k<=q;k++){
		move(nfd[qus[k-1].l],nfd[qus[k].l]);
		move(nfd[qus[k-1].r],nfd[qus[k].r]);
		ans[qus[k].id] = Vblock::query();
	}
	for(int k=1;k<=q;k++)
		out(ans[k],'\n');
	return 0;
}
