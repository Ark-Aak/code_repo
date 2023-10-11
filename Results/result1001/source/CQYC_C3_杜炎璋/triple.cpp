#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	int t,s=0;
	scanf("%lld",&t);
	while(t--) {
		int x,y,z,a,b,c,ans=3;
		scanf("%lld %lld %lld %lld %lld %lld",&x,&y,&z,&a,&b,&c);
		if(abs(x)+abs(y)+abs(z)+abs(a)+abs(b)+abs(c)<=100) {
			for(int i=-50; i<=50; i++) {
				for(int j=-50; j<=50; j++) {
					for(int l=1; l<(1<<4); l++) {
						for(int r=1; r<(1<<4); r++) {
							int f[5];
							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]+=i;
								}
							}
							for(int k=1; k<=3; k++) {
								if(r&(1<<(k-1))) {
									f[k]+=j;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,2ll);

							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]*=i;
								}
							}
							for(int k=1; k<=3; k++) {
								if(r&(1<<(k-1))) {
									f[k]+=j;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,2ll);

							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]+=i;
								}
							}
							for(int k=1; k<=3; k++) {
								if(r&(1<<(k-1))) {
									f[k]*=j;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,2ll);

							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]*=i;
								}
							}
							for(int k=1; k<=3; k++) {
								if(r&(1<<(k-1))) {
									f[k]*=j;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,2ll);
						}
					}
				}
			}
			for(int i=-20; i<=20; i++) {
				for(int j=-20; j<=20; j++) {
					for(int l=1; l<(1<<3); l++) {
						for(int r=1; r<(1<<3); r++) {
							int f[5];
							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]+=i;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,1ll);

							f[1]=x;
							f[2]=y;
							f[3]=z;
							for(int k=1; k<=3; k++) {
								if(l&(1<<(k-1))) {
									f[k]*=i;
								}
							}
							if(f[1]==a && f[2]==b && f[3]==c) ans=min(ans,1ll);
						}
					}
				}
			}
			if(x==a && y==b && c==z) ans=min(ans,0ll);
		} else if(a==x) {
			int chu1=1e12,chu2=1e12,chu3=1e12;
			if(x!=0) chu1=a/x;
			if(chu1==0) chu1=1e12;
			if(y!=0) chu2=b/y;
			if(chu2==0) chu2=1e12;
			if(z!=0) chu3=c/z;
			if(chu3==0) chu3=1e12;

			if(x==a && y!=b && c!=z) ans=2;
			if(x!=a && y==b && c!=z) ans=2;
			if(x!=a && y!=b && c==z) ans=2;

			if(chu1==chu2 && x!=a && c!=z && x*chu1==a && y*chu2==b) ans=2;
			if(chu1==chu3 && x!=a && b!=y && x*chu1==a && z*chu3==c) ans=2;
			if(chu2==chu3 && x!=a && c!=z && y*chu2==b && z*chu3==c) ans=2;

			if(x*chu1==a && (b-y)==(c-z)) ans=2;
			if(y*chu2==b && (a-x)==(c-z)) ans=2;
			if(z*chu3==c && (b-y)==(a-x)) ans=2;

			if(x*chu1==a && chu1*(b/chu1)==b && chu1*(c/chu1)==c && (b/chu1)-y==(c/chu1)-z) ans=2;
			if(y*chu2==b && chu2*(a/chu2)==a && chu2*(c/chu2)==c && (a/chu2)-x==(c/chu2)-z) ans=2;
			if(z*chu3==c && chu3*(a/chu3)==a && chu3*(b/chu3)==b && (a/chu3)-x==(b/chu3)-y) ans=2;

			if(x*chu1==a && y*chu2==b && chu1==chu2 && chu1*(c/chu1)==c) ans=2;
			if(x*chu1==a && z*chu2==b && chu1==chu3 && chu2*(b/chu2)==b) ans=2;
			if(y*chu1==b && z*chu2==c && chu2==chu3 && chu3*(a/chu1)==a) ans=2;

			if(a==0 && b==0 && x!=a && y!=b && z!=c) ans=2;
			if(a==0 && c==0 && x!=a && y!=b && z!=c) ans=2;
			if(c==0 && b==0 && x!=a && y!=b && z!=c) ans=2;

			if((a-x)==(b-y) && z!=c) ans=2;
			if((a-x)==(c-z) && b!=y) ans=2;
			if((c-z)==(b-y) && a!=x) ans=2;

			if(a==0 && b==0 && c==0) ans=1;

			if(x!=a && y==b && c==z) ans=1;
			if(x==a && y!=b && c==z) ans=1;
			if(x==a && y==b && c!=z) ans=1;

			if((a-x)==(b-y) && z==c) ans=1;
			if((a-x)==(c-z) && b==y) ans=1;
			if((c-z)==(b-y) && a==x) ans=1;

			if(chu1==chu2 && chu2==chu3 && x*chu1==a && y*chu2==b && z*chu3==c) ans=1;

			if(a==x && b==y && c==z) ans=0;
		}
		printf("%d\n",ans);

	}
	return 0;
}
