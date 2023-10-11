#include<bits/stdc++.h>
using namespace std;
int n,q,a[1000005],b[1000005];
vector<int>	pos[1000005];
int main()
{
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		pos[a[i]].push_back(b[i]);
	}
	while(q--)
	{
		int A,B;
		cin>>A>>B;
		if(A==0&&B==0)
		{
			cout<<"Bob"<<endl;
			continue;
		}
		bool flag=0;
		for(int i=0;i<pos[A].size();i++)
		{
			if(pos[A][i]==B)
			{
				cout<<"Bob"<<endl;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			cout<<"Alice"<<endl;
		}
	}
	return 0;
}
