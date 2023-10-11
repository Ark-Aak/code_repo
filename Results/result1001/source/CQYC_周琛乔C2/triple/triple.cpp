#include<bits/stdc++.h>
#define z0 (z&1)
#define z1 ((z>>1)&1)
#define z2 ((z>>2)&1)
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||'9'<c)&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int T;
int a[3],b[3];
inline int Two(int a,int b,int x,int y){
	if(a-x==b-y) return 1;
	if(!x&&!y) return 1;
	if(a&&b&&x%a==0&&y%b==0&&x/a==y/b) return 1;//x/a==y/b
	return 2;
}
inline int solve(){
	int cnt=0;
	for(int i=0;i<3;i++)
		if(a[i]^b[i]) ++cnt;
	if(cnt<=1) return cnt;
	if(cnt==2){
		for(int i=0;i<3;i++)
		for(int j=i+1;j<3;j++)
			if((a[i]^b[i])&&(a[j]^b[j])) 
				return Two(a[i],a[j],b[i],b[j]);
	}
	if(Two(a[0],a[1],b[0],b[1])==1&&Two(a[1],a[2],b[1],b[2])==1) return 1;
	if(b[0]==b[1]&&b[1]==b[2]){
		if(!b[0]) return 1;
		return 2;
	}
	for(int i=0;i<3;i++)
	for(int j=i+1;j<3;j++){
		if(b[i]==b[j]&&!b[3-i-j]) return 2;
		if(!b[i]&&!b[j]) return 2;
	}
	for(int z=1;z<8;z++)
		for(int i=-100;i<=100;i++){
			if(Two(a[0]+i*z0,a[1]+i*z1,b[0],b[1])==1&&Two(a[0]+i*z0,a[2]+i*z2,b[0],b[2])==1) return 2;
			if(Two(a[0]*(z0?i:1),a[1]*(z1?i:1),b[0],b[1])==1&&Two(a[0]*(z0?i:1),a[2]*(z2?i:1),b[0],b[2])==1) return 2;
		}
	return min(min(Two(a[0],a[1],b[0],b[1]),Two(a[1],a[2],b[1],b[2])),Two(a[0],a[2],b[0],b[2]))+1;
}
int main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	read(T);
	while(T--){
		read(a[0]),read(a[1]),read(a[2]);
		read(b[0]),read(b[1]),read(b[2]);
		printf("%d\n",solve());
	}
	return 0;
}
