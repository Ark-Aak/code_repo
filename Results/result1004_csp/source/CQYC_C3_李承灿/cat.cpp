#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n;
int w[502][502];
int a[502][502];
int rr[502][502],ll[502][502],dd[502][502],uu[502][502];
int wr[502][502],wl[502][502],wd[502][502],wu[502][502];
int L[502],U[502],suml[502],sumu[502]; 
int R,D,sumr,sumd;
int f[502],h[502];
char s;
int p[502],q[502];
int r(int x,int y){
	x%=mod;
	int z=1;
	while(y){
		if(y&1) z=z*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return z;
}
int C(int n,int m){
	return f[n]*h[m]%mod*h[n-m]%mod;
} 
int k(int x){
	int res=0;
	for(int i=1;i<x;i++) res+=C(x-1,i),res%=mod;
	return res;
}
int o(int x){
	return (r(2,x)+mod-1-x)%mod;
}
signed main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	scanf("%lld",&n);
	f[0]=h[0]=1;
	for(int i=1;i<=n;i++) f[i]=f[i-1]*i%mod;
	h[n]=r(f[n],mod-2);
	for(int i=n-1;i>=1;i--) h[i]=h[i+1]*(i+1)%mod; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>s;
			if(s=='R') a[i][j]=1,rr[i][j]=1;
			else if(s=='L') a[i][j]=2,ll[i][j]=1;
			else if(s=='D') a[i][j]=3,dd[i][j]=1;
			else a[i][j]=4,uu[i][j]=1;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&w[i][j]);
			if(a[i][j]==1) wr[i][j]=w[i][j];
			else if(a[i][j]==2) wl[i][j]=w[i][j];
			else if(a[i][j]==3) wd[i][j]=w[i][j];
			else wu[i][j]=w[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			rr[i][j]+=rr[i][j-1];rr[i][j]%=mod;
			ll[i][j]+=ll[i][j-1];ll[i][j]%=mod;
			wr[i][j]+=wr[i][j-1];wr[i][j]%=mod;
			wl[i][j]+=wl[i][j-1];wl[i][j]%=mod;
			dd[i][j]+=dd[i-1][j];dd[i][j]%=mod;
			uu[i][j]+=uu[i-1][j];uu[i][j]%=mod;
			wd[i][j]+=wd[i-1][j];wd[i][j]%=mod;
			wu[i][j]+=wu[i-1][j];wu[i][j]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]==1){
				L[i]+=wl[i][n]-wl[i][j];L[i]%=mod;
				L[i]+=(ll[i][n]-ll[i][j])*w[i][j]%mod;L[i]%=mod;
				suml[i]+=ll[i][n]-ll[i][j];suml[i]%=mod;
			}
			else if(a[i][j]==2){
				int s=rr[i][j];
				if(!q[s]) q[s]=k(s),p[s]=o(s);
				L[i]=(L[i]+mod-wr[i][j]*q[s]%mod)%mod;
				L[i]=(L[i]+p[s]*w[i][j])%mod;
				suml[i]=(suml[i]+mod-p[s])%mod;
			}
			else if(a[i][j]==3){
				U[j]+=wu[n][j]-wu[i][j];U[j]%=mod;
				U[i]+=(uu[i][n]-uu[i][j])*w[i][j]%mod;U[i]%=mod;
				sumu[j]+=uu[n][i]-uu[i][j];sumu[j]%=mod;
			}
			else{
				int s=dd[i][j];
				if(!q[s]) q[s]=k(s),p[s]=o(s);
				U[j]=(U[j]+mod-wd[i][j]*q[s]%mod)%mod;
				U[i]=(U[i]+p[s]*w[i][j])%mod;
				sumu[j]=(sumu[j]+mod-p[s])%mod;
			}
		}
	}
	sumr=sumd=1;
	for(int i=1;i<=n;i++){
		sumr=sumr*(suml[i]+1)%mod;
		sumd=sumd*(sumu[i]+1)%mod;
	}
	for(int i=1;i<=n;i++){
		R+=sumr*r(suml[i]+1,mod-2)%mod*L[i]%mod;R%=mod;
		D+=sumd*r(sumu[i]+1,mod-2)%mod*U[i]%mod;D%=mod;
	}
	printf("%lld",(R*(sumd)%mod+D*(sumr)%mod)%mod);
	return 0;
}


