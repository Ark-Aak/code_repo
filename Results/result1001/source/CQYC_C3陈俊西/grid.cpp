#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t,n,m;
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	t=read();
	while(t--){
		n=read(),m=read();
		if(min(n,m)<=1){
			printf("0\n");
			continue;
		}
		if(min(n,m)==2){
			int ans=0;
			int k=max(n,m);
			for(int i=k-1;i>=1;i--){
				ans=ans+i*k*3;
				ans=ans+(i-1)*i/2*k;
			}
			ans=ans*2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}
/*
3
2 2
2 3
3 2
*/
