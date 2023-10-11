#include <bits/stdc++.h>
using namespace std;
int t;
struct node{
    int a,b,c,d,e;
}x[5];
int read(){
    int s=0;
    char ch=getchar(),last=' ';
    while(ch<'0'||ch>'9')
        last=ch,ch=getchar();
    while(ch>='0'&&ch<='9')
        s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
    return last=='-'?-s:s;
}
int cmp(node x,node y){
    return abs(x.c)<abs(y.c);
}
int check(){
    if(x[1].c==x[2].c||x[1].c==x[3].c||x[2].c==x[3].c)
        return 1;
    if(x[1].c+x[2].c==x[3].c||x[1].c+x[3].c==x[2].c||x[2].c+x[3].c==x[1].c)
        return 1;
    if((x[1].a*x[1].d==x[1].b&&x[2].a*x[1].d==x[2].b)||(x[1].a*x[1].d==x[1].b&&x[3].a*x[1].d==x[3].b)||(x[2].a*x[2].d==x[2].b&&x[3].a*x[2].d==x[3].b))
        return 1;
    if(x[1].a*x[2].d*x[3].d==x[1].b&&x[2].a*x[2].d==x[2].b&&x[3].a*x[3].d==x[3].b)
        return 1;
    if(x[2].a*x[1].d*x[3].d==x[2].b&&x[1].a*x[1].d==x[2].b&&x[3].a*x[3].d==x[3].b)
        return 1;
    if(x[3].a*x[1].d*x[2].d==x[3].b&&x[1].a*x[1].d==x[1].b&&x[2].a*x[2].d==x[2].b)
        return 1;
    if(((x[2].a+x[1].c)*x[3].d==x[2].b&&x[3].a*x[3].d==x[3].b)||((x[3].a+x[1].c)*x[2].d==x[3].b&&x[2].a*x[2].d==x[2].b)||((x[1].a+x[2].c)*x[3].d==x[1].b&&x[3].a*x[3].d==x[3].b)||((x[3].a+x[2].c)*x[1].d==x[3].b&&x[1].a*x[1].d==x[1].b)||((x[1].a+x[3].c)*x[2].d==x[1].b&&x[2].a*x[2].d==x[2].b)||((x[2].a+x[3].c)*x[1].d==x[2].b&&x[1].a*x[1].d==x[1].b))
        return 1;
    int u,v;
    if(x[3].d){
        v=x[1].b/x[3].d-x[1].a;
        if((x[1].a+v)*x[3].d==x[1].b&&(x[2].a+v)*x[3].d==x[2].b&&!x[3].e)
            return 1;
    }
    if(x[2].d){
        v=x[1].b/x[2].d-x[1].a;
        if((x[1].a+v)*x[2].d==x[1].b&&(x[3].a+v)*x[2].d==x[3].b&&!x[2].e)
            return 1;
    }
    if(x[1].d){
        v=x[2].b/x[1].d-x[2].a;
        if((x[2].a+v)*x[1].d==x[2].b&&(x[3].a+v)*x[1].d==x[3].b&&!x[1].e)
            return 1;
    }
    if(x[3].c+x[1].a){
        v=x[1].b/(x[3].c+x[1].a);
        if((x[1].a+x[3].c)*v==x[1].b&&(x[2].a+x[3].c)*v==x[2].b)
            return 1;
    }
    if(x[2].c+x[1].a){
        v=x[1].b/(x[2].c+x[1].a);
        if((x[1].a+x[2].c)*v==x[1].b&&(x[3].a+x[2].c)*v==x[3].b)
            return 1;
    }
    if(x[1].c+x[2].a){
        v=x[2].b/(x[1].c+x[2].a);
        if((x[2].a+x[1].c)*v==x[2].b&&(x[3].a+x[1].c)*v==x[3].b)
            return 1;
    }
    v=(x[1].b-x[2].b)/(x[1].a-x[2].a);
    u=x[1].b/v-x[1].a;
    if((x[1].a+u)*v==x[1].b&&(x[2].a+u)*v==x[2].b&&(x[3].a+u)*v==x[3].b)
        return 1;
    if(((x[1].a*x[2].d+x[3].c)==x[1].b&&!x[2].e)||((x[1].a*x[3].d+x[2].c)==x[1].b&&!x[3].e)||((x[2].a*x[1].d+x[3].c)==x[2].b&&!x[1].e)||((x[2].a*x[3].d+x[1].c)==x[2].b&&!x[3].e)||((x[3].a*x[1].d+x[2].c)==x[3].b&&!x[1].e)||((x[3].a*x[2].d+x[1].c)==x[3].b&&!x[2].e))
        return 1;
    v=(x[1].b-x[3].c)/x[1].a;
    if((x[1].a*v+x[3].c)==x[1].b&&(x[2].a*v+x[3].c)==x[2].b)
        return 1;
    v=(x[1].b-x[2].c)/x[1].a;
    if((x[1].a*v+x[2].c)==x[1].b&&(x[3].a*v+x[2].c)==x[3].b)
        return 1;
    v=(x[2].b-x[1].c)/x[2].a;
    if((x[2].a*v+x[1].c)==x[2].b&&(x[3].a*v+x[1].c)==x[3].b)
        return 1;
    v=x[1].b-x[1].a*x[3].d;
    if((x[1].a*x[3].d+v)==x[1].b&&(x[2].a*x[3].d+v)==x[2].b&&!x[3].e)
        return 1;
    v=x[1].b-x[1].a*x[2].d;
    if((x[1].a*x[2].d+v)==x[1].b&&(x[3].a*x[2].d+v)==x[3].b&&!x[2].e)
        return 1;
    v=x[2].b-x[2].a*x[1].d;
    if((x[2].a*x[1].d+v)==x[2].b&&(x[3].a*x[1].d+v)==x[3].b&&!x[1].e)
        return 1;
    v=(x[1].b-x[2].b)/(x[1].a-x[2].a);
    u=x[1].b-x[1].a*v;
    if((x[1].a*v+u)==x[1].b&&(x[2].a*v+u)==x[2].b&&(x[3].a*v+u)==x[3].b)
        return 1;
    return 0;
}
signed main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    t=read();
    while(t--){
        for(int i=1;i<=3;i++)
            x[i].a=read();
        for(int i=1;i<=3;i++)
            x[i].b=read();
        for(int i=1;i<=3;i++){
            x[i].c=x[i].b-x[i].a;
            if(x[i].a)
                x[i].d=x[i].b/x[i].a,x[i].e=x[i].b%x[i].a;
        }
        sort(x+1,x+1+3,cmp);
        int w=1;
        while(!x[w].c&&w<=3)
            ++w;
        if(w>3){
            puts("0");
            continue;
        }
        int bj=0;
        for(int i=w+1;i<=3;i++)
            if(x[i].c!=x[i-1].c){
                bj=1;
                break;
            }
        if(!bj){
            puts("1");
            continue;
        }
        bj=0;
        for(int i=w+1;i<=3;i++)
            if(x[i].d!=x[i-1].d||x[i].a*x[i].d!=x[i].b){
                bj=1;
                break;
            }
        if(!bj&&x[w].a*x[w].d==x[w].b){
            puts("1");
            continue;
        }
        if(w>=2){
            puts("2");
            continue;
        }
        // if(check()){
        //     puts("2");
        //     continue;
        // }
        puts("3");
    }
    return 0;
}