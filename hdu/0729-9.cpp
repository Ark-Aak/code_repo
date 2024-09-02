#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Maxn=1e6+7;
int T;
int n,m;
string s,t[Maxn];
int tag[Maxn],len[Maxn];

int nxt[Maxn][40],now[40],knx[50],mp[50];


int g[Maxn][10];

int mth[]={31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        cin>>s;
        for(int i=0;i<27;i++) now[i]=0;
        for(int i=0;i<10;i++) knx[i]=0;
        for(int i=0;i<m;i++) tag[i]=0;
        for(int i=0;i<m;i++) for(int j=0;j<26;j++) nxt[i][j]=0;
        for(int i=0;i<m;i++) for(int j=0;j<10;j++) g[i][j]=0;

        for(int i=m-1;~i;i--){
            if(s[i]>='0' and s[i]<='9') continue;
            for(int j=0;j<26;j++) nxt[i][j]=now[j];
            now[s[i]-'a']=i;
        }

        for(int i=m-1;~i;i--){
            for(int j=0;j<10;j++) g[i][j]=knx[j];
            if(s[i]>='0' and s[i]<='9') ;
            else continue;
            knx[s[i]-'0']=i;
        }
        for(int i=1;i<=n;i++){
            cin>>t[i];
            len[i]=t[i].size();
            int l=now[t[i][0]-'a'],p=0,kk=len[i]-1;
            while(kk--) l=nxt[l][t[i][++p]-'a'];
            tag[l]++;
        }

        ll ans=0;

        for(int i=m-1;~i;i--){
            if(!tag[i]) continue;
            int ret=0;
            for(int j=0;j<12;j++){
                for(int k=1;k<=mth[j];k++){
                    int i1=(j+1)/10,i2=(j+1)%10,i3=k/10,i4=k%10;
                    if(g[i][i1] and g[g[i][i1]][i2] and g[g[g[i][i1]][i2]][i3] and g[g[g[g[i][i1]][i2]][i3]][i4]){
                        ret++;
                    }
                }
            }
            ans+=ret*tag[i];
        }

        printf("%lld\n",ans);
    }
    return 0;
}
