#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[10005],f[100005],maxn=0,minn=1e9;
int n,x,ans=0;
double cnt=0;
const int mod=1e12;
int ksm(int u,int y) {
	int www=1;
	while(y) {
		if(y&1) www=(www*u);
		y>>=1;
		u=(u*u);
		if(www>mod) return mod;
	}
	return www;
}
void dfs(double sum,int len,queue<int> Q) {
	if(len==1) {
		cnt+=(double)(Q.front()==x)*sum;
		return ;
	}
	int x1=Q.front();
	Q.pop();
	int x2=Q.front();
	Q.pop();
	queue<int> Q1,Q2;
	Q1=Q;
	Q2=Q;
	Q1.push(x1);
	dfs((double)sum*(double)x1/(double)(x1+x2),len-1,Q1);
	Q2.push(x2);
	dfs((double)sum*(double)x2/(double)(x1+x2),len-1,Q2);
}
void solve(int i) {
	int w=0,l=(i-1)%2,r=(n-i)+(i-1)/2;
	while(l>0 || r>0) {
		if(l==1) l--,w++;
		if(l==0 && r>0) r--,w++;
		l=r%2;
		r=(r/2);
	}
	printf("%0.15lf\n",(double)1/ksm(2,w));
}
signed main() {
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<n;i++) cin>>a[i],minn=min(minn,a[i]),maxn=max(maxn,a[i]);
	minn=min(minn,x);
	maxn=max(maxn,x);
	if(minn!=maxn) {
		for(int i=1;i<=n;i++) {
			cnt=0;
			queue<int> q;
			for(int j=1;j<n;j++) 
				if(i==j) q.push(x),q.push(a[j]);
				else q.push(a[j]);
			if(i==n) q.push(x);
			dfs(1,n,q);
			printf("%.015lf\n",cnt);
		}
	} else {
		for(int i=1;i<=n;i++) solve(i);
	}
	return 0;
}
