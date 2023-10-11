#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i = a; i <=b; i++)

const int N=2e5+5;

int n,k,a[N],ans;

inline void CL(int u){
	for(int i=1;i<=u;i++){
		a[i]++;
		if(a[i]==i) CL(i-1);
	}
	return;
}

inline void Check(){
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			a[i]=0;
			CL(i-1);
		}
	}
	F(i,1,n) ans+=a[i];
}

inline void dfs(int u){
	if(u==n+1){Check();return;}
	for(int i=0;i<=k;i++){
		a[u]=i;
		dfs(u+1);
	}
}

int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n>>k;
	dfs(1);
	cout<<ans;
	return 0;
}
