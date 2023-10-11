#include<bits/stdc++.h>
using namespace std;
int l[3005],r[3005],ans[3005];
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d %d",&l[i],&r[i]);
	}
	for(int i=1;i<=q;i++) {
		memset(ans,0,sizeof ans);
		int m;
		scanf("%d",&m);
		for(int j=1;j<=m;j++) {
			int x;
			cin>>x;
			for(int k=1;k<=n;k++) {
				if(l[k]<=x && x<=r[k]) ans[k]++;
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++) {
			if(ans[j]&1) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}

