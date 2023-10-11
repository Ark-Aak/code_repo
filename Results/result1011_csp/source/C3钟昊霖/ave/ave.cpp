#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
inline int read();

const int N = 1e6+5;

int n,a[N];
double ans=0;

signed main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	ans = a[1];
	for(int i=2;i<=n;i++)
	ans=(ans+a[i])/2;
	printf("%.6lf",ans);
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

