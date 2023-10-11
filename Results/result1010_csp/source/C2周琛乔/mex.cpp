#include<bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,b[114],a[114];
long long ans;
bool vis[10];
void dfs(int x){
	if(x==n+1){
		int mex=0;memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			vis[a[i]]=1;
			while(vis[mex]) ++mex;
		}
		ans=(ans+mex)%1000000007;
		return;
	}
	for(int i=0;i<=b[x];i++){
		a[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(b[i]);
	dfs(1);
	cout << ans;
	return 0;
}

