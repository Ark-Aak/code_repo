#include<bits/stdc++.h>
#define db doub
#define int long long
#define inf LONG_LONG_MAX
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
#define For(i,j,k) for(int i=j;i<=k;++i)
#define FoR(i,j,k) for(int i=j;i^k;++i)
#define FOR(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
template <typename _Tp>void read(_Tp& first) {
    _Tp x = 0, f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
    first = x * f;
}
#define N 100005
#define Mod 1000000007
struct Node{
	int x,y;
};
int T,n,k;
int X[N],Y[N];
Node s,t;
Node l[N],r[N];
char a[N];
bool checkC(){
    int x=X[n],y=Y[n],s=0;
    if(!x||!y)return 1;
    For(i,1,n)if(a[i]=='0'){
        For(j,i,min(i+k-1,n))if(a[j]=='0')s++;
        if(s==x)return 1;
        break;
    }s=0;
    For(i,1,n)if(a[i]=='1'){
        For(j,i,min(i+k-1,n))if(a[j]=='1')s++;
        if(s==y)return 1;
        break;
    }return 0;
}
bool checkD(){
	For(i,1,n-k+1){
		int j=i+k-1;
		if(X[i-1]&&(X[n]-X[j]))return 0;
		if(X[i-1]&&l[i-1].x-s.x+1>k)return 0;
		if((X[n]-X[j])&&t.x-r[j+1].x>k)return 0;
		
		if(Y[i-1]&&(Y[n]-Y[j]))return 0;
		if(Y[i-1]&&l[i-1].y-s.y+1>k)return 0;
		if((Y[n]-Y[j])&&t.y-r[j+1].y>k)return 0;
	}return 1;
}
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    read(T);
    while(T--){
        read(n),read(k);cin>>a+1;
        s.x=s.y=1e16;
        t.x=t.y=0;
        For(i,1,n){
        	X[i]=X[i-1],Y[i]=Y[i-1];
        	if(a[i]=='0')X[i]++;
	        else Y[i]++;
		}
//		For(i,1,n)
//		if(a[i]=='0')s.x=min(s.x,i),t.x=max(t.x,i);
//		else s.y=min(s.y,i),t.y=max(t.y,i);
		For(i,1,n){
			l[i]=l[i-1];
			if(a[i]=='0')l[i].x=i,s.x=min(s.x,i);
			else l[i].y=i,s.y=min(s.y,i);
		}r[n+1].x=r[n+1].y=n+1;
		FOR(i,n,1){
			r[i]=r[i+1];
			if(a[i]=='0')r[i].x=i,t.x=max(t.x,i);
			else r[i].y=i,t.y=max(t.y,i);
		}
        if(checkC())cout<<"win"<<endl;
        else if(checkD())cout<<"lose"<<endl;
        else cout<<"tie"<<endl;
    }
    return 0;
}
/*
3
4 2
0101
4 1
0101
4 2
0011

1
10 4
0000000001
*/
