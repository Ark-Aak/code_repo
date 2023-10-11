#include<bits/stdc++.h>
using namespace std;
int T;
int n,k;
int read(){
    int x=0;
    bool f=0;
    char ch=getchar();
    while(!isdigit(ch))f=((ch=='-')?1:0),ch=getchar();
    while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
    return (f)?-x:x;
}
int main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    T=read();
    while(T--){
        k=read(),n=read();
        int ans=0,f=3;
        int cr[4]={k/100,k/10%10,k%10,0};
        sort(cr,cr+3);
        if(cr[0]==cr[1]){
            f=1;
            if(cr[1]==cr[2])ans=1,f=0;
            else ans=7;
        }
        else {
            if(cr[1]==cr[2])ans=7,f=1;
            else ans=24;
        }
        if(n==0)ans=1;
        if(n>1)ans+=f;
        printf("%d\n",ans);
    }
    return 0;
}