#include<bits/stdc++.h>
#define int unsigned int
#define N 1000002
using namespace std;
string s;
int n,a[N];
int Q,L,R;
int o[10];
int ans[N];
signed main(){
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='m') a[i+1]=1;
		else if(s[i]=='i') a[i+1]=2;
		else if(s[i]=='l') a[i+1]=3;
		else if(s[i]=='k') a[i+1]=4;
		else a[i+1]=5;
	}
	n=s.size();
	scanf("%u",&Q);
	if(n<=1000&&Q<=1000){
		while(Q--){
			scanf("%u %u",&L,&R);
			o[0]=o[1]=o[2]=o[3]=o[4]=o[5]=0;
			for(int i=L;i<=R;i++){
				if(a[i]==1) o[1]++;
				else o[a[i]]+=o[a[i]-1];
			}
			printf("%u\n",o[5]);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1) o[1]++;
		else o[a[i]]+=o[a[i]-1];
		ans[i]=o[5];
	}
	while(Q--){
		scanf("%u %u",&L,&R);
		printf("%u\n",ans[R]-ans[L-1]);
	}
	return 0;
}


