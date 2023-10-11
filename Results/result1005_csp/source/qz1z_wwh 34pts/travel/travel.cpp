#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int l[100005],r[100005],s[100005];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i]>>s[i];
		if(s[i]!=0)
		{
			cout<<"0"<<endl;
			return 0;
		}
	}
	cout<<"1"<<endl;
//	reutn 0;
}
