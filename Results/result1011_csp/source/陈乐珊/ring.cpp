#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+4;
int n,mod;
ll w[N];
ll ans,x ;
int main() {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	cin>>n>>mod;
	w[1]=1;
	for(int i=2;i<=n;i++)
		w[i]=w[i-1]*i%mod;
	cout<<w[n] ;
	return 0;
} 
/*
p_n <= i <= p_i%(n-1)+1 (i%2==1)
p_1 <= i <= p_i%(n-1)+1 (i%2==0)

在第 i 次操作中 ：a = P_(i%2?n:1) , b = P_(i-1)%(n-2)+2;

P_(i%2?n:1) < i < P_(i-1)%(n-2)+2 ;
     (i-1) * (n-i) * 1*2*3*...*(n-2)
*/
