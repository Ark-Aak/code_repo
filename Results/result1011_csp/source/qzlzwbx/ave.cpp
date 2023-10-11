#include<bits/stdc++.h>
using namespace std;
int n;
double a[1000007];
int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	double ave=a[1];
	for(int i=2;i<=n;i++){
		ave=ave+a[i];
		ave/=2;
	}
	printf("%.6lf",ave);
	return 0;
} 
