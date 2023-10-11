#include<bits/stdc++.h>
using namespace std;
double a[1000005];
int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++) a[i]=(a[i]+a[i-1])/2.0;		
	printf("%lf\n",a[n]);
	return 0;
}

