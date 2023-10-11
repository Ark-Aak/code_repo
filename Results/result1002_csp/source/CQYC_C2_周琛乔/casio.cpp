#include<bits/stdc++.h>
using namespace std;
const int N=3e7;
inline void read(int &x){
   int f=1;x=0;char c=getchar();
   while((c<'0'||'9'<c)&&c^'-') c=getchar();
   if(c=='-') f=-1,c=getchar();
   while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
   x*=f;
}
int T,p,n,nxt,zhi[N+5],cnt;
int h[N+5],ans[N+5];
void print(int x){
	if(x>9) print(x/10);
	putchar('0'+x%10);
}
int main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	for(int i=2;i<=N;i++){
		if(!h[i]) zhi[++cnt]=i;
		for(int j=1;j<=cnt&&zhi[j]*i<=N;j++){
			h[i*zhi[j]]=zhi[j];
			if(i%zhi[j]==0) continue;
		}
	}
	read(T),read(p);
	for(int i=N,nxt=N+1;i;--i){
		if(h[i]>p||!h[i]) nxt=i; 
		ans[i]=nxt;
	}
	while(T--){
		read(n);
		print(ans[n]);
		putchar('\n');
	}
	return 0;
}
