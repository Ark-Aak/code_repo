#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define endl "\n" 
using namespace std;
const ll mod=1e9+7;
ll t,k;
string s;
int main(){
    freopen("device.in","r",stdin);
    freopen("device.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>s>>k;
        if(k==0){
            cout<<1<<endl;
            continue;
        }
        s=" "+s;
        ll cnt=0;
        if(s[1]==s[2])cnt++;
        if(s[3]==s[2])cnt++;
        if(s[1]==s[3])cnt++;
        if(cnt==3)cout<<1<<endl;
        if(cnt==1||cnt==2)cout<<7+(k==1?0:1)<<endl;
        if(cnt==0)cout<<24+(k==1?0:1)*3<<endl;
    }
    return 0;
}