#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k;
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	n=read(),k=read();
	printf("%lld",n-1);
	return 0;
}
