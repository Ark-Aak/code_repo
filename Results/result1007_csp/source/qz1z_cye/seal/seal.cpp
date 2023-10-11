#include<bits/stdc++.h>
using namespace std;
long long n,t,m,q[2005],z[2005],l,ans,top,kl[4000005];
int main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	cin>>n>>t>>m;
	for(int i=1;i<=n;i++) cin>>q[i]>>z[i];
	q[n+1]=t;
	sort(q+1,q+n+1);
	sort(z+1,z+n+1);
	for(int i=1;i<=n+1;i++)
	{
		while(z[l]<q[i]&&l+1<=n) l++;
		if(z[l]>q[i+1])  ans+=q[i+1]-q[i];
		else
		{
			top++;
			kl[top]=z[l]-q[i];
			l++;
			while(z[l+1]<q[i+1]&&l+1<=n)
			{
				top++;
				kl[top]=z[l]-z[l-1];
				l++;
			}
			ans+=q[i+1]-z[l];
			l++;
		}
	}
	sort(kl+1,kl+top+1);
	for(int i=top;i>=top-m+1;i--)
	{
		ans+=kl[i];
	}
	cout<<ans;
	return 0;
} 



