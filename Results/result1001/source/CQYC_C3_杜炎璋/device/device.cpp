#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int x,n;
		cin>>x>>n;
		if(n==0) {
			printf("1\n");
			continue;
		} else if(n==1) {
			int x1=x%10,x2=(x/10)%10,x3=(x/100);
			if(x1!=x2 && x2!=x3 && x3!=x1) {
				printf("24\n");
				continue;
			} else if(x1==x2 && x2==x3) {
				printf("1\n");
				continue;
			} else {
				printf("7\n");
				continue;
			}
		} else if(n>1) {
			int x1=x%10,x2=(x/10)%10,x3=(x/100);
			if(x1!=x2 && x2!=x3 && x3!=x1) {
				printf("27\n");
				continue;
			} else if(x1==x2 && x2==x3) {
				printf("1\n");
				continue;
			} else {
				printf("8\n");
				continue;
			}
		}
	}
	return 0;
}

