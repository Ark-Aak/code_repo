#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=1001;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t,k,n;
signed main(){
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	t=read();
	while(t--){
		k=read(),n=read();
		if(n==0){
			printf("1\n");
			continue;
		}
		else if(n==1){
			int s1=k%10,s2=k%100/10,s3=k/100;
			if(s1!=s2&&s1!=s3&&s2!=s3){
				printf("24\n");
				continue;
			}
			if(s1==s2&&s1==s3&&s2==s3){
				printf("1\n");
				continue;
			}
			printf("7\n");
		}
		else{
			int s1=k%10,s2=k%100/10,s3=k/100;
			if(s1!=s2&&s1!=s3&&s2!=s3){
				printf("27\n");
				continue;
			}
			if(s1==s2&&s1==s3&&s2==s3){
				printf("1\n");
				continue;
			}
			printf("8\n");			
		}
	}
	return 0;
}
