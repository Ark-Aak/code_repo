#include<bits/stdc++.h>
using namespace std;
int a[100005],vis[100005],f[(1<<10)];
int count(int x) {
	int sum=0;
	for(int i=20;i>=0;i--) {
		if(x>=(1<<i)) x-=(1<<i),sum++;
	}
	return sum;
}
int main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=0;i<(1<<n);i++) {
		for(int j=1;j<(1<<n);j++) {
			if((i&j)==0 && count(j)<=k) {
				int maxn=0;
				for(int k=1;k<=n;k++) if((j&(1<<(k-1)))) maxn=max(maxn,k);
				f[i|j]=min(f[i|j],f[i]+2*(a[maxn]-1)*(n-count(i)));
			}
		}
	}
	printf("%d",f[(1<<n)-1]);
	return 0;
}

