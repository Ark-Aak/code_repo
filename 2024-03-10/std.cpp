#include<bits/stdc++.h>
#define lt id<<1
#define rt id<<1|1
#define fi first
#define se second
#define mk make_pair
#define pi pair<int,int>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}
const int N=1e5+10,M=N<<2,K=N*40;
int t,n,B,T,ans,ll[N],rr[N],kk[N],Fi[M],Lt[K],Rt[K],ls[M],now[K],tot[N];
bool vis[N],biao[N];
queue<int>q;
vector<pi>loc[N];
void build(int id,int l,int r)
{
	Fi[id]=ls[id]=++T;Lt[T]=Rt[T]=now[T]=0;
	if(l==r) return loc[l].clear(),void();
	int mid=(l+r)>>1;
	build(lt,l,mid);build(rt,mid+1,r);
}
void add(int id,int l,int r,int L,int R,int d)
{
	if(l>R||r<L) return;
	if(L<=l&&r<=R)
	{
		now[++T]=d;
		loc[d].push_back(mk(T,id));
		Rt[ls[id]]=T;Lt[T]=ls[id];Rt[T]=0;ls[id]=T;
		return;
	}
	int mid=(l+r)>>1;
	add(lt,l,mid,L,R,d);add(rt,mid+1,r,L,R,d);
}
void Del(int x)
{
	for(pi v:loc[x])
	{
		Lt[Rt[v.fi]]=Lt[v.fi],Rt[Lt[v.fi]]=Rt[v.fi];
		if(!Rt[v.fi]) ls[v.se]=Lt[v.fi];
	}
}
void del(int id,int l,int r,int x)
{
	for(int i=Rt[Fi[id]];i;i=Rt[i])
	{
		--kk[now[i]];
		if(!kk[now[i]]) vis[now[i]]=1,Del(now[i]),q.push(now[i]);
	}
	if(l==r) return;
	int mid=(l+r)>>1;
	if(x<=mid) del(lt,l,mid,x);
	else del(rt,mid+1,r,x);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();ans=0;B=sqrt(n);
		for(int i=1;i<=n;i++)
			ll[i]=read(),rr[i]=read(),kk[i]=read(),vis[i]=biao[i]=0;
		T=0;build(1,1,n);
		for(int TT=0;TT<=n;TT+=B)
		{
			for(int i=1;i<=n;i++)
				tot[i]=tot[i-1]+biao[i];
			for(int i=1,p;i<=n;i++)
				if(!vis[i])
				{
					p=kk[i]-tot[rr[i]]+tot[ll[i]-1];
					if(p>B) continue;
					vis[i]=1;kk[i]=p;
					if(p<=0) q.push(i);
					else add(1,1,n,ll[i],rr[i],i);
				}
			while(!q.empty())
			{
				int x=q.front();q.pop();
				++ans;biao[x]=1;del(1,1,n,x);
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
