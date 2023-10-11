#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=550,mod=998244353;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^-'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
inline bool _char(){
	char c=getchar();
	while(c^'0'&&c^'1') c=getchar();
	return c-'0';
}
int n,m,c[N][N],k;
char ch;
inline int pw(ll x,int y){
	ll ans=1;
	for(;y;y>>=1){
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
	}
	return ans;
}
ll ans,w[5];
inline void sub50(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(c[i][j]==1) c[i][j]=0,c[j][i]=-1;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(!c[i][j]&&!c[j][i])
				c[i][j]=c[j][i]=1;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(i==j||c[i][j]==-1) continue;
		for(int k=1;k<=n;k++){
			if(k^i&&k^j&&c[j][k]>=0&&c[k][i]>=0)
				ans=(ans+w[c[i][j]+c[j][k]+c[k][i]])%mod;
		}	
	}
	printf("%lld",ans/3);
}
bool sa=1;
inline void subA(){
	ans=(1ll*n*(n-1)*(n-2)/6)%mod;
	ans=ans*w[3]%mod*2%mod;
	printf("%lld",ans);
}
int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		c[i][j]=_char();
		sa&=(!c[i][j]);
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
		m+=(!c[i][j]&&!c[j][i]);
	k=min(m,3);
	w[k]=pw(2,m-k);
	for(int i=k-1;~i;i--) w[i]=w[i+1]*2%mod;
	if(sa) subA();
	else sub50();
	return 0;
}

