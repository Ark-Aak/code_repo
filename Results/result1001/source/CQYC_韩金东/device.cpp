#include<bits/stdc++.h>
#define int long long
#define il inline
#define ct const
#define dl double
#define pk push_back
#define fi first
#define se second
#define pii pair<int,int>
#define N 1000010
#define inf (int)(1000000000000000000)
using namespace std;
bool ppp;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);ch=getchar();
	}
	return x*f;
}
char f__[40];
il void write(int x){
	int cnt=0;
	if(x<0){
		putchar('-');x=-x;
	}
	if(!x) putchar('0');
	while(x){
		f__[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f__[--cnt]);
}
int T,K,n,cnt[20],ans;
bool pppp;
signed main(){
    // cerr<<(&ppp-&pppp)/1024.0/1024.0<<"\n";
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	T=read();
    while(T--){
        K=read();n=read();
        if(!n) puts("1");
        else{
            int a[3]={K%10,K/10%10,K/100};
			sort(a,a+3);
            if(n==1){
                if(a[0]==a[1]&&a[1]==a[2]) puts("1");
                else if(a[0]==a[1]||a[1]==a[2]) puts("7");
                else puts("24");
            }
            else{
                if(a[0]==a[1]&&a[1]==a[2]) puts("1");
                else if(a[0]==a[1]||a[1]==a[2]) puts("8");
                else puts("27");
			}
        }
    }
    cerr<<"\n"<<(dl)clock()/CLOCKS_PER_SEC;
	// cerr<<"ERROR";
	return 0;
}