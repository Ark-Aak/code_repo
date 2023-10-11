//100
#include<bits/stdc++.h>
#define MX 1000002
using namespace std;
int n,re1,re2,p[MX],f[2][11];
string s,t;
signed main(){
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n>>s>>t;
	for(int i=0;i<n;i++) p[i+1]=(s[i]-'0');
	for(int i=1;i<11;i++) f[(n+1)&1][i]=1;
	for(int i=n;i>=1;i--){
	for(int j=0;j<11;j++){
		re1=f[(i+1)&1][(j*10)%11];
		re2=f[(i+1)&1][(j*10+p[i])%11];
		if(t[i-1]=='y') f[i&1][j]=min(re1,re2);
		else f[i&1][j]=max(re1,re2);
		//cout<<f[i&1][j];
	}/*cout<<'\n';*/}
	if(!f[1][0]) cout<<"yoimiya";
	else cout<<"oimiya";
	return 0;
} 
