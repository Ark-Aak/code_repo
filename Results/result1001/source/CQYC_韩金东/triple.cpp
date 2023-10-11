#include<bits/stdc++.h>
#define int long long
#define il inline
#define ct const
#define dl double
#define pk push_back
#define fi first
#define se second
#define pii pair<int,int>
#define N 1000010
#define inf (int)(1000000000000000000)
using namespace std;
bool ppp;
il int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);ch=getchar();
	}
	return x*f;
}
char f__[40];
il void write(int x){
	int cnt=0;
	if(x<0){
		putchar('-');x=-x;
	}
	if(!x) putchar('0');
	while(x){
		f__[cnt++]=x%10+'0';x/=10;
	}
	while(cnt) putchar(f__[--cnt]);
}
int T,tmp[3];
struct node{
    int a[3];
} A,B;
vector<pii> V;
il int calc(){
    int flag=1,lst;
    for(int i=0;i<3;++i) if(A.a[i]!=B.a[i]){
        flag=0;break;
    }
    if(flag) return 1;
    lst=inf;flag=1;
    for(int i=0;i<3;++i) if(A.a[i]!=B.a[i]){
        if(lst<inf&&B.a[i]-A.a[i]!=lst){
            flag=0;break;
        }
        lst=B.a[i]-A.a[i];
    }
    if(flag) return 2;
    lst=inf;flag=1;
    for(int i=0;i<3;++i) if(A.a[i]!=B.a[i]){
        if(!A.a[i]||(B.a[i]%A.a[i])||(lst<inf&&B.a[i]/A.a[i]!=lst)){
            flag=0;break;
        }
        lst=B.a[i]/A.a[i];
    }
    if(flag) return 2;
    return 3;
}
// il int gcd(int a,int b){
//     if(a<0&&b<0){
//         a=-a;b=-b;
//     }
//     // cerr<<a<<" "<<b<<"\n";
//     return b?gcd(b%a,a):a;
// }
bool pppp;
signed main(){
    // cerr<<gcd(8,12);
    // return 0;
    // cerr<<(&ppp-&pppp)/1024.0/1024.0<<"\n";
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
    T=read();
    while(T--){
        // cerr<<T<<" ";
        for(int i=0;i<3;++i) A.a[i]=read();
        for(int i=0;i<3;++i) B.a[i]=read();
        if(A.a[0]==B.a[0]&&A.a[1]==B.a[1]&&A.a[2]==B.a[2]){
            puts("0");continue;
        }
        for(int i=0;i<3;++i){
            V.pk(pii(0,B.a[i]-A.a[i]));
            if(A.a[i]&&!(B.a[i]%A.a[i])) V.pk(pii(1,B.a[i]/A.a[i]));
        }
        V.pk(pii(1,0));
        sort(V.begin(),V.end());
        V.resize(unique(V.begin(),V.end())-V.begin());
        int sz=V.size(),ans=3;
        if(A.a[0]-A.a[1]&&!((B.a[0]-B.a[1])%(A.a[0]-A.a[1]))){
            int k=(B.a[0]-B.a[1])/(A.a[0]-A.a[1]);
            if(B.a[0]-k*A.a[0]==B.a[1]-k*A.a[1]&&B.a[1]-k*A.a[1]==B.a[2]-k*A.a[2]) ans=2;
            // cerr<<"ERROR";
        }
        if(A.a[1]-A.a[0]&&!((B.a[0]*A.a[1]-B.a[1]*A.a[0])%(A.a[1]-A.a[0]))){
            int k=(B.a[0]*A.a[1]-B.a[1]*A.a[0])/(A.a[1]-A.a[0]);
            if(A.a[0]&&A.a[1]&&A.a[2]&&!((B.a[0]-k)%A.a[0])&&!((B.a[1]-k)%A.a[1])&&!((B.a[2]-k)%A.a[2])&&(B.a[0]-k)/A.a[0]==(B.a[1]-k)/A.a[1]&&(B.a[1]-k)/A.a[1]==(B.a[2]-k)/A.a[2]) ans=2;
        }
        // cerr<<sz<<" ";
        for(int i=0;i<sz;++i){
            for(int j=1;j<8;++j){
                if(V[i].fi){
                    memcpy(tmp,A.a,sizeof(tmp));
                    for(int k=0;k<3;++k) if((1<<k)&j) A.a[k]*=V[i].se;
                // cerr<<i<<" "<<j<<"\n";
                    ans=min(ans,calc());
                    memcpy(A.a,tmp,sizeof(A.a));
                    int flag=1;
                    for(int k=0;k<3;++k) if(((1<<k)&j)&&(!V[i].se||(B.a[k]%V[i].se))){
                        flag=0;break;
                    }
                    if(flag){
                        memcpy(tmp,B.a,sizeof(tmp));
                        for(int k=0;k<3;++k) if((1<<k)&j) B.a[k]/=V[i].se;
                        ans=min(ans,calc());
                        memcpy(B.a,tmp,sizeof(B.a));
                    }
                }
                else{
                    for(int k=0;k<3;++k) if((1<<k)&j) A.a[k]+=V[i].se;
                    ans=min(ans,calc());
                    for(int k=0;k<3;++k) if((1<<k)&j) A.a[k]-=V[i].se;
                    for(int k=0;k<3;++k) if((1<<k)&j) B.a[k]-=V[i].se;
                    ans=min(ans,calc());
                    for(int k=0;k<3;++k) if((1<<k)&j) B.a[k]+=V[i].se;
                }
            }
        }
        write(ans);putchar('\n');
        V.clear();
    }
    cerr<<"\n"<<(dl)clock()/CLOCKS_PER_SEC;
	// cerr<<"ERROR";
	return 0;
}