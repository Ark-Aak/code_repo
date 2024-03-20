#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

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

const int N = 200005;
int a[N],ans[N];
int n,m;

class inquery{
    public:
        int l,r,block,id;
        bool operator < (const inquery &tmp)const{
            if(block!=tmp.block)
                return l<tmp.l;
            if(block&1)
                return r>tmp.r;
            return r<tmp.r;
        }
};

struct{int x,c,bc;} mdf[N];
vector<inquery> qus;

vector<int> ha;
int h(int x){return lower_bound(ha.begin(),ha.end(),x)-ha.begin()+1;}

namespace list{
    int nxt[3*N],pre[3*N];
    void insert(int x,int y){
        pre[nxt[x]] = y;
        nxt[y] = nxt[x];
        nxt[x] = y;
        pre[y] = x;
    }
    void erase(int x){
        nxt[pre[x]] = nxt[x];
        pre[nxt[x]] = pre[x];
    }
}

namespace count{
    bool c[N];
    int ans;
    
    void init(){
        for(int k=1;k<=n;k++)
            c[k] = true;
        ans = 1;
    }

    void add(int x){
        c[x] = true;
        if(c[x-1]&&c[x+1])
            ans--;
        else if(!c[x-1]&&!c[x+1])
            ans++;
    }

    void del(int x){
        c[x] = false;
        if(c[x-1]&&c[x+1])
            ans++;
        else if(!c[x-1]&&!c[x+1])
            ans--;
    }
}

int main(){
    n = in,m = in;
    int block = ceil(n/sqrt(m)*4),pos = 0;
    for(int k=1;k<=n;k++)
        ha.push_back(a[k] = in);
    for(int k=1;k<=m;k++){
        int op = in;
        if(op==1){
            int x = in;
            ha.push_back(x);
            qus.push_back({k,x,k/block,++pos});
        }
        else{
            mdf[k].x = in,mdf[k].c = in;
            ha.push_back(mdf[k].c);
        }
    }
    sort(ha.begin(),ha.end());
    ha.erase(unique(ha.begin(),ha.end()),ha.end());
    for(int k=1;k<=n;k++){
        a[k] = h(a[k]);
        list::insert(a[k]+N,k);
    }
    for(int k=0;k<(int)qus.size();k++)
        qus[k].r = h(qus[k].r);
    for(int k=1;k<=m;k++)
        if(mdf[k].x){
            mdf[k].c = h(mdf[k].c);
            mdf[k].bc = a[mdf[k].x];
            a[mdf[k].x] = mdf[k].c;
        }
    sort(qus.begin(),qus.end());
    int L = 1/*时间*/,R = 1/*侵蚀力*/;
    count::init();
    for(auto [l,r,tmp,id]:qus){
        while(L<l){
            if(mdf[L].bc>=R)
                count::del(mdf[L].x);
            list::erase(mdf[L].x);
            list::insert(mdf[L].c+N,mdf[L].x);
            if(mdf[L].c>=R)
                count::add(mdf[L].x);
            L++;
        }
        while(L>l){
            L--;
            if(mdf[L].c>=R)
                count::del(mdf[L].x);
            list::erase(mdf[L].x);
            list::insert(mdf[L].bc+N,mdf[L].x);
            if(mdf[L].bc>=R)
                count::add(mdf[L].x);
        }
        while(R<r){
            for(int k=list::nxt[R+N];k;k=list::nxt[k])
                count::del(k);
            R++;
        }
        while(R>r){
            R--;
            for(int k=list::nxt[R+N];k;k=list::nxt[k])
                count::add(k);
        }
		cout << L << " " << R << " " << id << endl;
        ans[id] = count::ans;
    }
    for(int k=1;k<=pos;k++)
        out(ans[k],'\n');
    return 0;
}
