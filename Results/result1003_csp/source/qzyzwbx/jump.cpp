#include<bits/stdc++.h>
using namespace std;
int n,a[500007],f[500007],w[500007],top,s[500007];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	f[0]=0;
	a[0]=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		while(top&&a[s[top]]<=a[i]){
			top--;
		}
		w[i]=s[top];
		s[++top]=i;
	}
	for(int i=1;i<=n;i++)
		f[i]=f[w[i]]+1;
	for(int i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	return 0;
} 

