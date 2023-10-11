#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
const ll mod=1e9+7;
string s;
ll m,n,lct[10];
vector<ll>v[10];
int main(){
    freopen("milky.in","r",stdin);
    freopen("milky.out","w",stdout);
    cin>>s>>m;
    n=s.size();
    s=" "+s;
    for(int i=1;i<=m;i++){
        ll l,r;
        cin>>l>>r;
        if(r-l+1<5)cout<<"0\n";
        else if(r-l+1==5&&s[l]=='m'&&s[l+1]=='i'&&s[l+2]=='l'&&s[l+3]=='k'&&s[l+4]=='y')cout<<"1\n";
        else if(r-l+1==5)cout<<"0\n";
        else cout<<"1\n";
    }
    return 0;
}
