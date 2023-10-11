#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e5+5,Mod=147744151;

inline int read();

long long n,k,ans;

signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		cout<<n/2;
		return 0;
	}
	if(k>=147744151){
		cout<<int(log2(n));
		return 0;
	}
	if(k==2){
		ans=(sqrt(n*2)+Mod);
		cout<<ans%Mod;
		return 0;
	}
	//if(k==
	return 0;
}


inline int read() {
	long long x=0,f=1;
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



