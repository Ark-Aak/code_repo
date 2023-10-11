#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[35];
int ans=1e18;
int n;
void dfs(int x,int b[27],int sum,int tot,int t){
	if(sum>=ans) return;
	if(x==n+1){
		ans=sum;
		return;
	} 
	for(int i=x;i<=n&&sum<ans;i++){
		if(b[s[i]-'a']>0){
			if(b[s[i]-'a']>t) t=b[s[i]-'a'];
			else{
				sum++;
				t=b[s[i]-'a'];
			}
		}
		else{
			int c[27],k=t;
			for(int j=0;j<26;j++) c[j]=b[j];
			int o=b[s[i-1]-'a'];
			for(int j=0;j<26;j++) if(b[j]>o) b[j]++;
			b[s[i]-'a']=o+1;
			t=o;
			dfs(i+1,b,sum,tot+1,tot+1);
			t=k;
			for(int j=0;j<26;j++) b[j]=c[j];
			if(i==1) continue;
			o=b[s[i-1]-'a'];
			for(int j=0;j<26;j++) if(b[j]>=o) b[j]++;
			b[s[i]-'a']=o;
			tot++;
			t=o;
			sum++;
		}
	}
	if(sum<ans) ans=sum;
}
signed main(){
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin>>s;
	n=s.size();
	s=' '+s;
	dfs(1,a,1,0,0);
	printf("%lld",ans);
	return 0;
}
//mildmyildmiyldmiyld
//milddlimdlim

