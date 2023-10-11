#include <iostream>
#include <cstdio>
int T;
int main() {
    freopen("device.in","r",stdin);
    freopen("devive.out","w",stdout);
    for(scanf("%d",&T);T--;) {
        int k,n,length;
        scanf("%d%d",&k,&n);
        int a=k%10,b=k/10%10,c=k/100;
        if(a==b&&a==c) length=3;
        else if(a==b||a==c||b==c) length=2;
        else length=1;
        if(n==0) printf("1\n");
        else if(n==1) {
            if(length==1) printf("24\n");
            if(length==2) printf("7\n");
            if(length==3) printf("1\n");
        }
        else {
            if(length==1) printf("27\n");
            if(length==2) printf("8\n");
            if(length==3) printf("1\n");
        }
    }
    return 0;
}