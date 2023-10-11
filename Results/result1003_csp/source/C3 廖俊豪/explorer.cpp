#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,ans;
int a[500005],b[500005];
signed main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout); 
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){scanf("%lld %lld",&a[i],&b[i]);if(a[i]>b[i])swap(a[i],b[i]);}
	int ops=1;
	for(int i=1;i<=n;i++)if(a[i]!=2*i-1||b[i]!=2*i)ops=0;
	if(ops){
		printf("%lld",n*(n-1)*(n-2)/6);
		return 0; 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				int res1=(a[j]>a[i]&&a[j]<b[i])+(a[k]>a[i]&&a[k]<b[i])+(b[j]>a[i]&&b[j]<b[i])+(b[k]>a[i]&&b[k]<b[i]);res1=min(4-res1,res1);
				int res2=(a[i]>a[j]&&a[i]<b[j])+(a[k]>a[j]&&a[k]<b[j])+(b[i]>a[j]&&b[i]<b[j])+(b[k]>a[j]&&b[k]<b[j]);res2=min(4-res2,res2);
				int res3=(a[j]>a[k]&&a[j]<b[k])+(a[i]>a[k]&&a[i]<b[k])+(b[j]>a[k]&&b[j]<b[k])+(b[i]>a[i]&&b[k]<b[k]);res3=min(4-res3,res3);
				if(res1==res2&&res2==res3)ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
