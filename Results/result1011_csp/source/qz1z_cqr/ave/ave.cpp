//O(n) 100pts
//wait to test... -OK
#include<bits/stdc++.h>
using namespace std;
int n,l;
double x[1000005];
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&l);x[i]=l;}
	sort(x+1,x+1+n);
	//for(int i=1;i<=n;i++)
	//	printf("%.1lf ",x[i]);printf("\n");
	for(int i=1;i<n;i++)
		x[i+1]=(x[i+1]+x[i])/((double)2.0);
	printf("%.6lf",x[n]);
	return 0;
}

