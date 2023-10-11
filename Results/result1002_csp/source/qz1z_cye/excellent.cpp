#include<bits/stdc++.h>
using namespace std;
unsigned long long T,p[3005],ha=998244353,len,aa,sum=1,kl,qian[3005],hou[3005],h1,h2,slen,fflag,ans;
string s;
int main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>s;
		len=s.size();
//		if(len%2==1) 
//		{
//			cout<<"0"<<endl;
//			continue;
//		}
		s=" "+s;
		for(int i=1;i<=len;i++) qian[i]=hou[i]=0;
		for(int i=2;i<=len;i++)
		{
			for(int h=1;h<=i;h++)
			{
				slen=i-h+1;
				if(slen%2==0)
				{
					h1=h;
					h2=i-slen/2+1;
					fflag=0;
					for(int j=1;j<=slen/2;j++)
					{
						if(!(s[h1+j-1]==s[h2+j-1]||s[h1+j-1]=='?'||s[h2+j-1]=='?')) 
						{
							fflag=1;
							break;
						}
					}
					if(fflag==0) 
					{
						qian[i]++;
						hou[h]++;
					}
				}
			}
		}
		ans=0;
	//	cout<<s<<endl;
		for(int i=2;i<len;i++)
		{
		//	cout<<i<<" "<<qian[i]<<" "<<hou[i+1]<<endl;
			ans+=qian[i]*hou[i+1];
		}
		cout<<ans<<endl;
	}
	return 0;
}
//4
//aabbbb
//cccccc
//aabaabaabaa
//bbaabaababaaba
