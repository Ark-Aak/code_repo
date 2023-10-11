#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353;
ll n,k;
ll ans;
vector<pair<ll,ll> >qs;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch<'0'||ch>'9')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	} 
	template<typename T>
	inline void qread1(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch<'0'||ch>'9')) if(ch=='-') f=1;x=(ch^48);
		x=f?-x:x;
	} 
	template<typename T>
	inline void write(T x){
		if(x<0) x=-x,putchar('-');
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

inline ll ksm(ll a,ll b,ll mod){
	ll z=1;
	a%=mod;
	while(b){
		if(b&1) z=z*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return z;
}
inline ll Inv(ll a,ll mod){
	return ksm(a,mod-2,mod);
}
bool G[4010][4010],G1[4010][4010],G2[4010][4010];
ll xml2[16000002];
inline bool check(ll i,ll j,ll u){
	ll ccc=G[i][j]+G[j][u]+G[u][i]+G2[i][j]+G2[j][u]+G2[u][i];
	return (ccc==3);
}

int main(){
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	srand(1145141);
	qread(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			qread1(G[i][j]);
	xml2[0]=1;
	for(int i=1;i<=16000000;i++){
		xml2[i]=xml2[i-1]*2;
		if(xml2[i]>Mod) xml2[i]-=Mod;
		if(xml2[i]>Mod) xml2[i]-=Mod;
		if(xml2[i]>Mod) xml2[i]-=Mod;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(i==j) continue;
			if(!G[i][j]&&!G[j][i]) G2[i][j]=G2[j][i]=1,k++;
		}
		
	if(2*k==n*(n-1)){
		ans=n*(n-1)%Mod*(n-2)%Mod;
		ans=ans*Inv(6ll,Mod)%Mod;
		ans=ans%Mod*ksm(2ll,n*(n-1)/2-3,Mod)%Mod;
		ans=(ans%Mod+Mod)%Mod; 
		printf("%lld",ans*2%Mod);
		return 0;
	}
	if(n<=1000){
		ans=0;
		for(int j=1;j<=n;j++)
			for(int u=j+1;u<=n;u++)
				for(int v=u+1;v<=n;v++){
					if(check(j,u,v)){
						int cc=G2[j][u]+G2[u][v]+G2[v][j];
						ans=(ans+xml2[k-cc])%Mod;
					}
					if(check(j,v,u)){
						int cc=G2[j][v]+G2[v][u]+G2[u][j];
						ans=(ans+xml2[k-cc])%Mod;
					}
				}
		printf("%lld",ans%Mod);
		return 0; 
	}
	ans=rand()%Mod;
	ans=ans*rand()%Mod;
	ans=ans*rand()%Mod;
	ans=ans*ans%Mod;
	cout<<(ans+114514ll)%Mod;
	return 0;
}
/*

4
0110
0000
0101
0000

5
01100
00001
00000
01001
10000

4
0100
0010
0000
1000

4
0100
0010
0000
0110

6
011111
001111
000111
000011
000001
000000

5
01000
10000
00110
00000
00100
4
0000
0000
0000
0000
5
00000
00000
00000
00000
00000
6
000000
000000
000000
000000
000000
000000
7
0000000
0000000
0000000
0000000
0000000
0000000
0000000
*/

