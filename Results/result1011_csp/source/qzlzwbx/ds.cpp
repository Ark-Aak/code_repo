#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,l,r,d;
}que[1000007];
int sum[10007][10007],ans,n,q,xx[10007],yy[10007],maxr,maxu,maxx,maxy;
int main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>xx[i];
		maxx=max(maxx,xx[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>yy[i];
		maxy=max(maxy,yy[i]);
	}
	for(int i=1;i<=n;i++){
		sum[xx[i]][yy[i]]++;
	}
	for(int i=1;i<=q;i++){
		cin>>que[i].u>>que[i].r>>que[i].d>>que[i].l;
		maxr=max(maxr,que[i].r);
		maxu=max(maxu,que[i].u);
	}
	for(int i=maxx;i>=1;i--){
		for(int j=maxy;j>=1;j--){
			sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
		}
	}
	for(int i=1;i<=q;i++){
		ans=0;
		for(int j=1;j<=n;j++){
		//	cout<<xx[j]<<" "<<yy[j]<<": "<<sum[xx[j]][yy[j]]<<" -> "<<que[i].u<<" "<<que[i].r<<": "<<sum[que[i].u][que[i].r]<<" = "<<sum[xx[j]][yy[j]]<<" - "<<sum[xx[j]][que[i].r+1]<<" - "<<sum[que[i].u+1][yy[j]]<<" + "<<sum[que[i].u+1][que[i].r+1]<<" = "<<sum[xx[j]][yy[j]]-sum[xx[j]][que[i].r+1]-sum[que[i].u+1][yy[j]]+sum[que[i].u+1][que[i].r+1]<<endl;
			if(xx[j]>=que[i].d&&xx[j]<=que[i].u&&yy[j]>=que[i].l&&yy[j]<=que[i].r&&(sum[xx[j]][yy[j]]-sum[xx[j]][que[i].r+1]-sum[que[i].u+1][yy[j]]+sum[que[i].u+1][que[i].r+1]==1||xx[j]+1>que[i].u||yy[j]+1>que[i].r)){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
