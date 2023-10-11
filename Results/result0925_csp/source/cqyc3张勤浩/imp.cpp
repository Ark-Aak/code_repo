#include <bits/stdc++.h>
#define ll long long

#define lowbit(x) (x&-x)
using namespace std;
const ll Maxn=5.5e5+7,inf=1e13;
struct node{
	ll x,y,c;
}a[Maxn];
ll n,ans=-inf;
int main(){
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].c);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			ll res=0;
			ll t1=max(a[i].x,a[i].y),t2=max(a[j].x,a[j].y);
			if(t1>t2) continue;
			for(ll k=1;k<=n;k++){
				if(t1<=a[k].x&&t1<=a[k].y&&a[k].x<=t2&&a[k].y<=t2){
					res+=a[k].c;
				}
			}
			ans=max(ans,res-(t2-t1));
		}
	}
	printf("%lld",ans);
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
