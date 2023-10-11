#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],ans,ans3;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	long long tot=0,ans2=0;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(tot==0)
		{	
			tot=1;
			ans2=a[i]-1;
		}
		else
		{
			if(tot<k)
			{
				int j=i;
				while(a[j]==a[j+1]&&(j-i+1)<k-tot) j++;
				if(tot*2*(a[i]-a[i-1])<=(a[i]+a[i-1]-3)*(j-i+1))
				{
					tot+=(j-i+1);
					i=j;
					ans2=a[j]-1;
					if(i==n)
					{
						ans+=2*ans2*tot+ans3*tot;
						break;
					}
				}
				else
				{
					ans+=2*ans2*tot+ans3*tot;
					ans3+=2*ans2;
					tot=1;
					ans2=a[i]-1;
				}
			}
			else
			{
				ans+=2*ans2*tot+ans3*tot;
				tot=1;
				ans3+=2*ans2;
				ans2=a[i]-1;
			}
		}
		if(i==n)
		{
			ans+=2*ans2*tot+ans3*tot;
			break;
		}
	}
	cout<<ans;
	return 0;
}

