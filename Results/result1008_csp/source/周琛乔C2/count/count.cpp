#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=998244353;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int n,m,x,idx,cnt[N],len[N],ans;
long long sum[N],f[N][N],S,C;
inline int Sum(int i){return i<0?0:sum[i];}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.in","w",stdout);
	read(n),read(m);
	for(int i=1;i<=m;i++){
		read(x);
		if(!cnt[x]) len[++idx]=x;
		++cnt[x];
	}
	sum[0]=sum[1]=1;
	for(int j=1;j<=idx;j++){
		f[1][j]=cnt[len[j]];
		sum[1]+=f[1][j];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=idx;j++){
			S=((sum[i-1]-Sum(i-len[j]-1)+mod)%mod)*cnt[len[j]]%mod;
			C=(f[i-1][j]-f[max(0,i-len[j]-1)][j])%mod;
			f[i][j]=(S-C+mod)%mod;
			sum[i]=(sum[i]+f[i][j])%mod;
			f[i][j]=(f[i-1][j]+f[i][j])%mod;
		}
		sum[i]=(sum[i-1]+sum[i])%mod;
	}
	printf("%d",(sum[n]-sum[n-1]+mod)%mod);
	return 0;
}

