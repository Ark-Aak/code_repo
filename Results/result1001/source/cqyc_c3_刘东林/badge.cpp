#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

namespace IOR{
    char ib[1<<22],ob[1<<20],*p1=ib,*p2=ib,*po=ob;
    void flush(){fwrite(ob,sizeof(char),po-ob,stdout);po=ob;}struct OC{~OC(){flush();};}Oc;
    char gc(){return p1==p2&&(p2=(p1=ib)+fread(ib,sizeof(char),sizeof(ib),stdin),p1==p2)?EOF:*p1++;}
    void pc(const char c){*po++=c;if(po-ob==sizeof(ob))flush();}
    void pt(const char *s){while(*s!='\0'){pc(*s);s++;}pc('\n');}
}
#define getchar IOR::gc
#define putchar IOR::pc
#define puts IOR::pt

namespace fastio{
    struct{template<typename T>operator T(){
        T x=0;char f=0,c=getchar();
        while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
        while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
        return f?-x:x;
    }}in;int stk[40],tp;
    template<typename T>void out(T x,char c=0){
        if(x<0)putchar('-'),x=-x;
        do stk[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(stk[tp--]^48);
        if(c)putchar(c);
    }
}using fastio::in;using fastio::out;

const int N = 500005;
pair<int,int> a[N];
vector<int> l[N];
int res[N];
bool c[N];
int n,q;

vector<pair<int,int>> ha;
int h(pair<int,int> x){return lower_bound(ha.begin(),ha.end(),x)-ha.begin()+1;}

int main(){
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    n = in,q = in;
    for(int k=1;k<=n;k++){
        a[k].first = in,a[k].second = in;
        ha.push_back(a[k]);
    }
    sort(ha.begin(),ha.end());
    ha.erase(unique(ha.begin(),ha.end()),ha.end());
    for(int k=0;k<(int)ha.size();k++)
        for(int j=ha[k].first;j<=ha[k].second;j++)
            l[j].push_back(k+1);
    for(int k=1;k<=n;k++)
        res[h(a[k])]++;
    vector<int> cl;
    while(q--){
        for(int x:cl)
            c[x] = false;
        cl.clear();
        int m = in,ans = 0;
        while(m--){
            int x = in;
            for(int y:l[x]){
                if(!c[y]){
                    cl.push_back(y);
                    ans += res[y];
                    c[y] = true;
                }
                else{
                    ans -= res[y];
                    c[y] = false;
                }
            }
        }
        out(ans,'\n');
    }
    return 0;
}