#include <bits/stdc++.h>
#define gc getchar
#define pc putchar
#define pt printf
#define For(i,a,b) for(int i=a;i<=b;++i)
#define Rof(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int T,K,N;
int _() {
	int x=0,f=0;char ch=gc();
	while(ch<'0'||ch>'9') f|=(ch=='-'),ch=gc();
	while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	return f?-x:x;
}
void __(int x) {
	int stk[30],tp=0;
	if(x<0) x=-x,pc('-');
	do stk[++tp]=x%10,x/=10;while(x);
	while(tp) pc(stk[tp--]^48);
}
/*
3
123 0
123 1
999 100
*/
signed main() {
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	T=_();
	while(T--) {
		K=_(),N=_();
		int a=K%10,b=(K/10)%10,c=K/100;
		if((a==b&&b==c)||N==0) pt("1\n");
	}
	return 0;
}
