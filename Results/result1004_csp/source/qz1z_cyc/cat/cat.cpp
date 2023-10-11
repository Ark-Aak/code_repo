#include<bits/stdc++.h>
using namespace std;
long long n,L[505][505],U[505][505],ans=1,ans1,p=998244353,kl,C[505][505],kla,v[505][505],go1[505][505],go2[505][505];
long long vis1[505][505],vis2[505][505];
char a[505][505];
long long kuai(long long pp,long long x)
{
	long long h1=1;
	while(pp>1)
	{
		if(pp%2==1) h1=(x*h1)%p;
		x=(x*x)%p;
		pp/=2;
	}
	return (h1*x)%p;
}
long long ny(long long x,long long y)
{
	return (x*kuai(p-2,y))%p;
}
int main() {
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin>>n;
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=n; j++) {
			cin>>a[i][j];
			L[i][j]=L[i][j-1];
			U[i][j]=U[i-1][j];
			if(a[i][j]=='L') L[i][j]++;
			if(a[i][j]=='U') U[i][j]++;
		}
	}
	C[0][0]=1;
	for(long long i=0; i<=n; i++) {
		C[i][i]=1;
		for(long long j=i+1; j<=n; j++) {
			C[i][j]=ny((C[i][j-1]*j),(j-i));
		}
	}
	for(long long i=1; i<=n; i++) {
		ans1=0;
		for(long long j=n; j>=1; j--) {
			if(a[i][j]=='R') {
				kl=0;
				for(long long k=0; k<=min(ans1,L[i][n]-L[i][j]); k++) {
					kl+=((L[i][n]-L[i][j]-k+1)*C[k][L[i][n]-L[i][j]])%p;
				}
				ans1++;
				go1[i][j]=kl;
				ans=(ans*kl)%p;
			}
		}
	}
	for(long long j=1;j<=n;j++) {
		ans1=0;
		for(long long i=n; i>=1; i--) {
			if(a[i][j]=='D') {
				kl=0;
				for(long long k=0; k<=min(ans1,U[n][j]-U[i][j]); k++) {
					kl+=((U[n][j]-U[i][j]-k+1)*C[k][U[n][j]-U[i][j]])%p;
				}
				ans1++;
				go2[i][j]=kl;
				ans=(ans*kl)%p;
			}
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			cin>>v[i][j];
			vis1[i][j]=vis1[i][j-1];vis2[i][j]=vis2[i-1][j];
			if(a[i][j]=='L') vis1[i][j]==(vis1[i][j]+v[i][j])%p;
			if(a[i][j]=='U') vis2[i][j]==(vis2[i][j]+v[i][j])%p;
		}
	}
	for(long long i=1;i<=n;i++)
	{	
		for(long long j=1;j<=n;j++)
		{
			if(a[i][j]=='R') kla+=((v[i][j]*(ny(ans,go1[i][j]))*(L[i][n]-L[i][j]))%p+((vis1[i][n]-vis1[i][j])*(ans/go1[i][j]))%p)%p;
		}
	}
	for(long long i=1;i<=n;i++)
	{	
		for(long long j=1;j<=n;j++)
		{
			if(a[i][j]=='D') kla+=((v[i][j]*(ny(ans,go2[i][j]))*(U[n][j]-U[i][j]))%p+((vis2[n][j]-vis2[i][j])*(ans/go2[i][j]))%p)%p;
		}
	}
	cout<<kla%p;
	return 0;
}

