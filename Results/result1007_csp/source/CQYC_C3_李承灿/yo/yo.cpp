#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000002],z,sum;
bool f[1000002][11];
bool vis[1000002][11];
bool b[1000002];
string t,s;
bool dfs(int x,int s){
	if(x==n){
		if(b[x]){
			if((s*10+a[x])%11==0||s*10%11==0) return 1;
			else return 0;
		}
		else{
			if((s*10+a[x])%11!=0||s*10%11!=0) return 0;
			else return 1;
		}
	}
	if(dfs(x+1,s*10+a[x])==b[x]) return b[x];
	if(dfs(x+1,s*10)==b[x]) return b[x];
	return (!b[x]);
}
bool dfs2(int x,int s){
	if(vis[x][s]) return f[x][s];
	if(x==n){
		if(b[x]){
			if((s+a[x])%11==0) return 1;
			else return 0;
		}
		else{
			if((s+a[x])%11!=0) return 0;
			else return 1;
		}
	}
	int k=1;
	if((x&1)!=(n&1)) k=10;
	f[x][s]=b[x];
	vis[x][s]=1;
	if(dfs2(x+1,(s+a[x]*k)%11)==b[x]) return b[x];
	if(dfs2(x+1,s)==b[x]) return b[x];
	f[x][s]=(!b[x]);
	return (!b[x]);
}
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	scanf("%lld",&n);
	cin>>t>>s;
	t=' '+t;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='y') sum++,b[i]=1;
		else b[i]=0;
		a[i]=t[i]-'0';
		if(a[i]>0) z=1;
	}
	if(n<=10){
		if(dfs(1,0)) printf("yoimiya");
		else printf("oimiya");
		return 0;
	}
	if(sum==n){
		printf("yoimiya");
		return 0;
	}
	if(sum==0){
		if(z==1) printf("oimiya");
		else printf("yoimiya");
		return 0;
	}
	if(dfs2(1,0)) printf("yoimiya");
	else printf("oimiya");
	return 0;
}


