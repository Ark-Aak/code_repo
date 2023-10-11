#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch<'0'||ch>'9')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	} 
	template<typename T>
	inline void write(T x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

const int Maxn=5e5+7,inf=1e9+1;
int n,a[Maxn];
int stk[Maxn],top,l[Maxn],f[Maxn];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);a[0]=inf;
	for(int i=1;i<=n;i++){
		while(top&&a[stk[top]]<=a[i]) top--;
		l[i]=stk[top];
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++){
		//cout<<l[i]<<" ";
		f[i]=f[l[i]]+1;
		write(f[i]);putchar(' ');
	}
	return 0;
}
/*
5
1 2 3 4 5 

7
1 9 1 9 8 1 10
*/
