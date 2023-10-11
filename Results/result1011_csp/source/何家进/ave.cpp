#include<bits/stdc++.h>
using namespace std;
int n;
int x[1000005];
priority_queue<double>q;
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]),q.push(-x[i]);
	while(!q.empty())
	{
		double x=q.top();
		q.pop();
		double y=q.top();
		q.pop();
		q.push((x+y)/2);
	}
	double ans=-q.top();
	printf("%.6lf",ans);
	return 0;
}
