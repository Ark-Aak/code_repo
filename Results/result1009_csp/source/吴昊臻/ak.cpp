#include<bits/stdc++.h>
using namespace std;
long long n,m,k,top,top1,w[1000005],x;
long long ans;
struct node{
	long long cnt;
	long long f,b,id; 
}a[1000005];
struct node1{
	long long cnt;
	long long id; 
}b[1000005];
bool cmp(node1 i,node1 j)
{
	return i.cnt<j.cnt;
}
void sa(long long i)
{
	long long p=k,q=b[i].id;
	while(p--)
	{
//		cout<<a[q].cnt<<'\n';
		w[a[q].id]=1;
		if(a[a[q].f].cnt>a[a[q].b].cnt)
			if(a[q].b<=n)
			{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].b;
			}
			else{
			a[a[q].f].b=a[q].b;
			a[a[q].b].f=a[q].f;
			q=a[q].f;
		}
		else{
			if(a[q].f>0)
			{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].f;
			}
			else{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].b;
			}
		}
	}
}
void sa1(long long i)
{
	long long p=k,q=b[i].id;
	while(p--)
	{
//		cout<<a[q].cnt<<'\n';
		w[a[q].id]=1;
		if(a[a[q].f].cnt<a[a[q].b].cnt)
			if(a[q].b<=n)
			{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].b;
			}
			else{
			a[a[q].f].b=a[q].b;
			a[a[q].b].f=a[q].f;
			q=a[q].f;
		}
		else{
			if(a[q].f>0)
			{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].f;
			}
			else{
				a[a[q].f].b=a[q].b;
				a[a[q].b].f=a[q].f;
				q=a[q].b;
			}
		}
	}
}
int main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	m=n/k;
	top=1;
	top1=n;
	for(long long i=1;i<=n;i++)
		cin>>a[i].cnt,b[i].cnt=a[i].cnt,b[i].id=i,a[i].f=i-1,a[i].b=i+1,ans+=a[i].cnt;
	a[0].cnt=1e14;
	sort(b+1,b+n+1,cmp);
	for(long long i=1;i<=n;i++)
		a[b[i].id].id=i;
	for(long long i=1;i<=m;i++)
	{
		if(i%2==1)
		{
			while(w[top])top++;
			sa(top);
		}
		else
		{
			while(w[top1])top1--;
			sa1(top1);
		}
	}
	while(w[top1])top1--;
	cout<<ans-b[top1].cnt;
}
/*
11 5
1 5 2 7 1 9 4 6 2 11 3
*/
