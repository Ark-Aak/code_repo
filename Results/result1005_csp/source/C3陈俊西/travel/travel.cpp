#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=998244353;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,m;
int l[N],r[N],s[N];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read(),k=read(),m=read();
	for(int i=1;i<=m;i++){
		l[i]=read(),r[i]=read();
		s[i]=read();
	}
	if(k==0){
		printf("1");
		return 0;
	}
	return 0;
}
