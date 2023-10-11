#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,K=1005,mod=1e9+7;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
char op;
inline void Op(){
	op=getchar();
	while(op^'R'&&op^'S') op=getchar();
}
int n,m,k,x,y;
long long cn[N],cm[N],sum,ans,cnt;
int main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) cn[i]=1;
	for(int i=1;i<=m;i++) cm[i]=1;
	while(k--){
		Op(),read(x),read(y);
		if(op=='R') cn[x]=cn[x]*y%mod;
		else cm[x]=cm[x]*y%mod;
	}
	for(int i=1;i<=m;i++){
		sum=(1ll*sum+1ll*cm[i]*i%mod)%mod;
		cnt=(cnt+cm[i])%mod;
	}
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*cn[i]*sum%mod)%mod;
		sum=(sum+1ll*m*cnt)%mod;
	}
	printf("%lld",ans);
	return 0;
}

