#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,Q,m,ans[N];
struct node{
	int l,r;
}a[N];
signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	n=read(),Q=read();
	for(int i=1;i<=n;i++)
		a[i].l=read(),a[i].r=read();
	while(Q--){
		int res=0;
		m=read();
		for(int i=1;i<=n;i++) ans[i]=0;
		for(int i=1;i<=m;i++){
			int x=read();
			for(int j=1;j<=n;j++){
				if(x>=a[j].l&&x<=a[j].r){
					if(ans[j]==1) res--;
					else res++;
					ans[j]^=1;
				}					
			}
		}	
		printf("%lld\n",res);
	}
	return 0;
}
/*
5 2
4 5
3 5
2 4
2 3
5 5
2
2 5
3
1 2 5
*/
