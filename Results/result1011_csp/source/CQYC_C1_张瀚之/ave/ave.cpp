#include <bits/stdc++.h>
using namespace std;

int n;
double a[1000005];
double ans;

int main() {
	freopen("ave.in", "r", stdin);
	freopen("ave.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lf", a + i);
	priority_queue<double, vector<double>, greater<double> > pq(a + 1, a + n + 1);
	while (pq.size() > 1) {
        double t = pq.top();
        pq.pop();
        t = (t + pq.top()) / 2.0;
        pq.pop();
        pq.push(t);
	}
	printf("%.6lf", pq.top());
    return 0;
}
