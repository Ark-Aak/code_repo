#include <iostream>
#include <cstdio>
#define ans1 {printf("1\n");continue;}
#define ans2 {printf("2\n");continue;}
#define ans3 {printf("3\n");continue;}
int T,ans;
inline int abs(int x){return x>0?x:-x;}
int check(int a,int b,int c,int d,int e,int f) {
    return abs(a)<=10&&abs(b)<=10&&abs(c)<=10&&abs(d)<=10&&abs(e)<=10&&abs(f)<=10;
}
void dfs(int a,int b,int c,int fa,int fb,int fc,int step) {
    if(step>=ans) return;
    if(a==fa&&b==fb&&c==fc) {
        ans=step;
        return;
    }
    for(int i=-10;i<=10;i++) {
        dfs(a+i,b,c,fa,fb,fc,step+1);
        dfs(a,b+i,c,fa,fb,fc,step+1);
        dfs(a,b,c+i,fa,fb,fc,step+1);
        dfs(a+i,b+i,c,fa,fb,fc,step+1);
        dfs(a+i,b,c+i,fa,fb,fc,step+1);
        dfs(a,b+i,c+i,fa,fb,fc,step+1);
        dfs(a+i,b+i,c+i,fa,fb,fc,step+1);
    }
    for(int i=-10;i<=10;i++) {
        dfs(a*i,b,c,fa,fb,fc,step+1);
        dfs(a,b*i,c,fa,fb,fc,step+1);
        dfs(a,b,c*i,fa,fb,fc,step+1);
        dfs(a*i,b*i,c,fa,fb,fc,step+1);
        dfs(a*i,b,c*i,fa,fb,fc,step+1);
        dfs(a,b*i,c*i,fa,fb,fc,step+1);
        dfs(a*i,b*i,c*i,fa,fb,fc,step+1);
    }
}
int main() {
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    for(scanf("%d",&T);T--;) {
        int a,b,c;
        int fa,fb,fc;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&fa,&fb,&fc);

        if(a==fa) {
            if(b-fb==c-fc) ans1;
            if(c!=0&&b!=0&&fc%c==0&&fb%b==0 && fc/c==fb/b) ans1;
            ans2;
        }
        
        if(check(a,b,c,fa,fb,fc)) {
        ans=3;
            if(a-fa==b-fb&&a-fa==c-fc) ans=1;
            if(a!=0&&fa%a==0&&b!=0&&fb%b==0&&c!=0&&fc%c==0 &&
            a!=0&&b!=0&&c!=0&&fa/a==fb/b&&fa/a==fc/c) ans=1;
            if(a-fa==b-fb&&c==fc||a-fa==c-fc&&b==fb||b-fb==c-fc&&a==fa) ans=1;

            if(a!=0&&b!=0&&fa%a==0&&fb%b==0 && fa/a==fb/b && c==fc) ans=1;
            if(a!=0&&c!=0&&fa%a==0&&fc%c==0 && fa/a==fc/c && b==fb) ans=1;
            if(c!=0&&b!=0&&fc%c==0&&fb%b==0 && fc/c==fb/b && a==fa) ans=1;

            if(a-fa==b-fb||a-fa==c-fc||b-fb==c-fc) ans=2;

            if(a!=0&&b!=0&&fa%a==0&&fb%b==0 && fa/a==fb/b) ans=2;
            if(a!=0&&c!=0&&fa%a==0&&fc%c==0 && fa/a==fc/c) ans=2;
            if(c!=0&&b!=0&&fc%c==0&&fb%b==0 && fc/c==fb/b) ans=2;
            dfs(a,b,c,fa,fb,fc,0);
            printf("%d\n",ans);
            continue;
        }

        else {
            if(a-fa==b-fb&&a-fa==c-fc) ans1;
            if(a!=0&&fa%a==0&&b!=0&&fb%b==0&&c!=0&&fc%c==0 &&
            a!=0&&b!=0&&c!=0&&fa/a==fb/b&&fa/a==fc/c) ans1;
            if(a-fa==b-fb&&c==fc||a-fa==c-fc&&b==fb||b-fb==c-fc&&a==fa) ans1;

            if(a!=0&&b!=0&&fa%a==0&&fb%b==0 && fa/a==fb/b && c==fc) ans1;
            if(a!=0&&c!=0&&fa%a==0&&fc%c==0 && fa/a==fc/c && b==fb) ans1;
            if(c!=0&&b!=0&&fc%c==0&&fb%b==0 && fc/c==fb/b && a==fa) ans1;

            if(a-fa==b-fb||a-fa==c-fc||b-fb==c-fc) ans2;

            if(a!=0&&b!=0&&fa%a==0&&fb%b==0 && fa/a==fb/b) ans2;
            if(a!=0&&c!=0&&fa%a==0&&fc%c==0 && fa/a==fc/c) ans2;
            if(c!=0&&b!=0&&fc%c==0&&fb%b==0 && fc/c==fb/b) ans2;

            ans3;
        }
    }
    return 0;
}
