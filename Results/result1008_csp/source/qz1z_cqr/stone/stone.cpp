//30? 
#include<bits/stdc++.h>
using namespace std;
int n,k,dres,a[20],b[20],res;
void dfs2(){
	int c=0;
	for(int i=1;i<=n;i++){c+=b[i];}
	dres=min(dres,c);
	for(int i=1;i<=n;i++){
		if(b[i]==i){
			b[i]=0;
			for(int j=1;j<i;j++)
				b[j]++;
			dfs2(); 
		}
	}
}
void dfs1(int t){
	if(t>n){
		for(int i=1;i<=n;i++) b[i]=a[i];
		dres=114514;dfs2();res+=dres;
		res%=1000000007;
		return;
	}
	for(int i=0;i<=k;i++){
		a[t]=i;dfs1(t+1);}
} 
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n>>k;
	dfs1(1);cout<<res;
	return 0;
} 
