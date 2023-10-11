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

const int Maxn=2e5+7;

int m,t,n,q;
int sm,sn,ss;
struct node{
	int t,k;
}a[Maxn];
inline bool cmp(node x,node y){
	if(x.t==y.t) return x.k<y.k;
	return x.t<y.t;
}
int main(){
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout);
	qread(m),qread(t),qread(n),qread(q);
	sm=m;
	for(int i=1;i<=n;i++){
		string sk;
		scanf("%d",&a[i].t);
		cin>>sk;
		if(sk=="SM") a[i].k=1;
		if(sk=="SN") a[i].k=2;
		if(sk=="SS") a[i].k=3;
	}
	sort(a+1,a+n+1,cmp);
	while(q--){
		int s;
		qread(s);
		cout<<(t-s)/3<<" "<<(t-s)/2<<endl;
	}
	return 0;
}
/*
Ì°ÐÄ 
*/

