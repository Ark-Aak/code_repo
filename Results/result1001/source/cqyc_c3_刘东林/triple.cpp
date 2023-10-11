#include <iostream>
#include <vector>
#include <array>
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

int main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    int t = in;
    int cnt = 0;
    while(t--){
        array<int,3> s,t;
        for(int k=0;k<3;k++)
            s[k] = in;
        for(int k=0;k<3;k++)
            t[k] = in;
        auto same = [](vector<int> a){
            for(int k=1;k<(int)a.size();k++)
                if(a[k]!=a[k-1])
                    return false;
            return true;
        };
        auto checkadd = [&](auto s,auto t){
            vector<int> op;
            for(int k=0;k<3;k++){
                if(s[k]==t[k])
                    continue;
                op.push_back(t[k]-s[k]);
            }
            return same(op);
        };
        auto checkmul = [&](auto s,auto t){
            vector<int> op;
            for(int k=0;k<3;k++){
                if(s[k]==t[k])
                    continue;
                if(!s[k]||t[k]!=(t[k]/s[k])*s[k])
                    return false;
                op.push_back(t[k]/s[k]);
            }
            return same(op);
        };
        auto check1 = [&]{return checkadd(s,t)||checkmul(s,t);};
        auto check2 = [&]{
            auto alladd = [&]{
                vector<int> op;
                for(int k=0;k<3;k++){
                    if(s[k]==t[k])
                        continue;
                    op.push_back(t[k]-s[k]);
                }
                sort(op.begin(),op.end());
                op.erase(unique(op.begin(),op.end()),op.end());
                return op.size()==2;
            };
            auto allmul = [&]{
                vector<int> op;
                for(int k=0;k<3;k++){
                    if(s[k]==t[k])
                        continue;
                    if(!s[k]||t[k]!=(t[k]/s[k])*s[k])
                        return false;
                    op.push_back(t[k]/s[k]);
                }
                sort(op.begin(),op.end());
                op.erase(unique(op.begin(),op.end()),op.end());
                return op.size()==2;
            };
            auto addmul = [&](){
                if(t[1]!=t[2]){
                    int c = (t[2]*s[2]-t[1]*s[1])/(t[1]-t[2]);
                    auto S = s;
                    for(int k=0;k<3;k++)
                        S[k] += c;
                    if(checkmul(S,t)||checkadd(S,t))
                        return true;
                }
                for(int k=0;k<3;k++){
                    int c = t[k]-s[k];
                    auto S = s;
                    for(int j=1;j<8;j++){
                        for(int i=0;i<3;i++)
                            if((j>>i)&1)
                                S[i] += c;
                        if(checkmul(S,t)||checkadd(S,t))
                            return true;
                    }
                }
                return false;
            };
            auto muladd = [&](){
                if(t[1]!=t[2]){
                    int p = (s[1]-s[2])/(t[1]-t[2]);
                    auto S = s;
                    for(int k=0;k<3;k++)
                        S[k] *= p;
                    if(checkmul(S,t)||checkadd(S,t))
                        return true;
                }
                for(int k=0;k<3;k++){
                    if(s[k]==t[k]||!s[k]||t[k]!=(t[k]/s[k])*s[k])
                        continue;
                    int p = t[k]/s[k];
                    auto S = s;
                    for(int j=1;j<8;j++){
                        for(int i=0;i<3;i++)
                            if((j>>i)&1)
                                S[i] *= p;
                        if(checkmul(S,t)||checkadd(S,t))
                            return true;
                    }
                }
                return false;
            };
            return alladd()||allmul()||addmul()||muladd();
        };
        if(check1())
            puts("1");
        else if(check2())
            puts("2");
        else
            puts("3");
    }
    return 0;
}