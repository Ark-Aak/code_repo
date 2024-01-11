#include<bits/stdc++.h>
using namespace std;
#define fp(i,l,r) for(register int (i)=(l);(i)<=(r);++(i))
#define fd(i,l,r) for(register int (i)=(l);(i)>=(r);--(i))
#define fe(i,u) for(register int (i)=front[(u)];(i);(i)=e[(i)].next)
#define mem(a) memset((a),0,sizeof (a))
#define O(x) cerr<<#x<<':'<<x<<endl
#define int long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void wr(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)wr(x/10);
	putchar('0'+x%10);
}
const int MAXN=2e5+10;
int n,Q,qop[MAXN],qk[MAXN],ql[MAXN],qr[MAXN],qx[MAXN],s[1010],ans[MAXN],BB,B;
int a1[MAXN],a2[MAXN],s1[5010],s2[5010],bel[MAXN],L[MAXN];
inline void add(int p,int v){
	if(p>n)return;p=max(p,1ll);
	a1[p]+=v;s1[bel[p]]+=v;
	v*=p;a2[p]+=v;s2[bel[p]]+=v;
}
inline int ask(int p){
	if(!p)return 0;
	int ans=0;const int pp=p+1;
	fp(i,L[bel[p]],p)ans+=pp*a1[i]-a2[i];
	fd(i,bel[p]-1,1)ans+=pp*s1[i]-s2[i];
	return ans;
}
inline void solve(int k){
	mem(s);const int sk=k-1;
	fp(i,1,Q){
		if(qop[i]==1){
			if(qk[i]!=k)continue;
			int t=0,x=qx[i],l=ql[i],r=qr[i];
			fp(j,l,r)s[j]+=(t+=x);
			fp(j,r+1,sk)s[j]+=t;
		}
		else{
			int l=ql[i],r=qr[i],bl=l/k,br=r/k,pl=l%k,pr=r%k;
			if(bl==br)ans[i]+=s[pr]-(pl?s[pl-1]:0ll);
			else ans[i]+=(br-bl)*s[sk]-s[pl-1]+s[pr];
		}
	}
}
main(){
	freopen("sorrow.in","r",stdin);freopen("sorrow.out","w",stdout);
	n=read();Q=read();B=sqrt(n);BB=B;
	fp(i,1,n){
		bel[i]=(i-1)/B+1;
		if(!L[bel[i]])L[bel[i]]=i;
	}
	fp(i,1,n){
		int x=read();
		add(i,x);add(i+1,-x);
	}
	fp(i,1,Q){
		qop[i]=read();
		if(qop[i]==1){
			qk[i]=read();ql[i]=read();qr[i]=read();qx[i]=read();
			int k=qk[i],l=ql[i],r=qr[i],x=qx[i];
			if(k>BB){
				for(int j=0;j<=n;j+=k)
				add(j+l,x),add(j+r+1,-x);
			}
		}
		else{
			ql[i]=read();qr[i]=read();
			ans[i]=ask(qr[i])-ask(ql[i]-1);
		}
	}
	fp(i,1,BB)solve(i);
	fp(i,1,Q)if(qop[i]==2)wr(ans[i]),putchar('\n');
	return 0;
}