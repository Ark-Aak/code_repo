#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e7+7;
int n,a[1010],res;
int main(){
//	freopen("crazy.in","r",stdin);
//	freopen("crazy.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);a[0]=-120;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) if(a[i]!=a[i-1]+1) res++;
	printf("%d",res);
	return 0;
}
/*
2
1 10000000

*/
