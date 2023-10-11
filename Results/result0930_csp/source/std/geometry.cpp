#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	return !b?a:gcd(b,a%b);
}
int main()
{
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout); 
	ll n,x;
	scanf("%lld%lld",&n,&x);
	printf("%lld",(n-gcd(n,x))*3);
	return 0;
}
