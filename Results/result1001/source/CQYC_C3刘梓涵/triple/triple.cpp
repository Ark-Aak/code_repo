#include<bits/stdc++.h>
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
}inline void write(int x){
    if(x < 0) putchar('-'), x = -x;
    if(x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
#define N 200005
#define Mod 147744151
#define int long long
int T,p,q,r,a,b,c;
int ans=3;
void dfs(int x,int y,int z,int s){
    if(s==ans)return;
    if(x==a&&y==b&&z==c){
        ans=min(ans,s);
        return ;
    }
    s++;
    int cx=x-a,cy=y-b,cz=z-c;
    int sx=1e16,sy=1e16,sz=1e16;
    if(x&&a!=x){if(a%x==0)sx=a/x;}
    if(y&&b!=y){if(b%y==0)sy=b/y;}
    if(z&&c!=z){if(c%z==0)sz=c/z;}
    if(cx){
        dfs(x-cx,y-cx,z-cx,s);
        dfs(x-cx,y-cx,z,s);
        dfs(x-cx,y,z,s);
        dfs(x-cx,y,z-cx,s);
    }

    if(cy){
        dfs(x-cy,y-cy,z-cy,s);
        dfs(x-cy,y-cy,z,s);
        dfs(x,y-cy,z,s);
        dfs(x,y-cy,z-cy,s);
    }

    if(cz){
        dfs(x-cz,y-cz,z-cz,s);
        dfs(x,y-cz,z-cz,s);
        dfs(x,y,z-cz,s);
        dfs(x-cz,y,z-cz,s);
    }

    if(sx!=1e16){
        dfs(x*sx,y*sx,z*sx,s);
        dfs(x*sx,y*sx,z,s);
        dfs(x*sx,y,z,s);
        dfs(x*sx,y,z*sx,s);
    }

    if(sy!=1e16){
        dfs(x*sy,y*sy,z*sy,s);
        dfs(x*sy,y*sy,z,s);
        dfs(x,y*sy,z,s);
        dfs(x,y*sy,z*sy,s);
    }

    if(sz!=1e16){
        dfs(x,y*sz,z*sz,s);
        dfs(x,y,z*sz,s);
        dfs(x*sz,y*sz,z*sz,s);
        dfs(x*sz,y,z*sz,s);
    }
}
signed main(){
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
    read(T);
    while(T--){
        ans=3;
        read(p),read(q),read(r);
        read(a),read(b),read(c);
        dfs(p,q,r,0);
//        if(p==a)ans--;
//        if(q==b)ans--;
//        if(r==c)ans--;
//        if(p&&a!=p&&a%p==0&&(a/p)*q==b&&(a/p)*r==c)ans-=2,p=a,q=b,r=c;
//        else if(p&&a!=p&&a%p==0&&(a/p)*r==c)ans--,p=a,r=c;
//        else if(p&&a!=p&&a%p==0&&(a/p)*q==b)ans--,p=a,q=b;
//        else if(q&&b!=q&&b%q==0&&(b/q)*r==c)ans--,q=b,r=c;
//        if(a!=p&&q-(p-a)==b&&r-(p-a)==c)ans-=2,p=a,q=b,r=c;
//        else if(a!=p&&r-(p-a)==c)ans--,p=a,r=c;
//        else if(a!=p&&q-(p-a)==b)ans--,p=a,q=b;
//        else if(b!=q&&r-(q-b)==c)ans--,q=b,r=c;
//        if(a!=p&&b!=q&&c!=r){
//            int x=p-a,y=q-b,z=r-c;
//            if(x+y==z)ans--;
//            else if(x+z==y)ans--;
//            else if(y+z==x)ans--;
//        }
        printf("%lld\n",ans);
//        cout<<p<<" "<<q<<" "<<r<<endl;
    }
    return 0;
}
/*
2
3 5 7
6 5 10
8 6 3
9 7 8

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
