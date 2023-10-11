#include<bits/stdc++.h>
using namespace std;
int f[1000005];
map<int,int> ma;
int tail=0,head=1;
int main() {
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	int n,l,r,x,now;
	scanf("%d %d %d",&n,&l,&r);
	x=l;
	now=l;
	for(int i=1;i<=n;i++) {
		if(x==r+1) now++,x=now;
		if(now>r) {
			printf("Shinomiya");
			return 0;
		}
		if(i%2==1) {
			if(tail<4) tail++;
			else ma[f[head++]]--;
			ma[now]++;
			f[i]=now;
		} else {
			if(tail<4) tail++; 
			else ma[f[head++]]--;
			ma[x]++;
			if(ma[x]>=4) {
				x++;
				if(x==r+1) {
					now++,x=now;
					ma[x]--;
					ma[f[i-1]]--;
					i-=2;
					break;
				}
			}
			f[i]=x;
			x++;
		}
	}
	for(int i=1;i<=n;i++) {
		printf("%d\n",f[i]);
	}
	return 0;
}
