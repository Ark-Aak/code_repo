#include<bits/stdc++.h>
using namespace std;
int n,kl[500005],k[30],ans2,kj[30];
string s;
int main()
{
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	n=s.size();
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		kj[s[i]-'a']++;
		if(k[s[i]-'a']==0) 
		{
			k[s[i]-'a']=1;
			kl[i]++;
		}
		else
		{
			k[s[i]-'a']=0;
			kl[i+1]--;
		}
	}
	for(int i=0;i<=25;i++)
	{
		if(kj[i]==1) ans2++;
	}
	int ans=0,sa=0;
	for(int i=1;i<=n+1;i++)
	{
		sa+=kl[i];
		ans=max(ans,sa);
	}
	cout<<ans-ans2;
	return 0;
}
