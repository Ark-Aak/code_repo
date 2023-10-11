#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,Q,num[N];
signed main(){
	freopen("easiest.in","r",stdin);
	freopen("easiest.out","w",stdout);
	n=read(),Q=read();
	for(int i=1;i<=n;i++) num[i]=read();
	while(Q--){
		int opt=read();
		int l1=read(),r1=read();
		int l2=read(),r2=read();
		if(opt==1){
			int ans=0;
			for(int i=l1;i<=min(r1,l2-1);i++) ans++;
			int mx=num[r2];
			for(int i=r2+1;i<=r1;i++){
				if(num[i]>mx) mx=num[i];
				else ans++;
			} 
			printf("%lld\n",ans);
		}
	}
	return 0;
}
