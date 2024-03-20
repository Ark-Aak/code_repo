#include<iostream>
#include<algorithm>
#include<set>
const int sz=5e5+10;
int a[sz];
std::set<int>s;
int main(){
    freopen("interval.in","r",stdin);
    freopen("interval.out","w",stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin>>n;
    for(int i=1;i<=n;++i)std::cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        int l=i,r=i;
        while(r<=n&&a[r]/a[i]*a[i]==a[r])++r;
        while(l>=1&&a[l]/a[i]*a[i]==a[l])--l;
        ++l,--r;
        if(r-l>ans)ans=r-l,s.clear();
        if(r-l==ans)s.insert(l);
    }
    std::cout<<s.size()<<" "<<ans<<"\n";
    for(int p:s)std::cout<<p<<" ";
    return 0;
}