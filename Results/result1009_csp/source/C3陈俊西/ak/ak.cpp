#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,sum,v[N],s[N],tp;
signed main(){
//	fc C:\Users\HP\Desktop\T\ex_tower1.out C:\Users\HP\Desktop\T\ex_tower1.ans
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++) v[i]=read(),sum=sum+v[i];
	for(int i=1;i<=n;i++){
		int a=i-1,b=n-i;
		if((!(a%k))&&(!(b%k))) s[++tp]=v[i];
	}
	sort(s+1,s+1+tp);
	printf("%lld",sum-s[tp/2+1]);
	return 0; 
}
/*
5 2
3 5 3 2 1
*/
