#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch>'9'||ch<'0')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	}
	template<typename T>
	inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar('0'+x%10);
	}
}
using namespace IO;

const ll Maxn=5e5+11;
ll n,Q,l[Maxn],r[Maxn],cnt,odd[Maxn];
int main(){
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	qread(n),qread(Q);
	for(ll i=1;i<=n;i++) qread(l[i]),qread(r[i]);
	while(Q--){
		ll mk,ccc=0;
		qread(mk);
		ccc++;
		while(mk--){
			ll x;
			qread(x);
//			for(ll i=1;i<=n;i++){
//				if(l[i]<=x&&r[i]>=x){
//					cnt=cnt+(odd[i]^1?1:-1);
//					odd[i]^=1;
//				}
//			}
			odd[x]+=ccc;
		}
		//cout<<"ttt \n";
		//for(ll i=1;i<=n;i++) cout<<odd[i]<<" ";
		//cout<<endl;
		cnt=0;
		for(ll i=1;i<=n;i++){
			ll res=0;
			for(ll j=l[i];j<=r[i];j++) res+=odd[j];
			if(res&1) cnt++;
		}
			
				
		write(cnt);
		puts("");
	}
	return 0;
}
/*
5 2
4 5
3 5
2 4
1 3
5 5
4
1 2 3 4
1
4

5 2
4 5
3 5
2 4
2 3
5 5
2
2 5
3
1 2 5

*/
