#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch>'9'||ch<'0')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch<='9'&&ch>='0')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	}
	template<typename T>
	inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

const int Maxn=3010;
int T,n;
char s[Maxn];
int main(){
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	qread(T);
	while(T--){
		cin>>(s+1);
		n=strlen(s+1);
		int ans=0;
		for(int l=1;l<=n;l++){
			int res=0;
			for(int j=1;j<=l;j++)
				if((l-2*j)%2==0&&(l-2*j)>0) res++;
			ans+=res*(n-l+1);
		}
		
		printf("%d\n",max(0,ans));
	}
	return 0;
}


