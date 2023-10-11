#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int t,x,y,z,a,b,c,ans;
void dfs(int v1,int v2,int v3,int siz){
	if(v1==a&&v2==b&&v3==c){
		ans=min(ans,siz-1);
		return;
	} 
	if(siz==4) return;
	for(int k=-20;k<=20;k++){
		dfs(v1+k,v2,v3,siz+1);
		dfs(v1,v2+k,v3,siz+1);
		dfs(v1,v2,v3+k,siz+1);
		
		dfs(v1+k,v2+k,v3,siz+1);		
		dfs(v1+k,v2,v3+k,siz+1);
		dfs(v1,v2+k,v3+k,siz+1);
		
		dfs(v1+k,v2+k,v3+k,siz+1);
		
		dfs(v1*k,v2,v3,siz+1);
		dfs(v1,v2*k,v3,siz+1);
		dfs(v1,v2,v3*k,siz+1);
		
		dfs(v1*k,v2*k,v3,siz+1);		
		dfs(v1*k,v2,v3*k,siz+1);
		dfs(v1,v2*k,v3*k,siz+1);
		
		dfs(v1*k,v2*k,v3*k,siz+1);	
	}
	return;
}
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	t=read();
	while(t--){
		x=read(),y=read(),z=read();
		a=read(),b=read(),c=read();
		int c1=a-x,c2=b-y,c3=c-z;
		int s1,s2,s3;
		
		if(x!=0) s1=a/x;
		else s1=0;
		if(y!=0) s2=b/y;
		else s2=0;
		if(z!=0) s3=c/z;
		else s3=0;		
		
		if(c1==c2&&c2==c3){//cha deng
			printf("1\n");
			continue;
		}
		if(x*s1==a&&y*s2==b&&z*s3==c&&s1==s2&&s2==s3){//shang deng
			printf("1\n");
			continue;
		}
		if(x==a&&y==b&&z==c){
			printf("0\n");
			continue;
		}
		if(x==a&&y==b){
			printf("1\n");
			continue;
		}
		if(x==a&&z==c){
			printf("1\n");
			continue;
		}
		if(z==c&&y==b){
			printf("1\n");
			continue;
		}
		if(x==a){
			if(c2==c3){
				printf("1\n");	
				continue;
			} 
			if(y*s2==b&&z*s3==c&&s2==s3){
				printf("1\n");
				continue;
			}
			printf("2\n");
			continue;
		}
		if(y==b){
			if(c1==c3){
				printf("1\n");	
				continue;
			} 
			if(x*s1==a&&z*s3==c&&s1==s3){
				printf("1\n");
				continue;
			}
			printf("2\n");
			continue;
		}
		if(z==c){
			if(c1==c2){
				printf("1\n");	
				continue;
			} 
			if(y*s2==b&&x*s1==a&&s2==s1){
				printf("1\n");
				continue;
			}
			printf("2\n");
			continue;
		}
		ans=4;
		dfs(x,y,z,1);
		printf("%d\n",ans);
	}
	return 0;
}
