#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
		x=x*10+c-'0',c=getchar();
	return x*f;
}
/*
struct XXX{
	int num,flr,times;
}z[500005];*/
int a[500005];
int f[500005];
int b[500005];
int st[500005],tp=1,tail=0;
int num[500005];
signed main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	int n=read(),k=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	memset(f,0x3f,sizeof(f));
	if(n*k<=2e7){
		f[0]=0;
		int ans=1e16;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+(n-i+1)*(a[i]-1)*2;
			for(int j=i-1;j>=max(i-k,0ll);j--){	
				f[i]=min(f[i],f[j]+(n-j)*(a[i]-1)*2);
			}
		}
		cout<<f[n];
		return 0;
	}
	else{
		
		f[0]=0;
		for(int i=1;i<=n;i++){
			f[i]=f[i-1]+(n-i+1)*(a[i]-1)*2;
			if(a[i]==a[i-1]){
				int j=i-1;
				int gg=f[j]+(n-j)*(a[i]-1)*2;
				while(st[tail]>=gg&&tail>=tp) tail--; 
				st[++tail]=gg;
				num[tail]=j;
				while(num[tp]<max(i-k,0ll)&&tp<=tail) tp++;
				f[i]=min(f[i],st[tp]);
			}
			else{
				tp=1;
				tail=0;
				for(int j=max(i-k,0ll);j<i;j++){	
					int gg=f[j]+(n-j)*(a[i]-1)*2;
					while(st[tail]>=gg&&tail>=tp) tail--;
					st[++tail]=gg;
					num[tail]=j;
					f[i]=min(f[i],gg);
				}
				
			}
		}
		cout<<f[n];
		return 0;
	}
	return 0;
}

