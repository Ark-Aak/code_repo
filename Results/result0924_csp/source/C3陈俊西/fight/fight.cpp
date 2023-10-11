#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,x,a[N],s[N];
double ans;
void dfs(int l,int r,double res){
	if(l==r){
		if(s[l]==x) ans+=res;
		return;
	}
	
	s[r+1]=s[l];
	dfs(l+2,r+1,res*1.0*(s[l]*1.0)/((s[l]+s[l+1])*1.0));
	
	s[r+1]=s[l+1];
	dfs(l+2,r+1,res*1.0*(s[l+1]*1.0)/((s[l]+s[l+1])*1.0));
}
signed main(){
	freopen("fight.in","r",stdin);
	freopen("fight.out","w",stdout);
	n=read(),x=read();
	for(int i=1;i<n;i++) a[i]=read();
	if(n<=8){
		for(int i=1;i<=n;i++){
			ans=0;
			int j=1;
			for(int k=1;k<=n;k++)
				if(k==i) s[k]=x;
				else s[k]=a[j],j++;
			dfs(1,n,1);
			printf("%.15lf\n",ans);
		}
	}
	else{
		for(int i=1;i<=n;i++)
			printf("1.000000000000000\n");
	}
	return 0;
}
