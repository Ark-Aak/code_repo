#include <bits/stdc++.h>
#define int long long
using namespace std;
string l,r,ans,now;
int n,ans_s;
bool cmp(string x,string y)
{
	if(x.size()!=y.size()) return x.size()<y.size();
	return x<=y;
}
void dfs(int x,int sum)
{
	if((sum+(n-x+1)*(r.size()-l.size()+1))<=(ans_s)) return;
//	if(now[0]=='1') cout<<now<<' '<<sum<<'\n';
	if(x>=n)
	{
//		int sum = get();
		if(sum>ans_s) ans = now,ans_s = sum;
//		else if(sum==ans_s) ans = min(ans,now);
		return;
	}
	for(int i = '0';i<='9';i++)
	{
		now[x] = i;
		int tmp = sum;
		string sub = "";
		for(int j = x;j>=0;j--)
		{
			sub = now[j]+sub;
			bool v1 = cmp(l,sub),v2 = cmp(sub,r);
			if(v1&&v2) sum++;
			if(v2==0) break;
		}
		dfs(x+1,sum);
		sum = tmp;
	}
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>l>>r>>n;
	now.resize(n+1);
	dfs(0,0);
	cout<<ans_s<<'\n'<<ans;
	return 0;
}

