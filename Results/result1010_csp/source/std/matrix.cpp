#include<bits/stdc++.h>
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
#define regsiter register
#define CL fclose(stdin),fclose(stdout)
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
char s[222222];
long long cnt[4444444];
long long f[4444444];
int d[222222];
void D(long long* a,int n){
	n=1<<n;
	for(int T=1;T<n;T<<=1)
		for(int i=0;i<n;i+=T+T)
			for(int j=0;j<T;++j)
			{
				long long t1=a[i+j]+a[i+j+T];
				long long t2=a[i+j]-a[i+j+T];
				a[i+j]=t1;
				a[i+j+T]=t2;
			}
}
void ID(long long* a,int n){
	n=1<<n;
	for(int T=n/2;T;T>>=1)
		for(int i=0;i<n;i+=T+T)
			for(int j=0;j<T;++j){
				long long t1=a[i+j]+a[i+j+T]>>1;
				long long t2=a[i+j]-a[i+j+T]>>1;
				a[i+j]=t1;
				a[i+j+T]=t2;
			}
}
int main(){
	freopen("matrix.in","r",stdin) ;
	freopen("matrix.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<(1<<n);++i)f[i]=f[i-(i&-i)]+1;
	for(int i=1;i<(1<<n);++i)cmin(f[i],n-f[i]);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			if(s[j]=='1')d[j]|=1<<i-1;
	}
	for(int i=1;i<=m;++i)cnt[d[i]]++;
	D(cnt,n);
	D(f,n);
	for(int i=0;i<(1<<n);++i)f[i]*=cnt[i];
	ID(f,n);
	long long min=n*m;
	for(int i=0;i<(1<<n);++i)cmin(min,f[i]);
	printf("%lld\n",min);
	return 0;
}



