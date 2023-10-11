#include <iostream>
#include <cstdio>
#include <cstring>
int T,p;
bool isprime[1000500];
int list[100050],cnt;
void Prime(void) {
	isprime[1]=false;
	for(int i=2;i<=1e6;i++)
		if(isprime[i])
			for(int j=i;j<=1e6;j+=i) isprime[j]=false;
	for(int i=1;i<=1e6;i++)
		if(isprime[i]) list[++cnt]=i;
}
bool check(int x) {
	if(isprime[x]) return true;
	for(int i=1;i<=cnt;i++) {
		if(list[i]>p) return true;
		if(x%list[i]==0) return false;
	}
}
int main() {
freopen("casio.in","r",stdin);
freopen("casio.out","w",stdout);
	memset(isprime,true,sizeof(isprime));
	Prime();
	scanf("%d%d",&T,&p);
	for(int i=1;i<=T;i++) {
		int n;
		scanf("%d",&n);
		if(p==998244353) printf("998244389\n");
		else {
			for(int i=n;;i++)
				if(check(i)) {
					printf("%d\n",i);
					break;
				}
		}
	}
	return 0;
} 
