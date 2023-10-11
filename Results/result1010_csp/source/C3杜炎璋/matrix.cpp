#include<bits/stdc++.h>
using namespace std;
namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;
bitset<23> bit1[200005],bit2[200005];
int a[23][200005];
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	n=in,m=in;
	for(int i=1;i<=n;i++) {
		string s;
		cin>>s;
		for(int j=0;j<m;j++) if(s[j]=='1') a[i][j+1]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++){
			bit1[j][i]=a[i][j];
		}
	}
	int f[2][1<<(13)][2];
	memset(f,0x3f,sizeof f);
	for(int i=0;i<(1<<n);i++) f[0][i][0]=f[0][i][1]=0;
	for(int k=1;k<=m;k++) {
		int minn=1e9;
		for(int i=0;i<(1<<n);i++) {	 
			bit1[k]^=(i<<1);
			int cnt=bit1[k].count(),minx=min(f[1-(k&1)][i][0],f[1-(k&1)][i][1]);
			f[k&1][i][0]=min(f[k&1][i][0],cnt+minx);
			cnt=(n)-(bit1[k]).count();
			f[k&1][i][1]=min(f[k&1][i][1],cnt+minx);
			f[1-(k&1)][i][0]=1e9;
			f[1-(k&1)][i][1]=1e9;
			minn=min(minn,min(f[k&1][i][0],f[k&1][i][1]));
			bit1[k]^=(i<<1);
		}	
		if(k==m) {
			printf("%d",minn);
			return 0;
		}
	}
	return 0;
}

