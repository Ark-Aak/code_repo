#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue< double,vector<double>,greater<double> > q;
int n;
double x,y;
int main() {
	freopen("ave.in", "r", stdin);
	freopen("ave.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>x;
		q.push(x);
	}
	while(q.size()>1) {
		x=q.top();
		q.pop();
		y=q.top();
		q.pop();
		q.push((x+y)*0.5);
	}
	printf("%.6f",q.top());
	return 0;
}

