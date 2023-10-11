#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m;
long double ans;
int a[1000005];
signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	ans=(long double)a[1];
	for(int i=2;i<=n;i++){
		ans=(ans+a[i])/2.0;
	}
	cout<<fixed<<setprecision(50)<<ans;
	return 0;
}
