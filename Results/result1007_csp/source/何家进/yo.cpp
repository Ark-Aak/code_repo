#include<bits/stdc++.h>
using namespace std;
int n;
int sum;
int flag;
string s,t;
int cnt[114514];
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n>>s>>t;
	s=' '+s;
	t=' '+t;
	for(int i=1;i<=n;i++)
		cnt[i]=cnt[i-1]+(t[i]=='o')*(s[i]!='0');
	for(int j=1;j<=n;j++)
	{
		if(cnt[j])
		{
			cout<<"oimiya";
			return 0;
		}
		sum=s[j]-'0';
		flag=0;
		for(int i=j+1;i<=n;i++)
		{
			if(t[i]=='y')
			{
				if(sum%11)
					sum=(sum*10+s[i]-'0')%11,flag=1;
			}
			else
			{
				if(sum%11==0)
					sum=(sum*10+s[i]-'0')%11,flag=1;
			}
		}
		if(sum==0&&flag)
		{
			cout<<"yoimiya";
			return 0;
		}	
//		cout<<j<<" "<<sum<<endl;
	}
	cout<<"oimiya";
	return 0;
}
