#include<bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
#define int long long
using namespace std;
template<typename T> inline T read(T &num)
{
	re T x=0,f=0; re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
#define lowbit(x) ((x)&(-x))
int n,a[200001],lef[200001],rig[200001];
queue<int> q[200001];
struct binary_indexed_tree
{
	int tree[200001],n;
	inline void reset(){memset(tree,0,sizeof tree);n=0;}
	inline void resize(int N){n=N;assert(n<=200000);}
	inline void resetsize(int N){memset(tree,0,sizeof tree);n=N;assert(n<=200000);}
	inline void modify(int pos,int d)
	{
		while(pos<=n) tree[pos]+=d,pos+=lowbit(pos); 
	}
	inline int query(int pos)
	{
		int res=0;
		while(pos>0) res+=tree[pos],pos-=lowbit(pos);
		return res;
	}
}t;
int vis[200001];
int ans;
signed main()
{
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout); 
	read(n);
	t.resetsize(n);
	rep(i,1,n)
	{
		read(a[i]);
		q[a[i]].emplace(i);
	}
	rep(i,1,n)
	{
		if(vis[a[i]]) t.modify(i,1);
		++vis[a[i]];
	}
	rep(i,1,n) 
	{
		if(q[a[i]].empty()) lef[i]=n;
		else lef[i]=q[a[i]].front(),q[a[i]].pop();
		if(q[a[i]].empty()) rig[i]=n;
		else rig[i]=q[a[i]].front();
	}
	rep(i,1,n) 
	{
		if(rig[i]==lef[i]) continue;
		ans+=rig[i]-lef[i]-t.query(rig[i])+t.query(lef[i]);
//		cout<<ans<<endl;
		if(--vis[a[i]]) t.modify(i,-1);
	}
	write(ans);
	return 0;
}
