#include <bits/stdc++.h>
#define int long long
#define i128 __int128
using namespace std;
const int mod=147744151;
int n,k;
bool check(int x){
    i128 ans=0,now=1;
    for(int i=0;i<k;i++){
        double y=1.0*now*(x-i)/(i+1);
        if(y>n) return 1;
        now=now*(x-i)/(i+1);
        ans+=now;
        if(ans>=n) return 1;
    }
    return ans>=n;
}
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout); 
    cin>>n>>k;
    int c=1,cs=0;
    for(cs=1;cs<=k;cs++){
        c<<=1;
        if(c>n) break;
    }
    if(c>n){
        cout<<cs%mod<<"\n";
        return 0;
    }
    int l=1,r=n,ans=0,mid;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid-1;
            ans=mid;
        }
        else l=mid+1;
    }
    cout<<ans%mod<<"\n";
    return 0;
}
