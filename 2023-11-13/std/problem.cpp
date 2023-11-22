#include<bits/stdc++.h>
using namespace std;
int Query(int l,int r,int k);
int n,flag;
map<pair<int,int>,int>mp;
int solve(int l,int r)
{
	if(l==r)
		return l;
	if(l==r-1&&!(n%2))
	{
		if(!flag)
		{
			if(r<n)
			{
				int t=Query(r,n,n);
				return t==2?l:r;
			}
			else
			{
				int t=Query(1,l,n);
				return t==2?r:l;
			}
		}
		else
		{
			int a,b=mp[{1,l-1}];
			if(r==n)
				a=n/2+1;
			else
				a=mp[{1,r}];
			if(a==b+1)
			{
				int t=Query(1,l,2);
				return t==b+1?l:r;
			}
			else
			{
				int t=Query(r,n,2);
				return t==mp[{r+1,n}]+1?r:l;
			}
		}
	}
	int mid=l+(r-l)/2,a=Query(1,mid,2),b=Query(mid+1,n,2);
	mp[{1,mid}]=a,mp[{mid+1,n}]=b;
	a=2*a-mid,b=2*b-(n-mid);
	if(a==b)
	{
		if(flag)
		{
			if(mid<=flag)
				a++;
			else
				b++;
		}
		else
		{
			if(mid+1<n)
			{
				int t=Query(mid+1,n,n);
				if(t==2)
					a++,flag=mid+1;
				else
					b++,flag=mid;
			}
			else
			{
				int t=Query(1,mid,n);
				if(t==2)
					b++,flag=mid;
				else
					a++,flag=mid+1;
			}
		}
	}
	if(a>b)
		return solve(l,mid);
	else
		return solve(mid+1,r);
}
int Solve(int N)
{
	n=N;
	return solve(1,N);
}
