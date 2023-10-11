#include<bits/stdc++.h>
using namespace std;
long long n,k,m,l,r,s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>s;
		if(s>0)
		{
			cout<<"0";
			return 0;
		}
	}
	cout<<"1";
	return 0;
} 

