#include <iostream>
#include <cstdio>
#include <vector>
#define int long long
const int N=1000050;
const int MOD=1000000007;
struct node {
    int cnt,times;
}a[N],b[N];
int n,m,k,sum;
int iA[N][2],cntA;
int iB[N][2],cntB;
inline int power(int x,int y) {
    int res=1;
    while(y) {
        if(y&1) res=res*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return res%MOD;
}
inline int number(int x,int y){return (x-1)*m%MOD+y;}
signed main() {
    freopen("wisdom.in","r",stdin);
    freopen("wisdom.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=n;i++) a[i]=(node){((i-1)*m%MOD+1+i*m%MOD)%MOD*m%MOD*power(2,MOD-2)%MOD,1};
    for(int i=1;i<=m;i++) b[i]=(node){(i+i+(n-1)*m%MOD)*n%MOD*power(2,MOD-2)%MOD,1};
    for(int i=1;i<=n;i++) sum=(sum+a[i].cnt)%MOD;
    for(int i=1;i<=k;i++) {
        char op[114];
        int id,add;
        scanf("%s%lld%lld",op,&id,&add);
        if(op[0]=='R') {
            bool flag=false;
            for(int j=1;j<=cntA;j++) {
                if(iA[j][0]==id) {
                    flag=true;
                    iA[j][1]=iA[j][1]*add%MOD;
                    break;
                }
            }
            if(!flag) {
                iA[++cntA][0]=id;
                iA[cntA][1]=add;
            }
        }
        if(op[0]=='S') {
            bool flag=false;
            for(int j=1;j<=cntB;j++) {
                if(iB[j][0]==id) {
                    flag=true;
                    iB[j][1]=iB[j][1]*add%MOD;
                    break;
                }
            }
            if(!flag) {
                iB[++cntB][0]=id;
                iB[cntB][1]=add;
            }
        }
    }
    for(int i=1;i<=cntA;i++) {
        int id=iA[i][0],add=iA[i][1];
        sum=(sum+(add-1)*a[id].cnt%MOD*a[id].times%MOD)%MOD;
        a[id].times=a[id].times*add%MOD;
    }
    for(int i=1;i<=cntB;i++) {
        int id=iB[i][0],add=iB[i][1];
        sum=(sum+(add-1)*b[id].cnt%MOD*b[id].times%MOD)%MOD;
        b[id].times=b[id].times*add%MOD;
    }
    for(int i=1;i<=cntA;i++) {
        int id=iA[i][0],add=iA[i][1];
        for(int j=1;j<=cntB;j++) {
            int tid=iB[j][0],tadd=iB[j][1];
            sum=(sum+number(id,tid)*((add*tadd-1)%MOD-((add-1)+(tadd-1)))%MOD)%MOD;
        }
    }
    printf("%d",sum%MOD);
    return 0;
}