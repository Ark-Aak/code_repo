#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int main()
{
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	cin>>n>>l>>r;
	if(n<=r-l+1)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<l+i-1<<endl;
		}
	}
	else
	{
		cout<<"Shinomiya";
	}
	return 0;
}
