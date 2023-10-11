#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
int a[3];
int C[15][15],A[4];
signed main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	int T;
	scanf("%lld",&T);
	A[1]=1;A[2]=2;A[3]=6;
	C[0][0]=1;
	for(int i=1;i<=3;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	while(T--){
		for(int i=0;i<3;i++)scanf("%1lld",&a[i]);
		scanf("%lld",&n);
		if(n==0){
			printf("1\n");
			continue; 
		}
		sort(a,a+3);
		int tmp=1,ans=0;
		for(int i=1;i<3;i++)if(a[i]!=a[i-1])tmp++;
		if(tmp==1){
			ans=1;
		}else if(tmp==2){
			if(n==1)ans=7;
			else ans=8;
		}else{
			if(n==1)ans=24;
			else ans=27;
		}
		printf("%lld\n",ans);
	}
	return 0;
}/*
3
123 0
123 1
999 100
*/
