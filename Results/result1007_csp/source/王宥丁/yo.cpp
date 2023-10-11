#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,t;
int n;
//void subtask1()
//{
//	for ( int i = 0 ; i < (1<<n) ; i++ )
//	{
//		int cnt=0,k=0;
//		for ( int j = 0 ; j < n ; j++ )
//		{
//			if((i>>j)&1)
//			{
//				cnt=cnt*10+s[j]-'0';
//			}else{
//				cnt=cnt*10;
//			}
//			if(t[j]=='o')
//			{
//				k+=(1<<j);
//			}
//		}
//		if(cnt%11)
//		{
//			
//		}
//	}
//}
void subtask2()
{
	int flag=0;
	for ( int i = 0 ; i < n ; i++ )
	{
		if(s[i]!='0')
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout << "oimiya";
	}else{
		cout << "yoimiya";
	}
}
bool f[20];
void subtask3()
{
	int cnt1=0,cnt2=0;
	for ( int i = 0 ; i < n ; i++ )
	{
		if(i%2)
		{
			cnt1+=s[i]-'0'; 
		}else{
			cnt2+=s[i]-'0';
		}
	}
	cnt1%=11;
	cnt2%=11;
	int cnt=(cnt1-cnt2+11)%11;
	f[cnt]=1;
	for ( int i = 0 ; i < n ; i++ )
	{
		if(i%2)
		{
			for ( int j = 0 ; j < 11-s[i]+'0' ; j++ )
			{
				f[j]|=f[j+s[i]-'0'];
			}
			for ( int j = 11-s[i]+'0' ; j < 11 ; j++ )
			{
				f[j]|=f[j+s[i]-'0'-11];
			}
		}else{
			for ( int j = s[i]-'0' ; j < 11 ; j++ )
			{
				f[j]|=f[j-s[i]-'0'];
			}
			for ( int j = 0 ; j < s[i]-'0' ; j++ )
			{
				f[j]|=f[j-s[i]-'0'+11];
			}
		}
	}
	if(f[0])
	{
		cout << "yoimiya";
	}else{
		cout << "oimiya";
	}
}
signed main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin >> n;
	cin >> s>>t;
//	if(n<=10)
//	{
//		subtask1();
//		return 0;
//	}
	int flagy=1,flago=1;
	for ( int i = 0 ; i < n ; i++ )
	{
		if(t[i]=='y')
		{
			flago=0;
		}else{
			flagy=0;
		}
	}
	if(flago)
	{
		subtask2();
		return 0;
	}
	if(flagy)
	{
		subtask3();
		return 0;
	}
	cout << "oimiya";
	return 0;
}
