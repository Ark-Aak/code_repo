#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
char s[1000005];
int l0,r0,l1,r1;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		scanf("%s",s+1);
		l0=r0=l1=r1=0; 
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				if(!l0) l0=i;
				r0=i;
			}
			if(s[i]=='1'){
				if(!l1) l1=i;
				r1=i;
			}
		}
		if(r1-l1+1<=k){
			cout<<"win"<<endl;
			continue;//判斷他是否能贏，就是能夠一次轉完全部的時候
		}
		if(r0-l0+1<=k){
			cout<<"win"<<endl;
			continue;
		}
		if(n<=2*k){
			if(max(r1-l1+1,r0-l0+1)-2>=k){
				cout<<"tie"<<endl;
				continue;
			}
			cout<<"lose"<<endl;//會輸的情況有且僅有無論第一個人怎麽轉，第二個人都能翻完
			continue;
		}
		cout<<"tie"<<endl;
	}
	return 0;
}
/*
  
 10 5
  0101011001
  9 5
  111010000
 */
