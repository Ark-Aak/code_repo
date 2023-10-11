#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
inline int read();

const int N = 2e5+5;

int n,Mod;

signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read(),Mod=read();
	if(n%2==1){
		int ans = 1ll;
		for(int i=1;i<=n;i++) ans*=i,ans=(ans+Mod)%Mod;
		cout<<ans;
		return 0;
	}
	while(1);
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
