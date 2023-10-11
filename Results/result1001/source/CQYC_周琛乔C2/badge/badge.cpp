#include<bits/stdc++.h>
using namespace std;
const int N=3505;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,q,l[N],r[N],m,x,ans,o[N];
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	read(n),read(q);
	for(int i=1;i<=n;i++)
		read(l[i]),read(r[i]);
	while(q--){
		memset(o,-1,sizeof(o));
		read(m);ans=0;
		while(m--){
			read(x);
			for(int j=1;j<=n;j++)
				if(l[j]<=x&&x<=r[j]){
					o[j]*=-1;
					ans+=o[j];
				}
		}
		printf("%d\n",ans);
	}
	return 0;
}

