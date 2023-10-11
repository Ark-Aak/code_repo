#include<bits/stdc++.h>
using namespace std;
int T,n,fg,dpa[3005],dpb[3005],ans,anss;
string s;
int main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	cin>>T;
	while(T--)
	{
		anss=0;
		cin>>s;
		n=s.size();s=" "+s;
		if(n==4) {cout<<1<<endl;continue;}
		for(int i=2;i<=n-2;i++)
		{
			ans=0;
			for(int j=i;j>=i-i/2+1;j--)
			{
				if((i-j+1)>i/2) continue;
				fg=1;
				for(int k=i;k>=j;k--)
				{
					if(s[k]!=s[k-(i-j)-1]&&s[k]!='?'&&s[k-(i-j)-1]!='?') fg=0;
				}
				ans+=fg;
			}
			dpa[i]=ans;
		}
		for(int i=3;i<=n-1;i++)
		{
			ans=0;
			for(int j=i;j<=(n-i+1)/2+i-1;j++)
			{
				if((j-i+1)>(n-i+1)/2) continue;
				fg=1;
				for(int k=i;k<=j;k++)
				{
					if(s[k]!=s[k+(j-i)+1]&&s[k]!='?'&&s[k+(j-i)+1]!='?') fg=0;
				}
				ans+=fg;
			}
			dpb[i]=ans;
		}
		for(int i=2;i<=n-2;i++)
		{
			anss+=dpa[i]*dpb[i+1];
		}
		cout<<anss<<endl;
	}
	return 0;
}
