#include<bits/stdc++.h>
#define int long long
#define fir first
#define sec second
#define ls (x<<1)
#define rs (x<<1|1)
#define mid ((l+r)>>1)
#define Pr(i,j) pair<i,j>
#define PB(i) push_back(i)
#define MP(i,j) make_pair(i,j)
#define Fo(i,j) for(auto i:j)
#define mem(i,j) memset(i,j,sizeof(i))
#define FO(i,j,k) for(int i=j;i;i=k)
#define FFF(i,j,k) for(auto i=j;i!=k;++i)
#define For(i,j,k) for(long long i=j;i<=k;++i)
#define FoR(i,j,k) for(long long i=j;i^k;++i)
#define FOR(i,j,k) for(long long i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}
#define N 1000005
int n,l,r,s;
int a[N];
signed main(){
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
    cin>>n>>l>>r;
    int t=l,k=0;
    For(i,1,min(n,3ll))a[i]=t;t++;
    For(i,4,n){
    	if(k%3==0)a[i]=t;
    	if(k%3==1)a[i]=t;
    	if(k%3==2)a[i]=l;
        k++;
        if(k%3==0)k=0,t++;
    }
    if(a[n]>r)cout<<"Shinomiya";
    else For(i,1,n)cout<<a[i]<<endl;
    return 0;
}
