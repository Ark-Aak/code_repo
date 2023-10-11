#include<bits/stdc++.h>
using namespace std;
string s;
int n, a[100005], x[100005], id, ans, b[100005];
double delta = 0.93;
void init() {
	for(int i = 1; i <= id ;++i) {
		x[i] = i;
	}
	for(int i = 1; i <= n; ++i) {
		b[i] = lower_bound(a + 1, a + id + 1, b[i]) - a;
	}
	ans = 1;
	for(int i = 2; i <= n; ++i) {
		if(x[b[i]] <= x[b[i - 1]]) {
			ans++;
		}
	}
	return;
}
int js() {
	int sum = 1;
	for(int i = 2; i <= n; ++i) {
		if(x[b[i]] <= x[b[i - 1]]) {
			sum++;
		}
	}
	return sum;
}
void SA() {
	double T = 3000;
	while(T >= 1e-3) {
		int X = rand() % id + 1;
		int Y = rand() % id + 1;
		swap(x[X], x[Y]);
		double cnt = js();
		if(cnt < ans)	ans = cnt;
		else if(exp(ans - cnt) < (rand() - RAND_MAX) / T)	swap(x[X], x[Y]);
		T *= delta;
	}
	return; 
}
int main() {
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	srand(11451414);
	cin>>s;
	n = s.size();
	for(int i = 0; i < s.size(); ++i) {
		a[i + 1] = s[i] - 'a' + 1;
		b[i + 1] = a[i + 1];
	}
	sort(a + 1, a + n + 1);
	id = unique(a + 1, a + n + 1) - a - 1;
	init();
	int sa = 10;
	while(sa--)	SA();
	cout<<ans;
	return 0;
}
