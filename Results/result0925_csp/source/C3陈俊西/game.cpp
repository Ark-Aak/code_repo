#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
int T,n,k;
char a[N],b[N];
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	T=read();
	while(T--){
		bool over=0;
		n=read(),k=read();
		for(int i=1;i<=n;i++) cin>>a[i];
		
		if(n>1000){
			int l0=0,r0=0,l1=0,r1=0;
			for(int i=1;i<=n;i++)
				if(a[i]=='0') l0=i,i=n+1;
			for(int i=1;i<=n;i++)
				if(a[i]=='1') l1=i,i=n+1;		
			for(int i=n;i>=1;i--)
				if(a[i]=='0') r0=i,i=0;
			for(int i=n;i>=1;i--)
				if(a[i]=='1') r1=i,i=0;
			if(r0-l0+1<=k||r1-l1+1<=k) printf("win\n");
			else printf("tie\n"); 		
			continue; 	
		}
		
		for(int i=1;i<=n-k+1;i++){
			bool same=1;
			for(int j=1;j<=n;j++) b[j]=a[j];
			for(int j=i;j<=i+k-1;j++) b[j]='1';
			for(int j=1;j<=n;j++) if(b[j]=='0') same=0,j=n+1;
			if(same){
				cout<<"win\n";
				over=1;
				break;
			}
		
			same=1;
			for(int j=i;j<=i+k-1;j++) b[j]='0';
			for(int j=1;j<=n;j++) if(b[j]=='1') same=0,j=n+1;
			if(same){
				cout<<"win\n";
				over=1;
				break;
			}
		}
		if(over) continue;
		int win=0;
		for(int i=1;i<=n-k+1;i++){
			for(int j=1;j<=n;j++) b[j]=a[j];
			for(int j=i;j<=i+k-1;j++) b[j]='1';
			
			int l0=0,r0=0,l1=0,r1=0;
			for(int sss=1;sss<=n;sss++)
				if(b[sss]=='0') l0=sss,sss=n+1;
			for(int sss=1;sss<=n;sss++)
				if(b[sss]=='1') l1=sss,sss=n+1;		
			for(int sss=n;sss>=1;sss--)
				if(b[sss]=='0') r0=sss,sss=0;
			for(int sss=n;sss>=1;sss--)
				if(b[sss]=='1') r1=sss,sss=0;
			if(r0-l0+1<=k||r1-l1+1<=k) win++;
			////////////////////////////////////////////////////
			for(int j=i;j<=i+k-1;j++) b[j]='0';
			
			l0=0,r0=0,l1=0,r1=0;
			for(int sss=1;sss<=n;sss++)
				if(b[sss]=='0') l0=sss,sss=n+1;
			for(int sss=1;sss<=n;sss++)
				if(b[sss]=='1') l1=sss,sss=n+1;		
			for(int sss=n;sss>=1;sss--)
				if(b[sss]=='0') r0=sss,sss=0;
			for(int sss=n;sss>=1;sss--)
				if(b[sss]=='1') r1=sss,sss=0;
			if(r0-l0+1<=k||r1-l1+1<=k) win++;
		}
		if(win==2*(n-k+1)) printf("lose\n");
		else printf("tie\n");
	}
	return 0;
}	
