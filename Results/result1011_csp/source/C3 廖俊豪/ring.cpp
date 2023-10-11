#include<bits/stdc++.h>
using namespace std;
int n,mod;
long long int ans;
int s[25],w[25];
int S[25],W[25];
int check(){
	for(int i=0;i<n;i++)S[i]=s[i],W[i]=w[i]; 
	int ops=0;
	for(int i=1;i<=n;i++){
		int now=w[i];
		int l=(w[i]-1+n)%n;
		int r=(w[i]+1)%n;
		if((s[l]<i&&i<s[r])||(s[r]<i&&i<s[l])){
			ops=1;
			break;
		}
		swap(w[s[l]],w[s[r]]);
		swap(s[l],s[r]);
	}
	for(int i=0;i<n;i++)s[i]=S[i],w[i]=W[i];
	return ops;
}
void dfs(int x){
	if(x==n+1){
		ans+=check();
		return;
	}
	for(int i=0;i<n;i++){
		if(s[i]==0){
			w[x]=i;
			s[i]=x;
			dfs(x+1);
			s[i]=0;
		}
	}
}
void sub_1(){
	dfs(1);
	cout<<ans<<endl;
	return;
}
void sub_4(){
	ans=1;
	for(int i=1;i<=n;i++)ans=ans*i%mod;
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n>>mod;
	if(n<=10){
		sub_1();
		return 0;
	}
	if(n&1){
		sub_4();
		return 0;
	}
}
