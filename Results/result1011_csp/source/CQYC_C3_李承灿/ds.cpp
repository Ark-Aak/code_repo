#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q;
struct node{
	int x,y;
}t[1000005];
bool cmp(node a,node b){
	if(a.x==b.x) return a.y<b.y;
	return a.x>b.x;
}
signed main(){
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<=n;i++) scanf("%lld",&t[i].x);
	for(int i=1;i<=n;i++) scanf("%lld",&t[i].y);
	if(n<=300&&q<=300){
		while(q--){
			int u,r,d,l,ans=0;
			scanf("%lld %lld %lld %lld",&u,&r,&d,&l);
			for(int i=1;i<=n;i++){
				if(t[i].x<d||t[i].x>u||t[i].y<l||t[i].y>r) continue;
				int z=1;
				for(int j=1;j<=n;j++){
					if(t[i].x<t[j].x&&t[j].x<=u&&t[i].y<t[j].y&&t[j].y<=r){
						z=0;
						break;
					}
				}
				ans+=z;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	sort(t+1,t+n+1,cmp);
	while(q--){
		int u,r,d,l,ans=0;
		scanf("%lld %lld %lld %lld",&u,&r,&d,&l);
		int h=0;
		for(int i=1;i<=n;i++){
			if(t[i].x<d) continue;
			if(t[i].x>u||t[i].y<l||t[i].y>r||t[i].y<h) continue;
			h=t[i].y;
			ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}


