#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int a[N];
priority_queue<double, vector<double>, greater<double> >q;
int main() {
	freopen("ave.in", "r", stdin);
	freopen("ave.out", "w", stdout);
	int n;
	double ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), q.push(a[i]);
	for(int i = 1; i < n; i++) {
		double p1 = q.top();
		q.pop();
		double p2 = q.top();
		q.pop();
		ans = (p1 + p2) / 2.00;
		q.push(ans);
	}
	printf("%.6lf", ans);
}
/*
(a1 + a2) / 2 + a3
(a1 + a3) / 2 + a2
a1+a2+2a3
a1+a3+2a2

a3 - a2 + 2(a2 - a3)
(a2-a3)*1
a2-a3 < 0
(a1+a2)/2+a3>(a1+a3)/2+a2
*/
