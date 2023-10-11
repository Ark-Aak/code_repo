#include<bits/stdc++.h>
#define int long long
using namespace std;
const int K=1e3+5,N=1e6+5,mod=1e9+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int n,m,k,a[N],b[N],s[K],tps,r[K],tpr,ans;
int A[K][K];	
char c;
void add(int &a,int b){if((a+=b)>=mod) a%=mod;}
signed main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	n=read(),m=read(),k=read();
	if(n<=1000&&m<=1000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				A[i][j]=m*(i-1)+j;
		
		for(int i=1;i<=k;++i){
			cin>>c;
			int x=read(),y=read();
			if(c=='R'){
				for(int j=1;j<=m;j++)
					A[x][j]=(A[x][j]*y)%mod;
			}
			if(c=='S'){
				for(int j=1;j<=n;j++)
					A[j][x]=(A[j][x]*y)%mod;
			}
		}		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				ans=(ans+A[i][j])%mod;
		printf("%lld",ans);
	}
	else{
		for(int i=1;i<=n;++i){
			a[i]=1;	
			add(ans,(((i-1)*m+1+(i-1)*m+m)*m/2)%mod);
		} 
		for(int i=1;i<=m;++i) b[i]=1;
	
		for(int i=1;i<=k;++i){
			cin>>c;
			int x=read(),y=read();
			if(c=='R') a[x]=(a[x]*y)%mod;
			if(c=='S') b[x]=(b[x]*y)%mod;
		}
		for(int i=1;i<=n;++i){
			if(a[i]!=1){
				r[++tpr]=i;	
				add(ans,(a[i]-1+mod)%mod*((((i-1)*m+1+(i-1)*m+m)*m/2)%mod));
			}
		}
		for(int i=1;i<=m;++i){
			if(b[i]!=1){
				s[++tps]=i;
				add(ans,(b[i]-1+mod)%mod*(((i+i+(n-1)*m)*n/2)%mod)%mod);
			} 	
		}
		
		for(int i=1;i<=tpr;++i){
			for(int j=1;j<=tps;++j){
				int R=r[i],S=s[j];
				int V=m*(R-1)+S;
				if(!a[R]&&!b[S]) add(ans,V);
				else if(!a[R]) ans=(ans-(V*(b[S]-1))%mod+mod)%mod;
				else if(!b[S]) ans=(ans-(V*(a[R]-1))%mod+mod)%mod;
				else{
					ans=(ans-V*(a[R]-1)%mod-V*(b[S]-1)%mod+(mod<<1))%mod;
					add(ans,V*(a[R]*b[S]%mod-1)%mod);
				} 
			}
		}
		printf("%lld",ans%mod);		
	}

	return 0; 
}
/*
2 4 4
S 2 0
S 2 3
R 1 5
S 1 3
*/
