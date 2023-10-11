#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,res,ans;
char str[N];
int pos[N][30];
int main()
{
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	scanf("%s",str+1);
	n=strlen(str+1);
	int p=1,cur=1;
	for(int i=1;i<=n;i++)
	{
		if(pos[cur][str[i]-'a'])
		{
			cur++;
			p=1;
		}
		pos[cur][str[i]-'a']=p++;
	}
	for(int i=2;i<=cur;i++)
	{
		for(int x=0;x<26;x++)
		{
			if(!pos[i-1][x]||!pos[i][x])continue;
			for(int y=x+1;y<26;y++)
			{
				if(!pos[i-1][y]||!pos[i][y])continue;
				if((pos[i-1][x]<pos[i-1][y]&&pos[i-1][x]>pos[i-1][y])||(pos[i-1][x]>pos[i-1][y]&&pos[i-1][x]<pos[i-1][y]))ans++;
			}
		}
	}
	printf("%d",cur+ans);
	return 0;
}
