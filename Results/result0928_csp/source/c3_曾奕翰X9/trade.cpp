#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,c,ans;
int a[N];
vector<int>q[N];
void dfs(int x,int sum,int day){
	if(day*day*c>=sum&&sum!=0) return;
	if(x==1&&sum){
		ans=max(sum-day*day*c,ans);
	}
	for(auto v:q[x]){
		dfs(v,sum+a[v],day+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	n=read();m=read(),c=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		q[u].push_back(v);
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;

}

