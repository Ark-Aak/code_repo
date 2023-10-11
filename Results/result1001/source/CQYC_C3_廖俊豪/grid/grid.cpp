#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
int g[1005][1005];
int ans=0;
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	int T;
	scanf("%lld",&T);
	for(int i=1;i<=1000;i++)
		for(int j=1;j<=1000;j++)
			g[i][j]=__gcd(i,j);
	while(T--){
		scanf("%lld %lld",&n,&m);
		if(n<m)swap(n,m);
		if(m==1){
			printf("0\n");
		}else if(m==2){
			printf("%lld\n",(((n*n*(n+1)/2)+n*n-(n*(n+1)/2)-(n*(n+1)*(2*n+1)/6))*n+n*n*(n-1)/2)*2);
		}else{
			ans=0;
			for(int x_1=1;x_1<=n;x_1++)
			for(int y_1=1;y_1<=m;y_1++)
			for(int x_2=1;x_2<=n;x_2++)
			for(int y_2=1;y_2<=m;y_2++)
			for(int x_3=1;x_3<=n;x_3++)
			for(int y_3=1;y_3<=m;y_3++){
				if((x_1==x_2&&y_1==y_2)||(x_1==x_3&&y_1==y_3)||(x_3==x_2&&y_3==y_2))continue;
				if(((x_1-x_2)*(y_2-y_3)==(x_2-x_3)*(y_1-y_2))||((x_2-x_3)*(y_3-y_1)==(x_3-x_1)*(y_2-y_3))||((x_2-x_3)*(y_3-y_1)==(x_3-x_1)*(y_2-y_3)))continue;
				int res1=__gcd(abs(x_1-x_2),abs(y_1-y_2));
				int res2=__gcd(abs(x_1-x_3),abs(y_1-y_3));
				int res3=__gcd(abs(x_3-x_2),abs(y_3-y_2));
				ans=ans+res1+res2+res3;
			}
			printf("%lld\n",ans/6);
		}
	}
	return 0; 
} /*
5
17 5
6 20
11 14
16 1
9 12
*/
