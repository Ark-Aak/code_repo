#include<bits/stdc++.h>
using namespace std;

#define int long long

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e5+5;

inline int read();

int n,a[N];

signed main(){
	//freopen(".in","r",stdin);
	system("fc jump.out ex_jump.out"); 
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



