#include <bits/stdc++.h>
using namespace std;
const double esc = 1e-9;
int n;
double ans;
int a[1145141];
bool cmp(int a,int b){
	return a<b;
}
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	ans = a[1];
	for (int i = 2; i <= n; i++)
		ans = (ans+(double)a[i])/2;
	printf("%.6lf",ans);
	return 0;
}
