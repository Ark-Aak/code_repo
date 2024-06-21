#include<bits/stdc++.h>
#define int long long
namespace IO{
    template<typename T>
    void read(T &x){
        char ch=getchar();int fl=1;x=0;
        while(ch>'9'||ch<'0'){if(ch=='-')fl=-1;ch=getchar();}
        while(ch<='9'&&ch>='0'){x=x*10+ch-48;ch=getchar();}
        x*=fl;
    }
    template<typename T,typename ...Args>
    void read(T &x,Args& ...args){
        read(x);read(args...);
    }
    template <typename _Tp>
    void write(_Tp x) {
        if(x<0) x=(~x+1),putchar('-');
        if(x>9) print(x/10);
        putchar(x%10+'0');
    }
}
using namespace std;
using namespace IO;
const int N=5e5+5;
int n,fa[N],a[N][2],f[N],ans=0;;
struct Node {
    int id,x,y;
    bool operator < (const Node &b)const{
        if(x*b.y==b.x*y) {
            if(x==b.x) {
                if(y==b.y) return id<b.id;
                else return y<b.y;
            }else return x<b.x;
        }
        return x*b.y<y*b.x;
    }
};
priority_queue<Node> Q,Q1;
map<Node,int> ma;
int find(int x) {
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
signed main() {
#ifndef KAxdd
#ifndef ONLINE_JUDGE
    /* freopen("special.in","r",stdin); */
    /* freopen("special.out","w",stdout); */
#endif
#endif
    read(n);
    for(int i=2;i<=n;i++) read(fa[i]);
    for(int i=1;i<=n;i++) {
        int x; read(x);
        a[i][x]++; f[i]=i;
        if(i>1) Q.push({i,a[i][0],a[i][1]});
    }
    for(int i=1;i<n;i++) {
        while(!Q.empty() && ma[Q.top()]) Q.pop();
        int fx=Q.top().id,fy=find(fa[fx]); Q.pop();
        ma[{fy,a[fy][0],a[fy][1]}] = 1;
        if(fy>1) {
            Q.push({fy,a[fx][0]+a[fy][0],a[fx][1]+a[fy][1]});
        }
        ans+=a[fy][1]*a[fx][0];
        a[fy][0]+=a[fx][0];
        a[fy][1]+=a[fx][1];
        f[fx]=fy;
    }
    printf("%lld\n",ans);
    return 0;
}
/*
15
1 2 1 3 1 5 7 2 6 8 9 1 2 5
1 0 1 0 0 1 0 0 0 0 1 0 0 1 0

*/
