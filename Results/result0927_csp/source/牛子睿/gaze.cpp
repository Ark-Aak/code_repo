#include <iostream>
#include <cstdio>
const int N=200050;
int n,T,a[N];
void solve1(void) {
	int val;
	while(T--) {
		int op,x,y;
		scanf("%d",&op);
		if(op==1) {
			scanf("%d",&x);
			val=x;
			int res=0;
			for(int i=1;i<=n;i++) {
				if(a[i]>=val&&a[i-1]<val) ++res;
			}
			printf("%d\n",res);
		}
		if(op==2) {
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
	}
}
int main() {
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	scanf("%d%d",&n,&T);
	a[0]=-0x7fffffff;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
//	if(n<=2000&&T<=2000) solve1();
//	else solve2();
	solve1();
	return 0;
}
