#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e6+7;
int L[Maxn],R[Maxn],stk[Maxn],top;
int n,a[Maxn],ans; 
int main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		while(top&&a[stk[top]]<=a[i]) top--;
		if(top) L[i]=stk[top];
		else L[i]=0;
		stk[++top]=i;
	}
	top=0;
	for(int i=n;i;i--){
		while(top&&a[stk[top]]<=a[i]) top--;
		if(top) R[i]=stk[top];
		else R[i]=n+1;
		stk[++top]=i;
	}
	for(int i=1;i<=n;i++) printf("%d\n",R[i]-L[i]-2);
	return 0;
}
/*
5
1
2
3
2
1
*/
