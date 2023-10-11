#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;

queue <int > q;

int a[N], n, k,win;

double ans;

void dfs(queue<int> Q,double gl){
	if(Q.size()==1){ ans+=gl; return;}
	else{
		int x=Q.front();Q.pop();
		int y=Q.front();Q.pop();
		if(x==k){
			Q.push(x);
			dfs(Q,gl*double(double(x)/double(x+y)));
		}
		else if(y==k){
			Q.push(y);
			dfs(Q,gl*double(double(y)/double(x+y)));
		}else{
			queue <int> z; 
			z=Q;
			Q.push(x);
			dfs(Q,gl*double(double(x)/double(x+y)));
			z.push(y);
			dfs(z,gl*double(double(y)/double(x+y)));
		}
	}
	return;
}

inline void Subtask1() {
	for (int i = 1; i <= n; i++) {
		ans = 0 ;
		for(int j=1;j<i;j++) q.push(a[j]);
		q.push(k);
		for(int j=i;j<n;j++) q.push(a[j]);
		dfs(q,1);
		while (!q.empty()) q.pop();
		printf("%.16lf \n",ans);
	}

}

inline double ksm(double a,int b){
	double aa =a; 
	while(b){
		if(b&1) a*=aa;
		b>>=1;
		aa*=aa;
	}
	return a;
}

signed main() {
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	cin >> n >> k;
	for (int i = 1; i < n; i++) cin >> a[i];
	if (n <= 8) {
		Subtask1();
		return 0;
	} else {
		ans=ksm(0.5,n-2);
		for(int i=1;i<=n;i++) printf("%.16lf\n",ans);
	}
	return 0;
}
