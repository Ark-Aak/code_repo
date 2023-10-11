#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,k,ans1=0,ans2;
struct XXX{
	int a,b;
}z[1000005];
int mx[100005];
int gg[100005];
bool flag=0;
bool cmp(XXX x,XXX y){
	return x.a<y.a;
}
signed main() {
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&z[i].a,&z[i].b);
		if(z[i].a>z[i].b) swap(z[i].a,z[i].b);
		if(z[i].a!=z[i].b-1) flag=1;
	}
	if(flag==0){
		cout<<n*(n-1)*(n-2);
		return 0;
	}
	sort(z+1,z+n+1,cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		if(z[i].b>z[j].a) continue;
			if(z[j].b>z[i].b){
				ans1+=gg[z[i].a];
				ans1+=mx[z[j].b];
				//cout<<i<<" "<<j<<" "<<gg[z[i].b-1]+mx[z[j].b+1]<<endl;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(z[i].b<z[j].a) continue;
			if(z[i].b<z[j].b){
				ans2+=gg[z[i].b]-gg[z[j].a];
				//cout<<i<<" "<<j<<" "<< gg[z[i].b-1]-gg[z[j].a]<<endl;
			}
		}
		for(int j=1;j<=z[i].b;j++){
			mx[j]++;
		}
		for(int j=z[i].b;j<=2*n;j++){
			gg[j]++;
		}
	}
	printf("%lld",ans1+ans2);
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
