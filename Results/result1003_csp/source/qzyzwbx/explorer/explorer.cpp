#include<bits/stdc++.h>
using namespace std;
int u[500007],v[500007],n,ans;
int ss(int i,int j,int k){
	int res=2;
	if(u[j]>u[i]&&u[j]<v[i])res++;
	if(v[j]>u[i]&&v[j]<v[i])res++;
	if(u[k]>u[i]&&u[k]<v[i])res++;
	if(v[k]>u[i]&&v[k]<v[i])res++;
	return res;
}
int fs(int i,int j,int k){
	int res=2;
	if(u[j]<u[i]||u[j]>v[i])res++;
	if(v[j]<u[i]||v[j]>v[i])res++;
	if(u[k]<u[i]||u[k]>v[i])res++;
	if(v[k]<u[i]||v[k]>v[i])res++;
	return res;
}
int main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i];
		if(u[i]>v[i]){
			swap(u[i],v[i]);
		}
	}
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				int a,b,c;
				a=min(ss(i,j,k),fs(i,j,k));
				b=min(ss(j,i,k),fs(j,i,k));
				c=min(ss(k,i,j),fs(k,i,j));
				if(a==b&&b==c){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

