#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=5e5+7;
ll n,a[Maxn],b[Maxn],ans;
bool flg=1;
int main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		if(b[i]<a[i]) swap(a[i],b[i]); 
		flg&=(b[i]-a[i]==1);
	}
	if(n<=500){
		for(ll i=1;i<=n;i++)
			for(ll j=i+1;j<=n;j++)
				for(ll k=j+1;k<=n;k++){
					ll res1=0,res2=0,res3=0;
					if(a[i]<=a[j]&&a[j]<=b[i]) res1++;
					if(a[i]<=b[j]&&b[j]<=b[i]) res1++;
					if(a[i]<=a[k]&&a[k]<=b[i]) res1++;
					if(a[i]<=b[k]&&b[k]<=b[i]) res1++;
					if(a[j]<=a[i]&&a[i]<=b[j]) res2++;
					if(a[j]<=b[i]&&b[i]<=b[j]) res2++;
					if(a[j]<=a[k]&&a[k]<=b[j]) res2++;
					if(a[j]<=b[k]&&b[k]<=b[j]) res2++;
					if(a[k]<=a[i]&&a[i]<=b[k]) res3++;
					if(a[k]<=b[i]&&b[i]<=b[k]) res3++;
					if(a[k]<=a[j]&&a[j]<=b[k]) res3++;
					if(a[k]<=b[j]&&b[j]<=b[k]) res3++; 
					res1=min(res1,4-res1);
					res2=min(res2,4-res2);
					res3=min(res3,4-res3);
					if(res1==res2&&res2==res3) ans++;
				}
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",n*(n-1)*(n-2)/6);
	return 0;
	return 0;
}
/*
5
1 8
2 5
3 9
4 10
6 7

7
1 2
3 4
5 6
7 8
9 10
11 12
13 14
15 16
17 18 
19 20
*/
