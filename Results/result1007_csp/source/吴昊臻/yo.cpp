#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,w[105],ww[105],ans;
string a,b;
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>a>>b;
	if(a[n-1]!='0'&&b[n-1]=='o') return cout<<"oimiya",0;
	for(long long i=0;i<n;i++)
	{
		if(a[i]=='y')y++;
		x=(b[i]-'0');
		if(i%2) x=-x;
		ans+=x;
	}
	if(y==n) cout<<"yoimiya";
	else if(y==0) cout<<"oimiya";
	else if(abs(ans)%11==0) cout<<"yoimiya";
	else cout<<"oimiya";
 } 
