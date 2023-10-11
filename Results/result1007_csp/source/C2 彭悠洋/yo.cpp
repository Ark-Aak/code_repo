#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+5;
int n,f[N][11];
string s,t;
bool dfs(int x,int now)
{
	if(f[x][now]!=-1) return f[x][now];
	if(x>n) return f[x][now] = (now%11==0);
	bool res1 = dfs(x+1,(now*10)%11),res2 = dfs(x+1,(now*10+s[x]-48)%11);
	if(t[x]=='o') return f[x][now] = (res1&&res2);
	else return f[x][now] = (res1||res2);
}
signed main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>s>>t;
	s = ' '+s,t = ' '+t;
//	if(t[n]=='o') return puts("oimiya");
	memset(f,-1,sizeof f);
	if(dfs(1,0)) puts("yoimiya");
	else puts("oimiya");
	return 0;
}

