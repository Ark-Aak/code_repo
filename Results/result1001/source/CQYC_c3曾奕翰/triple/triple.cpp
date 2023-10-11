#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Mod=1e9+7;
int a,b,c;
int p,q,r;
signed main() {
	freopen("triple.in","r",stdin);
freopen("triple.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld",&p,&q,&r);
		scanf("%lld%lld%lld",&a,&b,&c);
		int z=p-a,za=q-b,zaa=r-c;
		if(z==za&&za==zaa&&za==0){
			cout<<0<<endl;
			continue;
		}
		
		int C=1e16,Ca=1e16,Caa=1e16;
		if(p!=0&&a%abs(p)==0) C=a/abs(p);
		if(q!=0&&b%abs(q)==0) Ca=b/abs(q);
		if(r!=0&&c%abs(r)==0) Caa=c/abs(r);
		if(z==za&&za==zaa){cout<<1<<endl;continue;}
		else if(z==za&&zaa==0){cout<<1<<endl;continue;}
		else if(z==zaa&&za==0){cout<<1<<endl;continue;}
		else if(zaa==za&&z==0){cout<<1<<endl;continue;}
		else if(zaa==0&&z==0) {cout<<1<<endl;continue;}
		else if(za==0&&z==0) {cout<<1<<endl;continue;}
		else if(za==0&&zaa==0) {cout<<1<<endl;continue;}
		else if(C==Ca&&Caa==1&&C!=1e16){cout<<1<<endl;continue;}
		else if(C==Caa&&Ca==1&&C!=1e16){cout<<1<<endl;continue;}
		else if(Ca==Caa&&C==1&&Ca!=1e16){cout<<1<<endl;continue;}
		else if(C==1&&q-r!=0&&__gcd(abs(b-c),abs(q-r))==abs(q-r)&&abs(b)%abs(q-r)==0&&abs(c)%abs(q-r)==0){cout<<2<<endl;continue;}
		else if(Ca==1&&p-r!=0&&__gcd(abs(a-c),abs(p-r))==abs(p-r)&&abs(a)%abs(p-r)==0&&abs(c)%abs(p-r)==0){cout<<2<<endl;continue;}
		else if(Caa==1&&q-p!=0&&__gcd(abs(b-c),abs(q-p))==abs(q-p)&&abs(b)%abs(q-p)==0&&abs(a)%abs(q-p)==0){cout<<2<<endl;continue;}
		else if(C==Ca&&C!=1e16){cout<<2<<endl;continue;}
		else if(C==Caa&&C!=1e16){cout<<2<<endl;continue;}
		else if(Ca==Caa&&Ca!=1e16){cout<<2<<endl;continue;}
		else if(zaa+za==z){cout<<2<<endl;continue;}
		else if(zaa+z==za){cout<<2<<endl;continue;}
		else if(z+za==zaa){cout<<2<<endl;continue;}
		else if(z==za){cout<<2<<endl;continue;}
		else if(zaa==za){cout<<2<<endl;continue;}
		else if(zaa==z){cout<<2<<endl;continue;}
		else if(zaa==0) {cout<<2<<endl;continue;}
		else if(za==0) {cout<<2<<endl;continue;}
		else if(z==0) {cout<<2<<endl;continue;}
		else cout<<3<<endl;
		
	}
	
	return 0;//福摩斯尔：盲生，你发现了华点。
}
