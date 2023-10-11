#include<bits/stdc++.h>
using namespace std;
int a[100][100],f[2],l[100],h[100],ans=9999999,n,m;
char ch;
void dfs(int x,string s){
	if(x>=n+m){
		f[1]=0;
		for(int i=1;i<=n;i++){
			h[i]=s[i-1]-'0';
		}
		for(int i=n+1;i<=n+m;i++){
			l[i-n]=s[i-1]-'0';
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((h[i]+l[j])%2==0){
					f[a[i][j]]++;
				}
				else{
					f[(!a[i][j])]++;
				}
			}
		}
		ans=min(ans,f[1]);
		return;
	}
	dfs(x+1,s+"0");
	dfs(x+1,s+"1");
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>ch;
			a[i][j]=ch-'0';
		}
	}
	dfs(0,"");
	cout<<ans<<endl;
	return 0;
}
