//0 | 100
#include<bits/stdc++.h>
using namespace std;
int a[50],n,ans;
string b;
int main()
{
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>b;
	n=b.size();
	for(int i=0;i<n;i++)
	{
		a[int(b[i]-'a')]++;
	}
	for(int i=0;i<26;i++)
	{
		ans=max(ans,a[i]);
	}
	cout<<ans<<endl;
}
