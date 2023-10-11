#include<bits/stdc++.h>
using namespace std;
int n,h[1000005]; 
int l[1000005],r[1000005];
int s[1000005];
int t;
int main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	for(int i=1;i<=n;i++){
		while(h[i]>h[s[t]]&&t>0) r[s[t]]=i,t--;
		s[++t]=i;
	}
	t=0;
	for(int i=n;i>=1;i--){
		while(h[i]>h[s[t]]&&t>0) l[s[t]]=i,t--;
		s[++t]=i;
	}
	for(int i=1;i<=n;i++){
		if(l[i]==0) l[i]=0;
		if(r[i]==0) r[i]=n+1;
		printf("%d\n",r[i]-l[i]-2);
	}
	return 0;
}
