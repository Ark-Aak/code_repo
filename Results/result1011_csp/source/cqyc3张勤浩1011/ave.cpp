#include <bits/stdc++.h>
#define ll long long
using namespace std;
priority_queue<ll>q;
double ans; 
ll n;
int main(){
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1,x;i<=n;i++) scanf("%lld",&x),q.push(-x);
	ans=-q.top();q.pop();
	while(!q.empty()){
		ll x=-q.top();
		q.pop();
		ans=(ans+x)/2.;
	}
	printf("%.7lf",ans);
	return 0;
}
/*
3
1
3
5
*/

