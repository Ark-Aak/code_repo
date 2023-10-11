#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans[1000005],l[100005],r[1000005];
int main(){
	freopen("mountain.in","r",stdin);
	froepen("mountain.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int tot=0,tail=0;
	for(int i=1;i<=n;i++) {
		while(tail>0 && a[l[tail]]<a[i]) {
			ans[l[tail]]+=i-l[tail]-1;
			tail--;
		}
		l[++tail]=i;
	}
	while(tail) ans[l[tail]]+=n-l[tail],tail--;
	for(int i=n;i>=1;i--) {
		while(tail>0 && a[l[tail]]<a[i]) {
			ans[l[tail]]+=l[tail]-i-1;
			tail--;
		}
		l[++tail]=i;
	}
	while(tail) ans[l[tail]]+=l[tail]-1,tail--;
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]); 
	return 0;
}

