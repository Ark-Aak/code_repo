#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,k;
inline ll Count(ll x){
	ll cnt=3;
	ll a=x%10,b=x/10%10,c=x/100;
	cnt=cnt-(a==b)-(b==c)-(a==c)+(a==b&&c==b);
	return cnt;
}
int main(){
	freopen("device2.in","r",stdin);
	freopen("device.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&k,&n);
		if(n==0){
			printf("1\n");
			continue;
		}
		if(n==1){
			if(Count(k)==1){
				printf("1\n");
			}
			if(Count(k)==2){
				printf("7\n");
			}
			if(Count(k)==3){
				printf("24\n");
			}
		}
		if(n>=2){
			if(Count(k)==1){
				printf("1\n");	
			}
			if(Count(k)==2){
				printf("8\n");
			}
			if(Count(k)==3){
				printf("27\n"); 
			}
		}
	}
	return 0;
}
/*
3
123 0
123 1
999 100
*/ 
