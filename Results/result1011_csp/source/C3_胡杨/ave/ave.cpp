#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
priority_queue<double, vector<double>,greater<double> > q;
int n;
double ans;
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
    read(n);
    for(int i = 1 ; i <= n ; i++){
    	double x;
    	cin >> x;
    	q.push(x);
	}
	while(q.size() > 1){
		double x = q.top();
		q.pop();
		double y = q.top();
		q.pop();
		ans = (double)(x + y) / 2.0;
		q.push(ans);
	}
	printf("%.6lf", q.top());
	return 0;
}

