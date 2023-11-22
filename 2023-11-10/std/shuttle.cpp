#include<bits/stdc++.h>
#define rg register
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)

using namespace std;

const int maxn=1e5+10;

int n,m,S,T;
int X[maxn],H[maxn];

namespace SGT{
	int Lazy[maxn<<2];
	inline void build(int node,int l,int r)
	{
		Lazy[node]=-1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(node<<1,l,mid);
		build(node<<1|1,mid+1,r);
	}
	inline void pushdown(int node)
	{
		if(Lazy[node]==-1)return;
		Lazy[node<<1]=Lazy[node];
		Lazy[node<<1|1]=Lazy[node];
		Lazy[node]=-1;
	}
	inline void Cover(int node,int l,int r,int L,int R,int V)
	{
		if(L<=l&&r<=R)
		{
			Lazy[node]=V;
			return;
		}
		pushdown(node);
		int mid=(l+r)>>1;
		if(mid>=L)Cover(node<<1,l,mid,L,R,V);
		if(mid<R)Cover(node<<1|1,mid+1,r,L,R,V);
	}
	inline int Query(int node,int l,int r,int id)
	{
		if(Lazy[node]>=0)return Lazy[node];
		if(l==r)return Lazy[node];
		int mid=(l+r)>>1;
		if(mid>=id)return Query(node<<1,l,mid,id);
		else return Query(node<<1|1,mid+1,r,id);
	}
}

struct bridge{
	int l,r,x;
	inline bool operator < (const auto one)const{
		return x<one.x;
	}
}B[maxn];

pair<int,int>Need[maxn<<5];int ___;
inline void lelel()
{
	sort(Need+1,Need+___+1);
	___=unique(Need+1,Need+___+1)-Need-1;
}
map<pair<int,int>,int>id;
int tnt;
inline void process()
{
	lelel();
	for(rg int i=1;i<=___;i+=1)
		id[Need[i]]=++tnt;
}
namespace Graph{
	const int maxNode=maxn<<5;
	vector<pair<int,int> >G[maxNode];
	inline void add(int x,int y,int z)
	{
		G[x].emplace_back(y,z);
		G[y].emplace_back(x,z);
	}
	const long long INF=1e18;
	long long dist[maxNode];
	bool vis[maxNode];
	inline void dij()
	{
		int s,t;
		s=S,t=T;
		s=id[make_pair(s,0)];
		t=id[make_pair(t,0)];
		for(rg int i=1;i<=tnt;i+=1)dist[i]=INF;
		priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >Q;
		Q.emplace(dist[s]=0,s);
		while(!Q.empty())
		{
			auto top=Q.top().second;Q.pop();
			if(vis[top])continue;
			vis[top]=true;
			for(auto [nxt,W]:G[top])
				if(dist[nxt]>dist[top]+W)
				{
					dist[nxt]=dist[top]+W;
					Q.emplace(dist[nxt],nxt);
				}
		}
		if(dist[t]==INF)puts("-1");
		else printf("%lld\n",dist[t]);
	}
}

