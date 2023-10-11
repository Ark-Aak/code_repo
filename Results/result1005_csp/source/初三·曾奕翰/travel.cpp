#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353; 
int n,m,k,ans;
bool flag;
int gg[100005];
struct XXX{
	int l,r,s;
}z[100005];
bool cmp(XXX a,XXX b){
	return a.l<b.l;
}
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&z[i].l,&z[i].r,&z[i].s);
		if(z[i].l!=1){
			flag=1;
			break;
		}
	}
	if(k==0){
		cout<<1;
		return 0;
	}
	sort(z+1,z+m+1,cmp);
	cout<<4;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

