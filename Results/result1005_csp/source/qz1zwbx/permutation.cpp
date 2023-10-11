#include<bits/stdc++.h>
using namespace std;
int f1[100007],f2[100007],f3[100007],n,k;
string s[100000];
void dfs(int step){
	if(step>=k)
		return;
	for(int i=1;i<=n;i++){
		f3[f1[i]]=f2[i];
	}
	for(int i=1;i<=n;i++){
		f1[i]=f2[i];
		f2[i]=f3[i];
	}
	dfs(step+1);
	return;
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>f1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>f2[i];
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cout<<f3[i]<<" ";
	}
	cout<<endl;
	return 0;
}

