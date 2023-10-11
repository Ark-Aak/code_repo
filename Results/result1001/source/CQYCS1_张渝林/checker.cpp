#include<bits/stdc++.h>
#define ll long long
#define L xd[x].l
#define R xd[x].r
#define mid (l+r>>1LL)
#define lc L,l,mid
#define rc R,mid+1,r
#define Root 1,1,n
#define OK l>=Ll&&r<=Rr
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define pb push_back
#define ull unsigned ll
#define e(x) for(int i=h[x],y=to[i];i;i=nxt[i],y=to[i])
#define E(x) for(auto y:p[x])
#define Pi pair<int,int>
#define ui unsigned ll
inline int read(){int s=0,w=1;char c=getchar();while(c<48||c>57) {if(c=='-') w=-1;c=getchar();}while(c>=48&&c<=57) s=(s<<1)+(s<<3)+c-48,c=getchar();return s*w;}
inline void pf(ll x){if(x<0) putchar('-'),x=-x;if(x>9)pf(x/10);putchar(x%10+48);}
const int N =5e5+5,M=1e6+5,inf=(1LL<<31)-1;
const ll llf=1e18,mod=1e8+7,bas=131;
const ui base=13331;
using namespace std;
int a[M<<1];
int s[M<<1],top;
int main(){
	int T=100000;
	freopen("triple2.ans","r",stdin);
	rep(i,1,T)a[i]=read();
	freopen("triple.out","r",stdin);
	rep(i,1,T){
		int x=read();
		if(x!=a[i]){
			cerr<<"On test "<<i<<",the answer is "<<a[i]<<".But you output "<<x<<".\n";
			s[++top]=i;
		}
	}
	freopen("triple2.in","r",stdin);
	T=read();
	int l=1;
	rep(i,1,T){
		int a=read(),b=read(),c=read(),x=read(),y=read(),z=read();
		if(i==s[l]){
			cerr<<"Case "<<i<<" is like:"<<"("<<a<<","<<b<<","<<c<<")->("<<x<<","<<y<<","<<z<<")\n";
			l++;
		}
	} 
	if(top==0)cerr<<"Congratulations£¡£¡£¡All answers are right£¡£¡£¡"; 
	return 0;
}
