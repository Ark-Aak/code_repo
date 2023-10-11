# include <bits/stdc++.h>
using namespace std;
using ll=long long;
int mod,fac[10010],inv[10010],f[5010];
void add(int &x,const ll &y){x=(x+y)%mod;}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	int n;
	cin>>n>>mod;
	fac[0]=fac[1]=inv[1]=1;
	for(int i=2;i<=n;i++) fac[i]=(ll)fac[i-1]*i%mod;
	for(int i=2;i<=n;i++) inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	if(n&1) return cout<<fac[n]<<"\n",0;
	f[1]=1;
	for(int i=2;2*i<=n;i++)
	{
		for(int j=1;j<i;j++) add(f[i],(ll)f[j]*f[i-j]);
		f[i]=(ll)f[i]*inv[2*i-1]%mod;
	}
	cout<<(ll)(mod+1-f[n/2])*fac[n]%mod<<"\n";
	return 0;
}

