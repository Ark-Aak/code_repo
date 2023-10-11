#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=11;
int n,f[N][mod+5];
char s[N],t[N];
int dfs(int u)
{
	if(!u)return 0;
	int last=dfs(u-1);
	int x=(10*last%mod)%mod,y=(10*last+s[u]-'0')%mod;
	if(t[u]=='y')return min(x,y);
	else return max(x,y);
}
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	memset(f,-1,sizeof f);
	scanf("%d%s%s",&n,s+1,t+1);
	if(!dfs(n))puts("yoimiya");
	else puts("oimiya");
	return 0;
}
