#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,k,a[N],b[N],ans,sum;
void solve(int id){
	b[id]=0;
	sum--;
	for(int i=1;i<id;i++) b[i]++;
	for(int i=1;i<id;i++) 
		if(b[i]==i) solve(i);
}
void dfs(int dep){
	if(dep==n+1){
		sum=0;
		for(int i=1;i<=n;i++)
			b[i]=a[i],sum+=b[i];
		for(int i=1;i<=n;i++)
			if(b[i]==i) solve(i);		
		ans+=sum;
		return;
	}
	for(int i=0;i<=k;i++)
		a[dep]=i,dfs(dep+1);
	return;
}
signed main(){
//	fc C:\Users\HP\Desktop\T\network2.out C:\Users\HP\Desktop\T\network2.ans
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=read(),k=read();
	dfs(1);
	printf("%lld",ans);
	return 0; 
}
