#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
namespace MYINPUT{
    const int S=(1<<20)+5;char B[S],*H=B,*T=B;
    inline char gc(){if(H==T) T=(H=B)+fread(B,1,S,stdin);return H==T?EOF:*H++;}
    inline ll fr(){ll x=0;bool fh=0;char ch=gc();while(ch<'0'||ch>'9'){if(ch=='-') fh=1;ch=gc();}while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc();}return fh?-x:x;}
}using MYINPUT::fr;
int check(ll a,ll b,ll c,ll x,ll y,ll z){
        if(a==x&&b==y&&c==z)return 0;//三个相同
        if(a==x&&b==y)return 1;//两个相同
        if(a==x&&c==z)return 1;//两个相同
        if(c==z&&b==y)return 1;//两个相同
        if(a==x){//一个相同
            if(c-z==b-y||(c*y==b*z&&abs(c)<abs(z)))return 1;
            else return 2;
        }
        if(b==y){//一个相同
            if(a-x==c-z||(a*z==c*x&&abs(a)<abs(x)))return 1;
            else return 2;
        }
        if(c==z){//一个相同
            if(a-x==b-y||(a*y==b*x&&abs(b)<abs(y)))return 1;
            else return 2;
        }
        if(a*y*z==b*x*z&&b*x*z==c*x*y&&abs(a)<abs(x)){//不同 1 次
            return 1;
        }
        if(a-x==b-y&&a-x==c-z){//不同 1 次
            return 1;
        }
        return 4;
}
void solve(int &ans,ll a,ll b,ll c,ll x,ll y,ll z){
    ll t=x-a;
    ans=min(ans,min(check(a+t,b+t,c+t,x,y,z)+(t!=0),min(check(a+t,b+t,c,x,y,z)+(t!=0),check(a+t,b,c+t,x,y,z)+(t!=0))));
    for(int i=1;i*abs(a)<=abs(x);i++){
        ll t=x-i*a;
        ans=min(ans,min(check(a*i+t,b*i+t,c*i+t,x,y,z)+(t!=0)+(i!=1),min(check(a*i+t,b*i+t,c,x,y,z)+(t!=0)+(i!=1),check(a*i+t,b,c*i+t,x,y,z)+(t!=0)+(i!=1))));
    }
}
int main(){
    freopen("triple.in","r",stdin);
    freopen("triple.out","w",stdout);
    ll T;
    cin>>T;
    while(T--){
        ll a,b,c,x,y,z;
        cin>>a>>b>>c>>x>>y>>z;
        int q=check(a,b,c,x,y,z);
        if(q!=4){
            cout<<q<<endl;
            continue;
        }
        int ans=3;
        solve(ans,a,b,c,x,y,z);//a->x
        solve(ans,b,a,c,y,x,z);//b->y
        solve(ans,c,a,b,z,x,y);//c->z;
        cout<<ans<<"\n";
    }
    return 0;
}
