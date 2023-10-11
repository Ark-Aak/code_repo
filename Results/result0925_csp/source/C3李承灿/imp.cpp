#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int x[2502],y[2502],c[2502];
int d[5002][5002];
int a[5002],tot;
int b[5002],cnt;
map<int,int> id;
int ans;
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld %lld",&x[i],&y[i],&c[i]);
		a[++tot]=x[i];
		a[++tot]=y[i];
	}
	sort(a+1,a+tot+1);
	for(int i=1;i<=tot;i++){
		if(a[i]!=a[i-1]) b[++cnt]=a[i];
	}
	for(int i=1;i<=cnt;i++) id[b[i]]=i;
	for(int i=1;i<=n;i++) d[id[x[i]]][id[y[i]]]+=c[i];
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			d[i][j]+=d[i-1][j]+d[i][j-1]-d[i-1][j-1];
		}
	}
	for(int i=1;i<=cnt;i++){
		for(int j=i;j<=cnt;j++){
			ans=max(ans,d[j][j]-d[j][i-1]-d[i-1][j]+d[i-1][i-1]-(b[j]-b[i]));
		}
	}
	printf("%lld",ans);
	return 0;
}


