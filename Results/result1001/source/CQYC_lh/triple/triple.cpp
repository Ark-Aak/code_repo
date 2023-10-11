#include<bits/stdc++.h>
using namespace std;
long long T;
long long read(){
    long long x=0;
    bool f=0;
    char ch=getchar();
    while(!isdigit(ch))f=((ch=='-')?1:0),ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return (f)?-x:x;
}
bool ck(long long a,long long b){return (b!=0)?(abs(a)%abs(b)==0):0;}
bool check1(long long a,long long b,long long c){
    return (a+b==c)||(a+c==b)||(b+c==a);
}
bool check2(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(c,r)&&(q+a-p)*(c/r)==b)return 1;
    if(ck(c,r)&&(p+b-q)*(c/r)==a)return 1;
    if(ck(b,q)&&(r+a-p)*(b/q)==c)return 1;
    if(ck(b,q)&&(p+c-r)*(b/q)==a)return 1;
    if(ck(a,p)&&(q+c-r)*(a/p)==b)return 1;
    if(ck(a,p)&&(r+b-q)*(a/p)==c)return 1;
    return 0;
}
bool check3(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(c,r)&&(q*(c/r)+a-p)==b)return 1;
    if(ck(c,r)&&(p*(c/r)+b-q)==a)return 1;
    if(ck(b,q)&&(r*(b/q)+a-p)==c)return 1;
    if(ck(b,q)&&(p*(b/q)+c-r)==a)return 1;
    if(ck(a,p)&&(q*(a/p)+c-r)==b)return 1;
    if(ck(a,p)&&(r*(a/p)+b-q)==c)return 1;
    return 0;
}
bool check4(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(a,p)&&ck(b,q)&&ck(c,r)&&(a/p)*(b/q)==(c/r))return 1;
    if(ck(a,p)&&ck(b,q)&&ck(c,r)&&(a/p)*(c/r)==(b/q))return 1;
    if(ck(a,p)&&ck(b,q)&&ck(c,r)&&(b/q)*(c/r)==(a/p))return 1;
    return 0;
}
bool check5(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(a,p)&&ck(b,(a/p))&&ck(c,(a/p))&&(b/(a/p)-q)==(c/(a/p)-r))return 1;
    if(ck(c,r)&&ck(b,(c/r))&&ck(a,(c/r))&&(b/(c/r)-q)==(a/(c/r)-p))return 1;
    if(ck(b,q)&&ck(a,(b/q))&&ck(c,(b/q))&&(a/(b/q)-p)==(c/(b/q)-r))return 1;
    return 0;
}
bool check6(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(a-(c-r),p)&&ck(b-(c-r),q)&&(a-(c-r))/p==(b-(c-r))/q)return 1;
    if(ck(a-(b-q),p)&&ck(c-(b-q),r)&&(a-(b-q))/p==(c-(b-q))/r)return 1;
    if(ck(c-(a-p),r)&&ck(b-(a-p),q)&&(c-(a-p))/r==(b-(a-p))/q)return 1;
    return 0;
}
bool check7(long long a,long long p,long long b,long long q,long long c,long long r){
    long long x,y;
    if(p-q!=0&&ck(a-b,p-q)){
        y=(a-b)/(p-q);
        if(ck(a,y)){
            x=a/y-p;
            return (q+x)*y==b&&(r+x)*y==c;
        }
    }
    if(p-r!=0&&ck(a-c,p-r)){
        y=(a-c)/(p-r);
        if(ck(a,y)){
            x=a/y-p;
            return (q+x)*y==b&&(r+x)*y==c;
        }
    }
    if(q-r!=0&&ck(b-c,q-r)){
        y=(b-c)/(q-r);
        if(ck(b,y)){
            x=b/y-q;
            return (p+x)*y==a&&(r+x)*y==c;
        }
    }
    return 0;
}
bool check8(long long a,long long p,long long b,long long q,long long c,long long r){
    long long x,y;
    if(p-q!=0&&ck(a-b,p-q)){
        x=(a-b)/(p-q);
        y=a-p*x;
        return q*x+y==b&&r*x+y==c;
    }
    if(p-r!=0&&ck(a-c,p-r)){
        x=(a-c)/(p-r);
        y=a-p*x;
        return q*x+y==b&&r*x+y==c;
    }
    if(q-r!=0&&ck(b-c,q-r)){
        x=(b-c)/(q-r);
        y=b-q*x;
        return p*x+y==a&&r*x+y==c;
    }
    return 0;
}
bool check9(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(a,p+c-r)&&ck(b,q+c-r)&&a/(p+c-r)==b/(q+c-r))return 1;
    if(ck(c,r+a-p)&&ck(b,q+a-p)&&c/(r+a-p)==b/(q+a-p))return 1;
    if(ck(a,p+b-q)&&ck(c,r+b-q)&&a/(p+b-q)==c/(r+b-q))return 1;
    return 0;
}
bool check10(long long a,long long p,long long b,long long q,long long c,long long r){
    if(ck(c,r)&&a-p*(c/r)==b-q*(c/r))return 1;
    if(ck(b,q)&&a-p*(b/q)==c-r*(b/q))return 1;
    if(ck(a,p)&&b-q*(a/p)==c-r*(a/p))return 1;
    return 0;
}
int main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    long long p,q,r,a,b,c;
    T=read();
    int num=0;
    while(T--){
        num++;
        p=read(),q=read(),r=read(),a=read(),b=read(),c=read();
        // if(num==13)printf("%lld %lld %lld\n%lld %lld %lld\n",p,q,r,a,b,c);
        if(a==p&b==q&&c==r){printf("0\n");continue;}
        if(a==p){
            if(c!=r)swap(a,c),swap(p,r);
            else swap(a,b),swap(p,q);
        }
        if(b==q)swap(b,c),swap(q,r);
        if(b==q&&c==r){printf("1\n");continue;}
        if(a-p==b-q&&c==r){printf("1\n");continue;}
        if(ck(a,p)&&ck(b,q)&&a/p==b/q&&c==r){printf("1\n");continue;}
        if(a-p==b-q&&b-q==c-r){printf("1\n");continue;}
        if(ck(a,p)&&ck(b,q)&&ck(c,r)&&a/p==b/q&&b/q==c/r){printf("1\n");continue;}
        if(c==r){printf("2\n");continue;}
        //a-p!=b-q!=c-r
        // if(!T)printf("%lld %lld %lld %lld %lld %lld\n",b,q,c,r,b-q,c-r);
        if(a-p==b-q||b-q==c-r||a-p==c-r){printf("2\n");continue;}
        if((ck(a,p)&&ck(b,q)&&a/p==b/q)||(ck(a,p)&&ck(c,r)&&a/p==c/r)||(ck(b,q)&&ck(c,r)&&b/q==c/r)){printf("2\n");continue;}
        if(check1(a-p,b-q,c-r)){printf("2\n");continue;}
        if(check2(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check3(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check4(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check5(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check6(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check7(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check8(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check9(a,p,b,q,c,r)){printf("2\n");continue;}
        if(check10(a,p,b,q,c,r)){printf("2\n");continue;}
        printf("3\n");
        // if(num==13)printf("%lld %lld %lld\n%lld %lld %lld\n",p,q,r,a,b,c);
    }
    return 0;
}