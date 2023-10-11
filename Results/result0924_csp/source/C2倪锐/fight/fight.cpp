#import<bits/stdc++.h>
int n;
using namespace std;
int main()
{
    freopen("fight.in","r",stdin);
    freopen("fight.out","w",stdout);
    std::cin>>n;
    for(int i=n-1;i>=n/2;--i)
    	for(int j=1;j<3;++j)std::cout<<fixed<<setprecision(5000)<<1.0/powl(2,i)<<endl;
}
