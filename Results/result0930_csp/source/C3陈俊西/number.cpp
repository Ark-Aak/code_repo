#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int l,r,n,num,ans,maxn;
int ksm(int x,int y){
	int res=1;
	while(y){
		if(y&1) res=res*x;
		x=x*x;
		y>>=1;
	}
	return res;
}
int f(int x,int i,int j){
	return (x/ksm(10,j-1))%ksm(10,i);
}
void dfs(int dep){
	if(dep==n+1){
		int rs=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(f(num,i,i)&&f(num,i,j)>=l&&f(num,i,j)<=r) rs++;
		if(rs>maxn) maxn=rs,ans=num;
		return;
	}
	for(int i=0;i<=9;i++) num=num*10+i,dfs(dep+1),num/=10;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	l=read(),r=read(),n=read();
	dfs(1);
	printf("%lld\n%lld",maxn,ans);
	return 0;
}
