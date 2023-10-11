#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,a[N],ans;

signed main(){
//	fc C:\Users\HP\Desktop\T\network2.out C:\Users\HP\Desktop\T\network2.ans
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++) a[i]=read();
	
	return 0; 
}
