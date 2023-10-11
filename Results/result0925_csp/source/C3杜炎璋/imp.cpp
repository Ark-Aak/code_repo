#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node {
	int x,y,val,id;
}a[250005],w[250005];
int id[250005],sum[4005][4005],maxn=-1e18,ma[4005][4005],shix[4005],shiy[4005];
bool cmp1(node u,node v) {
	return u.x<v.x;
}
bool cmp2(node u,node v) {
	return u.y<v.y;
}
bool cmp3(node u,node v) {
	return u.id<v.id;
}
int n;
signed main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld %lld %lld",&a[i].x,&a[i].y,&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp1);
	int s=0,t=0;
	for(int i=1;i<=n;i++) {
		if(s<a[i].x) t++,shix[t]=a[i].x;
		s=a[i].x;
		w[a[i].id].x=t;
	}
	sort(a+1,a+n+1,cmp2); 
	int e=t;
	s=0,t=0;
	for(int i=1;i<=n;i++) {
		if(s<a[i].y) t++,shiy[t]=a[i].y;
		s=a[i].y;
		w[a[i].id].y=t;
	}
	sort(a+1,a+n+1,cmp3);
	for(int i=1;i<=n;i++) {
		ma[w[i].x][w[i].y]+=a[i].val;
	}
	for(int i=0;i<=e;i++) {
		sum[i][0]+=ma[i][0];
		for(int j=1;j<=t;j++) {
			sum[i][j]=sum[i][j-1]+ma[i][j];
		}
		for(int j=1;j<=t;j++) {
			sum[i][j]+=sum[i-1][j];
		}
	}
	for(int i=0;i<=e;i++) {
		for(int j=0;j<=t;j++) {
			if(shiy[j]>=shix[i]) {
				int len=shiy[j]-shix[i];
				int tmp=sum[i+len][j]+sum[i-1][i-1]-sum[i-1][j]-sum[i+len][i-1]-len;
				maxn=max(tmp,maxn);
			}
		}
	}
	printf("%lld\n",maxn);
	return 0;
}
/*
6
2 3 4
1 4 -4
0 0 2
1 0 -5
3 1 -1
1 1 3

*/

