#include<bits/stdc++.h>
using namespace std;
int t,k,n;
int a[5];
int main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&k,&n);
		a[1]=k%10;a[2]=(k/10)%10;a[3]=k/100;
		sort(a+1,a+1+3);
		if(a[1]==a[2]&&a[2]==a[3]||n==0)printf("1\n");
		if(a[1]==a[2]&&a[2]!=a[3]||a[2]==a[3]&&a[2]!=a[1]){
			if(n<3)printf("7\n");
			else printf("8\n");
		}
		if(a[1]!=a[2]&&a[2]!=a[3]){
			if(n<3)printf("24\n");
			else printf("27\n");
		}
	}
	return 0;
}

