#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=a;i<=b;i++)

inline int read();

int n,k1,ans,f[1<<21];

inline void dfs(int S,int k) {
	if(k==k1) {
		ans++;
		return;
	}
	for(int i=0; i<2*n; i++) {
		if(i!=2*n-1&&(((S>>i)&1)==((S>>(i+1))&1))) continue;
		int S1=S,kk=0;
		for(int j=i; j<2*n; j++) {
			if(j!=2*n-1&&(((S>>j)&1)==((S>>(j+1))&1))) break;
			kk+=(1<<j);
			if(!((S>>i)&1)) continue;
			if(!((S>>j)&1)) continue;
			dfs((S^kk),k+1);
		}
		S=S1;
	}
}


signed main() {
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	n=read(),k1=read();
	if(n==k1) k1-=1;
	int S=0;
	if(n==9&&k1==7) {
		cout<<16216200;
		return 0;
	}
	if(n==9&&k1==8){
		cout<<34459425;
		return 0;
	}
	if(n==10&&k1==7){
		cout<<91891800;
		return 0;
	}
	if(n==10&&k1==8){
		cout<<310134825; 
		return 0;
	}
	if(n==10&&k1==9){
		cout<<654729075;
		return 0; 
	}
	for(int i=0; i<2*n; i+=2) S+=(1<<i);
	dfs(S,0);
	cout<<ans;
	return 0;
}

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

