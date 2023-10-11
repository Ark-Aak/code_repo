//10-
#include<bits/stdc++.h>
using namespace std;
int n,cnt,cn2,ans,a[505][505],dy[505][505],mod=998244353;
int cx[250005],cy[250005];
string s[505];bool ck[250005];
vector<int> v[250005];
void dfs(int t,int o){
	o%=mod;
	if(t>cnt){ans=(ans+o)%mod;return;}
	dfs(t+1,o);
	for(auto i:v[t]){
		if(ck[i]) continue;
		ck[i]=1;
		dfs(t+1,o+cx[t]+cy[i]);
		ck[i]=0;
	}
}
signed main(){
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>s[i];s[i]=" "+s[i];}
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){ 
		if(s[i][j]=='L'){
			++cn2;cy[cn2]=a[i][j];
			for(int k=1;k<j;k++){
			if(s[i][k]=='R'){
				if(!dy[i][k]){dy[i][k]=++cnt;cx[cnt]=a[i][k];}
				v[dy[i][k]].push_back(cn2);
			}}
		}else if(s[i][j]=='U'){
			++cn2;cy[cn2]=a[i][j];
			for(int k=1;k<i;k++){
			if(s[k][j]=='D'){
				if(!dy[k][j]){dy[k][j]=++cnt;cx[cnt]=a[k][j];}
				v[dy[k][j]].push_back(cn2);
			}}
		}
	}}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
//cout<<i<<' '<<k<<'('<<dy[i][k]<<','<<a[i][k]<<"),"<<i<<' '<<j<<'('<<cy[cn2]<<")\n";
//cout<<k<<' '<<j<<'('<<dy[k][j]<<','<<a[k][j]<<"),"<<i<<' '<<j<<'('<<cy[cn2]<<")\n";
