#include<bits/stdc++.h>
#define int long long
#define inf 1000000000000000
using namespace std;
const int N=1e6+5;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
void write(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int f[N][2],g[N][2];
int a[N],sum[N],vis[N],ans[N],tot;

int n,k; 
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum[i]=sum[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=f[0][1]=0;
	if(n/k*n<=100000000){
		int s=n,op=0,ans=0;
		while(s>1){
			int l=0,r=0,mi=1e18,mx=0;
			for(int i=1;i+k-1<=n;i++){
				
				int j=i+k-1;
				if(vis[i] || vis[j]) continue;
				if(op%2==0){
					if(sum[j]-sum[i-1]<mi) mi=sum[j]-sum[i-1],l=i,r=j;
				}
				else if (op%2==1){
					if(sum[j]-sum[i-1]>mx) mx=sum[j]-sum[i-1],l=i,r=j;
				}
			}
			for(int i=l;i<=r;i++){
				vis[i]=1;
			}
			if(r==l && r==0) continue;
			s-=k;
			ans+=sum[r]-sum[l-1];
			op++;
		}
		write(ans);
	}else{
		for(int i=1;i<=n;i+=k){
			ans[++tot]=a[i];
		} 
		cout << sum[n]-ans[tot/2+1];
	}
	

	return 0;
}
/*
11 5
1 9 1 9 8 1 1 1 1 4 5
2 5 9 4
*/