inline void ins1()
{
	Need[++___]=make_pair(S,0);
	Need[++___]=make_pair(T,0);
	for(rg int i=1;i<=m;i+=1)
	{
		auto [l,r,x]=B[i];
		Need[++___]=make_pair(l,x);
		Need[++___]=make_pair(r,x);
	}
	lelel();
	sort(B+1,B+m+1);
	{
		SGT::build(1,1,n);
		int id=0;
		int Max=0;
		for(rg int i=S;i;i-=1)
		{
			Max=max(Max,H[i]);
			while(id<m&&B[id+1].x<=Max)
			{
				auto [l,r,x]=B[++id];
				if(l<=i&&S<=r)
				{
					auto re=SGT::Query(1,1,n,i);
					Need[++___]=make_pair(i,x);
					if(re!=-1)Need[++___]=make_pair(i,re);
				}
				SGT::Cover(1,1,n,l,r,x);
			}
		}
		lelel();
		id=0,Max=0;
		SGT::build(1,1,n);
		for(rg int i=S;i<=n;i+=1)
		{
			Max=max(Max,H[i]);
			while(id<m&&B[id+1].x<=Max)
			{
				auto [l,r,x]=B[++id];
				if(l<=S&&i<=r)
				{
					auto re=SGT::Query(1,1,n,i);
					Need[++___]=make_pair(i,x);
					if(re!=-1)Need[++___]=make_pair(i,re);
				}
				SGT::Cover(1,1,n,l,r,x);
			}
		}
		lelel();
		SGT::build(1,1,n);
		id=Max=0;
		for(rg int i=T;i;i-=1)
		{
			Max=max(Max,H[i]);
			while(id<m&&B[id+1].x<=Max)
			{
				auto [l,r,x]=B[++id];
				if(l<=i&&S<=r)
				{
					auto re=SGT::Query(1,1,n,i);
					Need[++___]=make_pair(i,x);
					if(re!=-1)Need[++___]=make_pair(i,re);
				}
				SGT::Cover(1,1,n,l,r,x);
			}
		}
		lelel();
		id=0,Max=0;
		SGT::build(1,1,n);
		for(rg int i=T;i<=n;i+=1)
		{
			Max=max(Max,H[i]);
			while(id<m&&B[id+1].x<=Max)
			{
				auto [l,r,x]=B[++id];
				if(l<=S&&i<=r)
				{
					auto re=SGT::Query(1,1,n,i);
					Need[++___]=make_pair(i,x);
					if(re!=-1)Need[++___]=make_pair(i,re);
				}
				SGT::Cover(1,1,n,l,r,x);
			}
		}
		lelel();
	}
	SGT::build(1,1,n);
	for(rg int i=1;i<=m;i+=1)
	{
		rg int j=i;
		while(j<m&&B[j+1].x==B[i].x)j+=1;
		for(rg int k=i;k<=j;k+=1)
		{
			auto [l,r,no_use]=B[k];
			int re=SGT::Query(1,1,n,l);
			if(re!=-1)
			{
				Need[++___]=make_pair(l,re);
			}
			re=SGT::Query(1,1,n,r);
			if(re!=-1)Need[++___]=make_pair(r,re);
		}
		for(rg int k=i;k<=j;k+=1)
		{
			auto [l,r,H]=B[k];
			SGT::Cover(1,1,n,l,r,H);
		}
		i=j;
	}
	SGT::build(1,1,n);
	for(rg int i=m;i;i-=1)
	{
		rg int j=i;
		while(j>1&&B[j-1].x==B[i].x)j-=1;
		for(rg int k=j;k<=i;k+=1)
		{
			auto [l,r,x]=B[k];
			int re=SGT::Query(1,1,n,l);
			if(re!=-1&&re<=H[l])Need[++___]=make_pair(l,re);
			re=SGT::Query(1,1,n,r);
			if(re!=-1&&re<=H[r])Need[++___]=make_pair(r,re);
		}
		for(rg int k=j;k<=i;k+=1)
		{
			auto [l,r,H]=B[k];
			SGT::Cover(1,1,n,l,r,H);
		}
		i=j;
	}
}
inline void Connect()
{
	{
		static vector<pair<int,int> >pos[maxn];
		for(rg int i=1;i<=n;i+=1)pos[i].clear();
		for(auto [Info,node]:id)
		{
			auto [x,y]=Info;
			pos[x].emplace_back(node,y);
		}
		for(rg int i=1;i<=n;i+=1)
			if(pos[i].size()>1)
			{
				int sz=pos[i].size();
				for(rg int j=0;j<sz-1;j+=1)Graph::add(pos[i][j].first,pos[i][j+1].first,pos[i][j+1].second-pos[i][j].second);
			}
		for(rg int i=1;i<=n;i+=1)vector<pair<int,int> >().swap(pos[i]);
	}
	{
		static int Height[maxn<<4];int ccf=0;
		for(auto [Info,node]:id)
		{
			auto [x,y]=Info;
			Height[++ccf]=y;
		}
		for(rg int i=1;i<=m;i+=1)Height[++ccf]=B[i].x;
		sort(Height+1,Height+ccf+1);
		ccf=unique(Height+1,Height+ccf+1)-Height-1;
		static vector<pair<int,int> >pos[maxn<<4],bri[maxn<<4];
		for(rg int i=1;i<=ccf;i+=1)pos[i].clear(),bri[i].clear();
		for(auto [Info,node]:id)
		{
			auto [x,y]=Info;
			pos[lower_bound(Height+1,Height+ccf+1,y)-Height].emplace_back(x,node);
		}
		for(rg int i=1;i<=m;i+=1)
			bri[lower_bound(Height+1,Height+ccf+1,B[i].x)-Height].emplace_back(B[i].l,B[i].r);
		for(rg int i=1;i<=ccf;i+=1)
			if(pos[i].size()&&bri[i].size())
			{
				sort(bri[i].begin(),bri[i].end(),[](auto x,auto y)
												 {
													 return x.first<y.first;
												 });
				int sz=pos[i].size(),id=0;
				for(auto [l,r]:bri[i])
				{
					while(id<sz&&pos[i][id].first<l)id+=1;
					if(id==sz)break;
					if(pos[i][id].first>r)continue;
					int id2=id;
					while(id2<sz-1&&pos[i][id2+1].first<=r)id2+=1;
					for(rg int j=id+1;j<=id2;j+=1)
						Graph::add(pos[i][j-1].second,pos[i][j].second,X[pos[i][j].first]-X[pos[i][j-1].first]);
				}
			}
		for(rg int i=1;i<=ccf;i+=1)
			vector<pair<int,int > >().swap(pos[i]),
				vector<pair<int,int> >().swap(bri[i]);
	}
}

int main()
{
	file("shuttle");
	scanf("%d %d",&n,&m);
	for(rg int i=1;i<=n;i+=1)scanf("%d %d",X+i,H+i);
	for(rg int i=1;i<=m;i+=1)scanf("%d %d %d",&B[i].l,&B[i].r,&B[i].x);
	for(rg int i=1;i<=m;i+=1)B[i].l+=1,B[i].r+=1;
	scanf("%d %d",&S,&T);
	S+=1,T+=1;
	ins1();
	process();
	Connect();
	Graph::dij();
	return 0;
}
