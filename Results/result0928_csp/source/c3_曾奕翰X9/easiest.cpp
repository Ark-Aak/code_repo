#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
inline int read() {
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9') {
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int n,m,ans;
int a[N],qzh[N];
signed main(){
	ios::sync_with_stdio(0);
	freopen("easiest.in","r",stdin);
	freopen("easiest.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=1;i<=m;i++){
		int opt=read(),l1=read(),r1=read(),l2=read(),r2=read();
		if(opt==1){
			int maxx=a[r2+1],ans=0;
			for(int i=r2+2;i<=r1;i++){
				if(a[i]<maxx) ans++;
				if(a[i]>maxx) maxx=a[i];
			}
			cout<<ans+(l2-l1)<<endl;
		}
		else{
			cout<<9<<endl;
		}
	}
	return 0;

}

