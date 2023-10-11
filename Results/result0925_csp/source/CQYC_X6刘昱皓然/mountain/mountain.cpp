#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],q[1000005],l=1,r,ans[1000005],u[1000005];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int main()
{
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		while(l<=r&&a[q[l]]<=a[q[l+1]])	l++;
		while(l<=r&&a[q[r]]<=a[i])	r--;
		ans[i]=i-q[r]-1;
		q[++r]=i;
	}
	l=1,r=0;
	for(int i=n;i>=1;i--)
	{
		while(l<=r&&a[u[l]]<=u[q[l+1]])	l++;
		while(l<=r&&a[u[r]]<=a[i])	r--;
		if(!u[r])	ans[i]+=n-i;
		else	ans[i]+=u[r]-i-1;
		u[++r]=i;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
