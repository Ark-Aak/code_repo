#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005],v[200005],sum[200005],minn=1e9;
struct node {
	int x,id;
}b[200005],s[200005];
bool cmp(node u,node v) {
	return u.x<v.x;
}
signed main(){
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	int n,m;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),b[i].x=a[i],b[i].id=i;
	if(n<=2000 && m<=2000) {
		while(m--) {
			int tmp,x,y;
			scanf("%lld",&tmp);
			if(tmp==1) {
				int cnt=0;
				scanf("%lld",&x);
				a[0]=-1;
				for(int i=1;i<=n;i++) {
					if(a[i-1]>=x && a[i]<x) cnt++;
				}
				if(a[n]<x) cnt--;
				printf("%lld\n",cnt+1);
			} else {
				scanf("%lld %lld",&x,&y);
				a[x]=y;
			}
		}
	} else {
		for(int i=1;i<=m;i++) {
			int tmp;
			scanf("%lld %lld",&tmp,&s[i].x);
			s[i].id=i;
		}
		sort(s+1,s+m+1,cmp);
		sort(b+1,b+n+1,cmp);
		int r=1;
		int cnt=0;
		memset(v,0,sizeof v);
		for(int i=1;i<=m;i++) {
			while(r<=n && b[r].x<s[i].x) {
				if(!v[b[r].id-1] && !v[b[r].id+1]) cnt++;
				if(v[b[r].id-1] && v[b[r].id+1]) cnt--;
				v[b[r].id]=1;
				r++;
			}
			int ans=cnt;
			sum[s[i].id]=ans+1-(v[1]+v[n]);
		}
		for(int i=1;i<=m;i++) printf("%lld\n",sum[i]); 
	}
	return 0;
}

/*
5 1
8
6
3
5
4
1 5

*/

