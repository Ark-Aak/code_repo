#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define F(i,a,b) for(int i=a;i<=b;i++)
inline int read();

const int N=1e3+5;

int n;

char a[N][N];

signed main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	n=read();	
	F(i,1,n)
	F(j,1,n) 
	cin>>a[i][j];
	srand(time(0));
	cout<<rand();
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'&&c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
