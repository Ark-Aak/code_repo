#include<bits/stdc++.h>
using namespace std;
int f[100005][35],vis[35],t[35];
int main() {
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),ans=1e9;
	s=" "+s;
	int tot=0;
	for(int w=1; w<=20; w++) {
		int sum=1,maxn=0;
		memset(f,0,sizeof f);
		for(int i=1; i<=n; i++) {
			int flag=0;
			if(!vis[s[i]-'a']) {
				vis[s[i]-'a']=++tot;
				for(int j=1; j<=20; j++) if(t[j]>=maxn+1) t[j]++;
				t[s[i]-'a']=maxn+1;
				maxn++;
			}
			f[i][vis[s[i]-'a']]++;
			if(f[i-1][vis[s[i]-'a']]) {
				maxn=t[s[i]-'a'];
				sum++;
			} else if(t[s[i]-'a']<maxn) {
				maxn=t[s[i]-'a'];
				sum++;
			} else {
				for(int j=1; j<=n; j++) f[i][j]+=f[i-1][j];
				maxn=max(maxn,t[s[i]-'a']);
			}
		}
		for(int i=1;i<=tot;i++) t[s[i]-'a']=(t[s[i]-'a']+tot-2)%tot+1;
		
		ans=min(ans,sum);	
	}
	memset(vis,0,sizeof vis);
	memset(t,0,sizeof t);
	tot=0;
	for(int w=1; w<=20; w++) {
		int sum=1,maxn=0;
		memset(f,0,sizeof f);
		for(int i=n; i>=1; i--) {
			int flag=0;
			if(!vis[s[i]-'a']) {
				vis[s[i]-'a']=++tot;
				for(int j=1; j<=20; j++) if(t[j]>=maxn+1) t[j]++;
				t[s[i]-'a']=maxn+1;
				maxn++;
			}
			f[i][vis[s[i]-'a']]++;
			if(f[i+1][vis[s[i]-'a']]) {
				maxn=t[s[i]-'a'];
				sum++;
			} else if(t[s[i]-'a']<maxn) {
				maxn=t[s[i]-'a'];
				sum++;
			} else {
				for(int j=1; j<=n; j++) f[i][j]+=f[i+1][j];
				maxn=max(maxn,t[s[i]-'a']);
			}
		}
		for(int i=1;i<=tot;i++) t[s[i]-'a']=(t[s[i]-'a']+tot-2)%tot+1;
		ans=min(ans,sum);	
	}
	printf("%d\n",ans);
	return 0;
}

