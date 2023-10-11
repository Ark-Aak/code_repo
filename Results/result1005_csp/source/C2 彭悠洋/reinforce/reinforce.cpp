#include <bits/stdc++.h>
using namespace std;
string s,t = " ";
int ton[128],id[128],ans,m,las;
signed main()
{
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s;
	int n = s.size();
	s = ' '+s;
	las = 114514;
	for(int i = 1;i<=n;i++)
	{
		int ch = s[i];
		if(ton[ch]==0)
		{
			ton[ch]++;
			if(!m) t+=ch,m++;
			else
			{
				t+=' ';
				int x;
				for(int j = 1;j<=m;j++)
					if(t[j]==s[i-1])
					{
						x = j;
						break;
					}
//				cout<<m<<' '<<x<<'\n';
				for(int j = m;j>x;j--) t[j+1] = t[j];
				t[x+1] = ch,m++;
			}
			continue;
		}
//		cout<<t<<'\n';
	}
	for(int i = 1;i<=m;i++)
		id[t[i]] = i;
//	cout<<t<<'\n'<<id['a']<<' '<<id['b']<<' '<<id['c']<<'\n';
	for(int i = 1;i<=n;i++)
	{
		if(id[s[i]]<=las) ans++;
		las = id[s[i]];
//		cout<<las<<' ';
	}
	cout<<ans;
	return 0;
}

