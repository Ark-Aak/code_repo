#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
const int Inf=1e9+7;
int n;
int a[500005];
int s[500005],tot;
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	s[++tot]=Inf;
	for(int i=1;i<=n;i++){
		while(a[i]>=s[tot]&&tot>0)tot--;
		printf("%d ",tot);
		s[++tot]=a[i]; 
	} 
	return 0;
} 
