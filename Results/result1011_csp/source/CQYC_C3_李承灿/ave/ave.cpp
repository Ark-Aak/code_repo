#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
double a[1000005]; 
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) a[i]=(a[i]+a[i-1])/2;
	printf("%.6lf",a[n]);
	return 0;
}


