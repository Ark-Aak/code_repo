#include<bits/stdc++.h>
using namespace std;
inline void read(int &x){
	int f=1;x=0;char c=getchar();
	while(!isdigit(c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,a[1000005];
double ans;
int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	ans=a[1];
	for(int i=2;i<=n;i++)
		ans=(ans+a[i])/2.0;
	printf("%.6lf",ans);
	return 0;
}

