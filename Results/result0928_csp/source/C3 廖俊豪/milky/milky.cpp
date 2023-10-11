#include<bits/stdc++.h>
using namespace std;
const long long int mod=4294967296;
int n,q,tmp;
char s[1000005];
int a[1000005];
long long int f[1000005][5][5];
inline long long int Mod(long long int x){
    if(x>=mod)x-=mod;
    return x;
}
inline long long int get(int l,int r,int L,int R){
    if(L==R)return Mod(f[r][L][L]+(mod-f[l-1][L][L]));
    long long int res=Mod(f[r][L][R]+(mod-f[l-1][L][R]));
    for(int i=L;i<R;i++)res=Mod(res+(mod-(f[l-1][L][i]*get(l,r,i+1,R)%mod)));
    return res;
}
signed main(){
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout); 
	scanf("%s\n",s+1);
    for(int i=1;;i++){
        if(s[i]=='m')a[i]=0;
        else if(s[i]=='i')a[i]=1;
        else if(s[i]=='l')a[i]=2;
        else if(s[i]=='k')a[i]=3;
        else if(s[i]=='y')a[i]=4;
        else break;
        n++;
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i];j++)f[i][j][a[i]]=Mod(f[i][j][a[i]]+f[i-1][j][a[i]-1]);
        for(int j=0;j<5;j++)for(int k=0;k<5;k++)f[i][j][k]=Mod(f[i][j][k]+f[i-1][j][k]);
        f[i][a[i]][a[i]]=Mod(f[i][a[i]][a[i]]+1);
    }
    scanf("%d\n",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%lld\n",get(l,r,0,4));
    }
	return 0;
}
