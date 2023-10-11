#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m;
char str[N][N];
int check(char &a,char &b,char &c,char &d)
{
	if((a==d&&b==c&&a=='0'&&b=='1')||(a==d&&b==c&&a=='1'&&b=='0'))return 0;
	if(a==d&&a!='?')
	{
		if(a!=b&&b!='?'&&c=='?')c=a;
		if(a!=c&&c!='?'&&b=='?')b=a;
	}
	if(b==c&&b!='?')
	{
		if(b!=a&&a!='?'&&d=='?')d=b;
		if(b!=d&&d!='?'&&a=='?')a=b;
	}
	return 1;
}
int main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	for(int cases=1;cases<=10;cases++)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(!check(str[i][j],str[i][j+1],str[i+1][j],str[i+1][j+1]))
				{
					puts("No");
					return 0; 
				}
			}
		}
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i>1&&j>1)check(str[i-1][j-1],str[i-1][j],str[i][j-1],str[i][j]);
			if(i>1&&j<m)check(str[i-1][j],str[i-1][j+1],str[i][j],str[i][j+1]);
			if(str[i][j]=='?')str[i][j]='0';
			printf("%c",str[i][j]);
		}
		puts("");
	}
	return 0;
}
