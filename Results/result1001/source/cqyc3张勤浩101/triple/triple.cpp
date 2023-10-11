#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T;
ll p,q,r,a,b,c,ji;
int main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&p,&q,&r,&a,&b,&c);
		++ji;
		if(p==a&&q==b&&c==r){
			printf("0\n");
			continue;
		}
		
		
		ll d[3],xs=(p==a)+(q==b)+(c==r);
		d[0]=a-p,d[1]=b-q,d[2]=c-r;
		sort(d,d+3);
		ll cnt0=(d[0]==0)+(d[1]==0)+(d[2]==0);
		if(((d[0]==d[1]||d[1]==d[2])&&cnt0==1)||(cnt0>=2)||(d[0]==d[1]&&d[1]==d[2])){
			printf("1\n");
			continue;
		}
		if(p==0) d[0]=0;
		else d[0]=a/p;
		if(q==0)d[1]=0;
		else d[1]=b/q;
		if(r==0) d[2]=0;
		else d[2]=c/r;
		ll ccc=0;
		if(d[0]&&a!=p) ccc=d[0];
		else if(d[1]&&b!=q) ccc=d[1];
		else if(d[2]&&c!=r) ccc=d[2];
		ll a1=p,b1=q,c1=r,cc1=(p==a?1:ccc),cc2=(q==b?1:ccc),cc3=(r==c?1:ccc);
		if(cc1*a1==a&&b1*cc2==b&&c1*cc3==c){
			printf("1\n");
			continue;
		}
		
		
		if(xs>=1){
			printf("2\n");
			continue;
		}
		ll tq=(a==0)+(b==0)+(c==0);
		if(tq>=2){
			printf("2\n");
			continue;
		}
		d[0]=a-p,d[1]=b-q,d[2]=c-r;
		sort(d,d+3);
		ll ppp=(d[0]==d[1])+(d[1]==d[2])+(d[0]==d[2]);
		ll p1=q-p,p2=r-q;
		ll ttt=__gcd(p1,p2);
		if(ttt!=0){
			if(ttt%(b-a)==0&&ttt%(c-b)==0){
				printf("2\n");
				continue;
			}
		}
		if(ppp>=1){
			printf("2\n");
			continue;
		}
		
		printf("3\n");
	}
	return 0;
}
/*
2
3 5 7
6 5 10
8 6 3
9 7 8

*/
