#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll n,k;
ll a[N];
ll ans,out;
ll dp[N];
int main() {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		a[i]--;
//		ans+=a[i];
	}
//	ans*=2;
	sort(a+1,a+n+1);
	ll ck=0;
	for(int i=1;i<=n;i++) {
//		cout<<(a[i-1]*(n-i+1+ck)+a[i]*(n-i+1))<<" "<<((n-i+1+ck)*(a[i]-a[i-1]))<<"\n";
		if(ck>0&&(ck==k||(a[i-1]*(n-i+1+ck)+a[i]*(n-i+1))<=((n-i+1+ck)*(a[i]-a[i-1])))) {//
			ans+=a[i-1]*(n-i+1+ck)*2;
			ck=1;
		} else {
			ck++;
		}
	}
	ans+=a[n]*ck*2;
	cout<<ans;
	return 0;
}
/*
i-1-->i:+(n-i+ck)*(a[i]-a[i-1])*2-a[i-1]*2

i:
*/
