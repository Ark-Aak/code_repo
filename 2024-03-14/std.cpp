#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll Mod=998244353;
const ll inf=1e9;
const int Maxn=1e7+7;
const int sqMaxn=1e5+7;
const int B=1e7;
int T;
int n,k,k2;

ll fac[510],Inv[510];
ll Smk[Maxn],Idk[Maxn];
ll pre[300],suf[300];
ll Sm2k[Maxn];
int sq;

ll Sk1[sqMaxn],Sk2[sqMaxn];
ll S1k[sqMaxn],S2k[sqMaxn];
inline ll Getkth(ll m){
    if(m<=sq) return Sk1[m];
    return Sk2[n/m];
}
inline ll Getkth2(ll m){
    if(m<=sq) return S1k[m];
    return S2k[n/m];
}

ll h[Maxn],Sh[Maxn];

vector<int>prm;
bitset<Maxn>isp;

inline ll upd(ll x){
    return (x%Mod+Mod)%Mod;
}
inline ll ksm(ll a,ll b,ll mod){
    ll z=1;
    while(b){
        if(b&1) z=z*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return z;
}

inline void init(int N){
    fac[0]=1;
    for(int i=1;i<=500;i++) fac[i]=fac[i-1]*i%Mod;
    Inv[500]=ksm(fac[500],Mod-2,Mod);
    for(int i=499;~i;i--) Inv[i]=Inv[i+1]*(i+1)%Mod;

    isp.set(1);isp.set(0);
    h[1]=1;Idk[1]=1;
    for(int i=2;i<=N;i++){
        if(!isp.test(i)){
            prm.emplace_back(i);
            Idk[i]=ksm(i,k,Mod);
            h[i]=upd(1-Idk[i]);
        }
        for(auto j:prm){
            const int t=i*j;if(t>N) break;
            isp.set(t);
            Idk[t]=Idk[i]*Idk[j]%Mod;
            if(!(i%j)){
                h[t]=h[i];
                break;
            }
            h[t]=h[i]*h[j]%Mod;
        }
    }
}

inline void foInt(int N){
    for(int i=1;i<=N;i++){
        Smk[i]=(Smk[i-1]+Idk[i])%Mod;
        Sm2k[i]=(Sm2k[i-1]+Idk[i]*Idk[i]%Mod)%Mod;
    }
    for(int i=1;i<=N;i++) Sh[i]=(Sh[i-1]+h[i]*Idk[i]%Mod)%Mod;
}
inline ll solvek(ll m){
    if(m<=B) return Smk[m];
    pre[0]=suf[k+3]=1;
    for(int i=1;i<=k+2;i++) pre[i]=(pre[i-1]*(m-i))%Mod;
    for(int i=k+2;i>=1;i--) suf[i]=(suf[i+1]*(m-i))%Mod;
    ll ret=0;
    for(int i=1;i<=k+2;i++){
        ll res=Smk[i]*Inv[i-1]%Mod*Inv[k+2-i]%Mod;
        if((k+2-i)&1) res=(Mod-res);
        res=res*pre[i-1]%Mod*suf[i+1]%Mod;
        ret=(ret+res)%Mod;
    }
    return ret;
}
inline ll solve2k(ll m){
    if(m<=B) return Sm2k[m];
    pre[0]=suf[k2+3]=1;
    for(int i=1;i<=k2+2;i++) pre[i]=(pre[i-1]*(m-i))%Mod;
    for(int i=k2+2;i>=1;i--) suf[i]=(suf[i+1]*(m-i))%Mod;
    ll ret=0;
    for(int i=1;i<=k2+2;i++){
        ll res=Sm2k[i]*Inv[i-1]%Mod*Inv[k2+2-i]%Mod;
        if((k2+2-i)&1) res=(Mod-res);
        res=res*pre[i-1]%Mod*suf[i+1]%Mod;
        ret=(ret+res)%Mod;
    }
    return ret;
}
/*
OK,good
*/

ll g1[Maxn],g2[Maxn];
ll GetS(int m){
    if(m<=B) return Sh[m];
    if(m<=sq&&g1[m]) return g1[m];
    if(m>sq&&g2[n/m]) return g2[n/m];
    ll res=Getkth(m);
    for(int l=2,r;l<=m;l=r+1){
        r=m/(m/l);
        res=res+Mod-(Getkth2(r)-Getkth2(l-1)+Mod)*GetS(m/l)%Mod;
        if(res>=Mod) res-=Mod;
    }
    if(m<=sq) g1[m]=res;
    else g2[n/m]=res;
    return res;
}

int main(){
    scanf("%d%d",&T,&k);
    k2=k*2;
    init(B);
    foInt(B);

    while(T--){
        scanf("%d",&n);

        sq=sqrt(n);
        for(int i=0;i<=sq+10;i++) g1[i]=g2[i]=0;

        for(int l=1,r;l<=n;l=r+1){
            r=(n/(n/l));
            int val=n/l;
            if(val<=sq) Sk1[val]=solvek(val);
            else Sk2[n/val]=solvek(val);
            if(val<=sq) S1k[val]=solve2k(val);
            else S2k[n/val]=solve2k(val);
        }

        ll ans=0;
        for(int l=1,r;l<=n;l=r+1){
            r=n/(n/l);
            ll val=Getkth(n/l);
            val=val*val%Mod;
            ans=upd(ans+upd(GetS(r)-GetS(l-1))*val%Mod);
        }
        printf("%lld\n",ans);

    }
    cerr<<(double)clock()/CLOCKS_PER_SEC;
    return 0;
}
