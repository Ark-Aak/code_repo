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

const int Maxn=3e7+7;
int n,P,T;
int p[Maxn],cnt,low[Maxn];
bitset<Maxn>isp;
vector<int>s;
inline void init(int N){
	isp[0]=isp[1]=1;
	for(int i=2;i<=N;i++){
		if(!isp[i]) p[++cnt]=i,low[i]=i;
		for(int j=1;j<=cnt&&p[j]*i<=N;j++){
			isp[i*p[j]]=1;
			low[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
	for(int i=1;i<=N;i++)
		if(low[i]>P||!isp[i]) s.push_back(i);
} 
int main(){
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	qread(T),qread(P);
	init(Maxn-7);
	while(T--){
		qread(n);
		ll pos=lower_bound(s.begin(),s.end(),n)-s.begin();
		write(s[pos]);
		putchar('\n');
	}
	return 0;
}
/*
2 3
22
25
*/
