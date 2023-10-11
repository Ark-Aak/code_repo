#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353,Maxn=1e6+7;
ll n,k,ans;
char s[Maxn];
void DFS(char c[],ll p){
	if(p==0){
		ans++;
		return ;
	}
	for(ll i=0;i<n;i++){
		bool flg=1;
		for(ll j=i;j<n;j++){
			if((j-i+1)%2==0) flg&=(c[j]=='0');
			else flg&=(c[j]=='1');
			if(!flg) break;
			if((j-i+1)%2&&flg){
				for(ll u=i;u<=j;u++){
					if(c[u]=='1') c[u]='0';
					else c[u]='1';
				}
				DFS(c,p-1);
				for(ll u=i;u<=j;u++){
					if(c[u]=='1') c[u]='0';
					else c[u]='1';
				}
			}
		}
	}
		
}
ll biao[]={1,3,3,6,15,15,10,45,105,105,15,105,420,945,945,21,210,1260,4725,10395,10395,28,378,3150,17325,62370,135135,135135,36,630,6930,51975,270270,945945,2027025,2027025,45,990,13860,135135,945945,4729725,16216200,34459425,34459425,55,1485,25740,315315,2837835,18918900,91891800,310134825,654729075,654729075};
int main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(n<=10&&k<=10){
		cout<<biao[(n-1)*n/2+k-1]%Mod;
		return 0;
	}
	else if(k==1){
		cout<<(n*(n+1))/2;
		return 0;
	}
	else if(k==n-1||k==n){
		if(k==n) k--;
		ll s=1;
		for(ll i=1;i<=k;i++) s=s*(2*i+1)%Mod;
		cout<<s;
		return 0; 
	}
	else{
		for(ll i=1;i<=n;i++) s[2*i-1]='1';
		for(ll i=1;i<n;i++) s[2*i]='0';
		n=2*n-1;
		DFS(s+1,k);
		printf("%lld",ans);
	}
	
	return 0;
}
/*
3 2 
*/

