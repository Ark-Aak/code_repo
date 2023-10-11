#include<bits/stdc++.h>
#define int long long
#define inf 1e18
#define debug puts("IAKIOI")
using namespace std;
int a[2000010];
vector<int>v;
map<int,int>mp;
bool f[500010];
int n,k;
int q()
{
	int p=k,num=0;
	for ( int i = 0 ; i < v.size() ; i++ )
	{
		if(f[i])
		{
			continue;
		}
		num=i;
		break;
	}
	for ( int i = num+1 ; i < v.size() ; i++ )
	{
		if(f[i])
		{
			continue;
		 } 
		 int jssj=a[v[i]]*v[i],lfsj=(v[i]-v[num])*n;
		 if(jssj>lfsj)
		 {
		 	num=i;
		 }
	}
	int jl=v[num]*2-2;
	jl*=n;
	while(p&&num!=-1)
	{
		if(f[num])
		{
			num--;
			continue;
		}
		if(a[v[num]]<=p)
		{
			p-=a[v[num]];
			a[v[num]]=0;
			f[num]=1;
		}else{
			a[v[num]]-=p;
			p=0;
		}
		num--;
	}
	n=n-(k-p);
	return jl;//¾àÀë 
}
signed main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin >> n >> k;
	for ( int i = 1 ; i <= n ; i++ )
	{
		int x;
		cin >> x;
		a[x]++;
		if(mp[x]==0)
		{
			mp[x]=1;
			v.push_back(x);
		}
	}
	sort(v.begin(),v.end());
	int ans=0;
	while(n)
	{
		ans+=q();
	}
	cout <<ans;
	return 0;
}//15 
