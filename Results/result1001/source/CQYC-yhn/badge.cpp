#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,q,m,t1,sum[500005];
struct ok{
	int l,r;
}a[500005];
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
signed main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++) a[i].l=read(),a[i].r=read();
	for(int i=1;i<=q;i++){
		m=read();
		for(int j=1;j<=n;j++) sum[j]=0;
		for(int j=1;j<=m;j++){
			t1=read();
			sum[t1]^=1;
		}
		for(int j=1;j<=n;j++) sum[j]^=sum[j-1];
		int tot=0;
		for(int j=1;j<=n;j++){
			if(sum[a[j].r]^sum[a[j].l-1]) tot++;
		}
		cout<<tot<<"\n";
	}
    return 0;
}

