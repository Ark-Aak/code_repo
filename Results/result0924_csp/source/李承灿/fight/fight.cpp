#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x;
int a[5000];
signed main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	scanf("%lld %lld",&n,&x);
	for(int i=1;i<n;i++) scanf("%lld",&a[i]);
	double h=n;
	for(int i=1;i<=n;i++) printf("%.11lf\n",(double)(1/h));
	return 0;
}
