#include <iostream>
#include <cstdio>
#include <cstring>
const int N=1145141;
int dp1[N][6],dp2[N][6],sum[N][6],T;
char str[N];
unsigned int g(int l,int r,int sign) {
    return sum[r][sign]-sum[l-1][sign];
}
int main() {
    freopen("milky.in","r",stdin);
    freopen("milky.out","w",stdout);
    scanf("%s",str+1);
    int n=strlen(str+1);
    for(int i=1;i<=n;i++) {
        sum[i][1]=sum[i-1][1];
        sum[i][2]=sum[i-1][2];
        sum[i][3]=sum[i-1][3];
        sum[i][4]=sum[i-1][4];
        sum[i][5]=sum[i-1][5];
        if(str[i]=='m') ++sum[i][1];
        if(str[i]=='i') ++sum[i][2];
        if(str[i]=='l') ++sum[i][3];
        if(str[i]=='k') ++sum[i][4];
        if(str[i]=='y') ++sum[i][5];
    }
    for(int i=1;i<=n;i++) {
        dp1[i][1]=dp1[i-1][1];
        dp1[i][2]=dp1[i-1][2];
        dp1[i][3]=dp1[i-1][3];
        dp1[i][4]=dp1[i-1][4];
        dp1[i][5]=dp1[i-1][5];
        if(str[i]=='m') dp1[i][1]=dp1[i-1][1]+1;
        if(str[i]=='i') dp1[i][2]=dp1[i-1][2]+dp1[i-1][1];
        if(str[i]=='l') dp1[i][3]=dp1[i-1][3]+dp1[i-1][2];
        if(str[i]=='k') dp1[i][4]=dp1[i-1][4]+dp1[i-1][3];
        if(str[i]=='y') dp1[i][5]=dp1[i-1][5]+dp1[i-1][4];
    }
    for(int i=n;i>=1;i--) {
        dp2[i][1]=dp2[i+1][1];
        dp2[i][2]=dp2[i+1][2];
        dp2[i][3]=dp2[i+1][3];
        dp2[i][4]=dp2[i+1][4];
        dp2[i][5]=dp2[i+1][5];
        if(str[i]=='y') dp2[i][5]=dp2[i+1][5]+1;
        if(str[i]=='k') dp2[i][4]=dp2[i+1][4]+dp2[i+1][5];
        if(str[i]=='l') dp2[i][3]=dp2[i+1][3]+dp2[i+1][4];
        if(str[i]=='i') dp2[i][2]=dp2[i+1][2]+dp2[i+1][3];
        if(str[i]=='m') dp2[i][1]=dp2[i+1][1]+dp2[i+1][2];
    }
    for(scanf("%u",&T);T--;) {
        int l,r;
        scanf("%u%u",&l,&r);
        printf("%u\n",
             dp1[r][5]+dp2[l][1]-dp1[n][5]
            
        );
    }
    return 0;
}
