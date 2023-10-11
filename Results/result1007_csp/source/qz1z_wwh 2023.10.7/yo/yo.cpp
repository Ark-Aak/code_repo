#include<bits/stdc++.h>
using namespace std;
int n,s[1000005],po,py,pz;
string t;
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
		if(s[i]!=0)
		{
			pz=1;
		}
	}
	cin>>t;
	for(int i=0;i<n;i++)
	{
		if(t[i]=='y')
		{
			py=1;
		}
		if(t[i]=='o')
		{
			po=1;
		}
	}
	if(po==0)
	{
		cout<<"yoimiya"<<endl;
		return 0;
	}
	if(py==0)
	{
		if(pz==1)
		{
			cout<<"oimiya"<<endl;
		}
		else
		{
			cout<<"yoimiya"<<endl;
		}
		return 0;
	}
}
