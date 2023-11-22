#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e7+7,Mod=998244353;
int phi[Maxn],prime[Maxn],cnt,n,k,tot,ln[Maxn];
int pron[Maxn],nex[Maxn];
int used[Maxn];
bool isprime[Maxn],visd[Maxn]; 
ll ans;
void init(ll N){
	ln[1]=phi[1]=isprime[1]=1;
	for(ll i=2;i<=N;i++){
		if(!isprime[i]) prime[++cnt]=i,phi[i]=i-1,ln[i]=i;
		for(ll j=1;j<=cnt&&prime[j]*i<=N;j++){
			isprime[i*prime[j]]=1;ln[i*prime[j]]=prime[j];
			if(i%prime[j]) phi[i*prime[j]]=phi[i]*(prime[j]-1);
			else {phi[i*prime[j]]=phi[i]*prime[j];break;}
		}
	}
}
inline ll D(ll x){
	ll arcaea=1;
	for(ll i=1;i<=tot;i++){
		int cnt=0;
		while(x%nex[i]==0) x/=nex[i],cnt++;
		arcaea=(arcaea*(pron[nex[i]]*k-cnt+1))%Mod;
	}
	return arcaea;
}
void dfs(ll s){
	ans=(ans+phi[s]*D(s)*(n/s))%Mod;
	for(ll i=1;i<=tot;i++)
		if(s*nex[i]<=n&&!visd[s*nex[i]]&&used[nex[i]]<pron[nex[i]]*k) 
			used[nex[i]]++,visd[s*nex[i]]=1,dfs(s*nex[i]),used[nex[i]]--;
}
int main(){
	init(Maxn-2);
	scanf("%d%d",&n,&k);
	ll x=n;
	for(ll i=2;i*i<=x;i++){
		if(!(x%i)){
			int cnt=0;
			while(!(x%i)) ++cnt,x/=i;
			pron[i]=cnt;
			nex[++tot]=i;
		}
	}
	if(x!=1) pron[x]=1,nex[++tot]=x;
	dfs(1);
	printf("%lld",ans%Mod);
	return 0;
} 