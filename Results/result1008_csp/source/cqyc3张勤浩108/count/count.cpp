#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5,Mod=998244353;
ll n,m,ans,a[Maxn];
void dfs (ll pos,ll num,ll k){
	if(k>a[num]) return ;
	if(pos==n){
		ans++;
		return ;
	}
	for(ll i=1;i<=m;i++){
		if(i==num){
			dfs(pos+1,i,k+1);
		}
		else{
			dfs(pos+1,i,1);
		}
	}
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	dfs(0,0,0);
	cout<<ans%Mod;
	return 0; 
}
/*
3 3
1 2 3
*/

