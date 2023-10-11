#include<bits/stdc++.h>
#define int long long
#define ll long long
#define mid ((l+r)>>1)
#define FOR(i,a,b) for(ll i=(a); i<=(b); ++i)
#define ROF(i,a,b) for(ll i=(a); i>=(b); --i)
#define modj(x) ((x)-=((x)>=MOD)?MOD:0)
#define qmin(x,y) ((x)=min((x),(y)))
#define qmax(x,y) ((x)=max((x),(y)))
using namespace std;
const int MAXN=6e4,Mod=1e9+7;
inline ll read(){
	ll t=0,f=0;char v=getchar();
	while(!isdigit(v))f|=(v=='-'),v=getchar();
	while(isdigit(v))t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
inline void write(ll x){
	if(x<0){x*=-1; putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
	return;
}
int n,k,maxx=1e16;
int a[MAXN],ans;
int qzh[1005][1005];
int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
} 
int calc(int x,int y){
	return (x+y)/gcd(x,y)-2;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T=read();
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			qzh[i][j]=(Mod+qzh[i-1][j]+qzh[i][j-1]-qzh[i-1][j-1])%Mod;
			qzh[i][j]+=calc(i,j);
			qzh[i][j]%=Mod;
		}
	}
	while(T--){
		n=read();k=read();
		if(n<=1000&&k<=1000){
			printf("%lld\n",qzh[n][k]);
			continue;
		}
		 printf("%lld\n",ans);
		
	}
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/

