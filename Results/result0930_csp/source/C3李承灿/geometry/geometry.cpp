#include<bits/stdc++.h>
#define int long long
using namespace std;
double a,b;
double x,y,ans;
int p=5000000;
signed main(){
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	scanf("%lf %lf",&a,&b);
	if(a==b*2){
		printf("%.12lf",b*3);
		return 0;
	}
	if((int)(a/b)*b==a){
		printf("%.12lf",(a-b)*3);
		return 0;
	}
	x=max(a-b,b),y=min(a-b,b);
	while(p--){
		ans+=((int)(x/y))*y*3;
		a=x,y=b;
		if((int)(x/y)*y==x) break;
		x=max(a-b,b),y=min(a-b,b);
	}
	if((int)(x/y)*y==x) cout<<ans;
	else printf("-1");
	return 0;
}


