#include<bits/stdc++.h>
#define int long long
#define x first
#define y second 
#define y1 ____
#define y2 _____
using namespace std;
int t,n;
vector<int> vec;
vector<pair<pair<int,int>,pair<int,int>>> s;
#define add(x1,y1,x2,y2) (s.push_back({{x1,y1},{x2,y2}}))
inline void work(int val)
{
	add(n-1,n+1,n,n+1);
	add(n-2,n+3,n-1,n+3);
	add(n+1,n+2,n+1,n+3);
	add(n,n+4,n+1,n+4);
	add(n+2,n,n+3,n);
	add(n+2,n+1,n+3,n+1);
	add(n,n+2,n,n+3);
	add(n+3,n-2,n+3,n-1);
	add(n+4,n,n+4,n+1);
	if(val<3) add(n+1,n-1,n+1,n);
	else val-=3;
	if(val==0) add(n-1,n+2,n,n+2);
	if(val<=1) add(n+2,n-1,n+2,n);
	n+=2; 
}
signed main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>t;
	while(t) vec.push_back(t%6),t/=6;
	n = 2;
	add(1,2,2,2),add(2,1,2,2);
	if(vec.size() > 0)
		for(int i = vec.size()-1;~i;i--) work(vec[i]);
	cout<<n<<' '<<n<<'\n';
	int k = s.size();
	for(auto i:s) if(i.x.x<1||i.x.x>n||i.x.y<1||i.x.y>n||i.y.x<1||i.y.x>n||i.y.y<1||i.y.y>n) k--;
	cout<<k<<'\n';
	for(auto i:s)
	{
		if(i.x.x<1||i.x.x>n||i.x.y<1||i.x.y>n||i.y.x<1||i.y.x>n||i.y.y<1||i.y.y>n) continue;
		cout<<i.x.x<<' '<<i.x.y<<' '<<i.y.x<<' '<<i.y.y<<'\n';
	}
	return 0;
}

