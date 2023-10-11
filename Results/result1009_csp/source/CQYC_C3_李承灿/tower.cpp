#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k; 
int a[50002];
int l[50002][52],r[50002][52];
int tot,g[50002];
int vis[50002];
int ans=1e12;
string s[52];
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=k;i++){
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for(int i=1;i<=k;i++){
		tot=0;
		for(int j=1;j<=n;j++){
			if(a[j]!=i) g[++tot]=j;
			else{
				for(int w=1;w<=tot;w++) r[g[w]][i]=j;
				tot=0;
			}
		}
		tot=0;
		for(int j=n;j>=1;j--){
			if(a[j]!=i) g[++tot]=j;
			else{
				for(int w=1;w<=tot;w++) l[g[w]][i]=j;
				tot=0;
			}
		}
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push(make_pair(0,1));
	while(!q.empty()){
		int x=q.top().first,y=q.top().second;
		q.pop();
		if(y==n){
			ans=min(ans,x);
			continue;
		}
		if(vis[y]) continue;
		vis[y]=1;
		if(s[a[y]][a[n]]=='1') ans=min(ans,x+abs(n-y));
		for(int i=1;i<=k;i++){
			if(!l[y][i]&&!r[y][i]) continue;
			if(s[a[y]][i]=='0') continue;
			if(l[y][i]!=0&&!vis[l[y][i]]){
				q.push(make_pair(x+abs(y-l[y][i]),l[y][i]));
			}
			if(r[y][i]!=0&&!vis[r[y][i]]){
				q.push(make_pair(x+abs(r[y][i]-y),r[y][i]));
			}
		}
	}
	if(ans==1e12) printf("-1");
	else printf("%lld",ans);
	return 0;
}


