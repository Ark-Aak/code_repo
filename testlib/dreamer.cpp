#include <bits/stdc++.h>
#define ll long long
#define lll __int128

ll m,k;
inline void qread(ll &x){
	x=0;char ch;bool f=0;
	while((ch=getchar())&&(ch>'9'||ch<'0')) if(ch=='-') f=1;x=(ch^48);
	while((ch=getchar())&&(ch>='0'&&ch<='9')) x=(x<<1)+(x<<3)+(ch^48),x%=m;
	x=f?-x:x;
}

using namespace std;

ll ans;
ll T=20,t;

struct Divs{
	ll x;
	int ap;
}dvs[30];

ll h[1<<19|2],f[1<<19|2];
int cnt[1<<19|2];

template<typename T>
inline T up(T x){
	return (x%m+m)%m;
}

inline ll ksm(ll a,ll b,ll mod){
	ll z=1;a%=mod;
	while(b){
		if(b&1) z=(lll)z*a%mod;
		a=(lll)a*a%mod;
		b>>=1;
	}
	return z;
}
inline ll G(int x){
	return ksm(k-1,cnt[x],m);
}
inline ll getnm(int x){
	ll res=1;
	for(int i=0;i<t;i++) if(x>>i&1) res=res*dvs[i].x%m;
	return res;
}

void DFS_dvs(int p,ll x,int e1,int e2,ll oth){
	ll j=x%m;
	ans=(ans+f[e1]*(oth%m*oth%m)%m*j%m*j%m*h[e2]%m)%m;
	
//	cout<<"sd ";write(x);cout<<' '<<oth<<" " <<f[e1]*oth%m*oth%m<<endl;
	
	
	for(int i=p+1;i<t;i++){
		ll y=1,lst=1;
		for(int j=1;j<=dvs[i].ap;j++){
			y=y*dvs[i].x%m;
			ll nxtoth=oth;
			if(j>1) nxtoth=oth*lst%m;
			if(j!=dvs[i].ap) DFS_dvs(i,x*y%m,e1|(1<<i),e2,nxtoth);
			else DFS_dvs(i,x*y%m,e1|(1<<i),e2^(1<<i),nxtoth);
			lst=y;
		}
	}
}

int main(int argc, char *argv[]) {
	freopen(argv[1], "rb", stdin);
	freopen(argv[2], "wb", stdout);
	for(int i=0;i<(1<<19);i++) cnt[i]=cnt[i>>1]+(i&1);
	scanf("%lld",&T);
	while(T--){
		ans=0;
		
		scanf("%lld%lld",&k,&m);
		scanf("%lld",&t);
		for(int i=0;i<t;i++) qread(dvs[i].x),scanf("%d",&dvs[i].ap);
		
		for(int i=0;i<(1<<t);i++) h[i]=G(i)*getnm(i)%m,f[i]=(getnm(i)%m)*(getnm(i)%m)%m;
		for(int i=0;i<t;i++)
			for(int j=0;j<(1<<t);j++)
				if(j>>i&1) h[j]=up(h[j^(1<<i)]+h[j]),f[j]=up(-f[j^(1<<i)]+f[j]);
		
		DFS_dvs(-1,1,0,(1<<t)-1,1);  
		
		printf("%lld\n",ans);
	}
	return 0;
}

/*
10
2 1
3 1
5 1
7 1
11 1
13 1
17 1
19 1
23 1
29 1
11451 191981012
2
2 10
3 10
514 520
*/
