#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int n,x;
double ans;
double a[5010];
void dfs(double s,queue<pair<double,int> > q) {
	//cout <<s  << endl;
	if(q.size() == 1) {
		pair<int,int> x = q.front();
//		cout << x.first << " " << x.second << " "<<s << endl;
		if(x.second == 1) ans += s;
		return ;
	}
	pair<int,int> x,y;
	x = q.front();
	q.pop();
	y = q.front();
	q.pop();
	queue<pair<double,int> > q1;
	q1 = q;
	q.push(x);
	q1.push(y);
//	cout << s << endl;
//	cout << s * (double)x.first /(x.first + y.first) << endl<<endl;
	double aa = (double)x.first / (x.first + y.first);
	double bb = (double)y.first / (x.first + y.first);
	//cout << aa << endl;
	dfs((double)(s * aa),q);
	dfs((double)(s * bb),q1);
}
signed main() {
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	cin >> n >> x;
	for(int i = 1 ; i < n ; i++) read(a[i]);
	if(n <= 8) {
		for(int i = 1 ; i <= n ; i++) {
			ans = 0;
			queue<pair<double,int> > q;
			pair<double,int> y;
			for(int j = 1 ; j < i ; j++) {
				y.first = a[j];
				y.second = 0;
				q.push(y);
			}
			y.first = x;
			y.second = 1;
			q.push(y);
			for(int j = i  ; j < n ; j++) {
				y.first = a[j];
				y.second = 0;
				q.push(y);
			}
			dfs(1,q);
			printf("%.15lf\n",ans);
		}
		return 0;
	}
	double aa = 1,bb = 2;
	ans = 0.5;
	double xx = 0.5;
    for(int i = 1 ; i < log2(n) ; i++)
        ans = (double)(ans * xx);
    for(int i = 1 ; i <= n ; i++){
    	printf("%.15lf\n",ans);
	}
	return 0;
}

