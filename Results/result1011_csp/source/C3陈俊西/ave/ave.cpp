#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n;
double a[N];
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) scanf("%lf",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) a[i]=1.0*(a[i-1]+a[i])*0.5;
	printf("%.6lf",a[n]);
	return 0;
}
