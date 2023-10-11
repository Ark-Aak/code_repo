#include <bits/stdc++.h>
using namespace std;
int t,k,n;
int read(){
    int s=0;
    char ch=getchar(),last=' ';
    while(ch<'0'||ch>'9')
        last=ch,ch=getchar();
    while(ch>='0'&&ch<='9')
        s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return last=='-'?-s:s;
}
signed main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    t=read();
    while(t--){
        k=read(),n=read();
        int x=k%10,y=k/10%10,z=k/100%10;
        if(x==y&&x==z){
            puts("1");
            continue;
        }
        if(x==y||x==z||y==z){
            if(n==0)
                puts("1");
            if(n==1)
                puts("7");
            if(n>1)
                puts("8");
            continue;
        }
        if(n==0)
            puts("1");
        if(n==1)
            puts("24");
        if(n>1)
            puts("27");
    }
    return 0;
}