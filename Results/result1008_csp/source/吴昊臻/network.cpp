#include<bits/stdc++.h>
using namespace std;
int n,m,l,r,fa[1000005],son[1000005],bsz[1000005],rk[1000005],zz,w[1000005];
int id[1000005],dep[1000005],siz[1000005],top[1000005],x,ad[4000005];
long long zh[1000005];
vector<int>a[1000005]; 
long long qqq=INT_MAX;
string p;
int dfs(int i,int j)
{
	long long mx=0,o=0;
	dep[i]=j;
	siz[i]=1;
	for(int z=0;z<a[i].size();z++)
	{
		if(fa[i]==a[i][z]) continue; 
		fa[a[i][z]]=i;
		dfs(a[i][z],j+1);
		siz[i]+=siz[a[i][z]];
		if(siz[a[i][z]]>mx)
			o=a[i][z],mx=siz[a[i][z]];
	}
	son[i]=o;
	return 0;
}
int dfs1(int i,int j)
{
	top[i]=j;
	++x;
	id[i]=x;
	rk[x]=i;
	if(!son[i]) return 0;
	dfs1(son[i],j);
	for(int z=0;z<a[i].size();z++)
	{
		if(a[i][z]==fa[i]||a[i][z]==son[i]) continue;
		dfs1(a[i][z],a[i][z]); 
	}
	return 0;
}
int build(int l,int r,int bh)
{
	if(l==r) return zh[bh]=bsz[rk[l]],0;
	int mid=(l+r)/2;
	build(l,mid,bh*2);
	build(mid+1,r,bh*2+1);
	zh[bh]=min(zh[bh*2],zh[bh*2+1]);
	return 0;
}
long long cz(int l,int r,int nl,int nr,int bh)
{
	long long ans1=1e10;
	if(l>=nl&&r<=nr) return zh[bh];
	int mid=(l+r)/2;
	if(mid>=nl) ans1=min(ans1,cz(l,mid,nl,nr,bh*2));
	if(mid<nr) ans1=min(ans1,cz(mid+1,r,nl,nr,bh*2+1));
	return ans1;
}
int czl(int i,int j)
{
	long long ans=INT_MAX;
	while(top[i]!=top[j])
	{
		if(dep[top[i]]<dep[top[j]]) swap(i,j);
		qqq=min(qqq,cz(1,n,id[top[i]],id[i],1)); 
		i=fa[top[i]];
 	}
 	if(dep[i]>dep[j]) swap(i,j);
	qqq=min(qqq,cz(1,n,id[i],id[j],1)); 
 	return i;
}
long long czl1(int i,int j)
{
	long long ans=INT_MAX;
	while(top[i]!=top[j])
	{
		if(dep[top[i]]<dep[top[j]]) swap(i,j);
		ans=min(ans,cz(1,n,id[top[i]],id[i],1)); 
		i=fa[top[i]];
 	}
 	if(dep[i]>dep[j]) swap(i,j);
	ans=min(ans,cz(1,n,id[i],id[j],1)); 
 	return ans;
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		bsz[i]=i;
	for(int i=1;i<n;i++)
		cin>>l>>r,a[l].push_back(r),a[r].push_back(l);
	dfs(1,1);
	dfs1(1,1);	
	build(1,n,1);
	for(long long i=1;i<=m;i++)
	{
		cin>>p>>x;
		if(p[0]=='J')
			if(zz==0)
				zz=x,qqq=x;
			else zz=czl(zz,x);
		else
			if(x==zz) cout<<qqq<<endl; 
			else cout<<min(qqq,czl1(x,zz))<<endl;
	}
}
/*
5 9
1 3
5 3
2 4
4 3
JC 4
Query 5
Query 4
JC 2
Query 5
JC 1
Query 5
Query 1
Query 4
*/
