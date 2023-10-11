#include<bits/stdc++.h>
using namespace std;
priority_queue<double,vector<double>,greater<double> >q;
int n; 
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		int x;
		scanf("%d",&x);
		q.push(x);
	}
	while(q.size()>1)
	{
		double a=q.top();
		q.pop();
		double b=q.top();
		q.pop();
		q.push((a+b)/2);
	} 
	printf("%.6lf",q.top());
	return 0;
}
