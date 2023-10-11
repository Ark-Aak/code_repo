#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,k,n,ans;
int a[5];
signed main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&k,&n);
		if(n==0){
			printf("1\n");
			continue;
		}
		a[1]=k/100;a[2]=k/10%10;a[3]=k%10;
		if(a[1]!=a[2]&&a[1]!=a[3]&&a[2]!=a[3]){
			if(n==1) printf("24\n");
			else printf("27\n");
		}
		else if((a[1]==a[2]&&a[2]!=a[3])||(a[1]==a[3]&&a[1]!=a[2])||(a[2]==a[3]&&a[1]!=a[2])){
			if(n==1) printf("7\n");
			else printf("8\n");
		}
		else printf("1\n");
	}
	return 0;
}


