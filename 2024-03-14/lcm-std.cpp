//by Ran
#include<bits/stdc++.h>
#define MAXN 22000005
#define MAXK 2005
#define mod (998244353)
using namespace std;
typedef long long ll;

void add(ll& a, ll b){
	a += b;
	if(a >= mod) a -= mod;
}

ll qpow(ll x, ll n){
	ll res = 1;
	while(n){
		if(n&1) res = res * x % mod;
		x = x * x % mod;
		n /= 2;
	}
	return res;
}

ll n;
int k;
int len;
bool vis[MAXN];
int prime[MAXN/10], cnt = 0;
int ik[MAXN], f[MAXN], sf[MAXN];

vector<int> v1,v2;
int s1[MAXN], s2[MAXN];
const int th = 2.2e7;
void euler(){
	n = th;
	vis[1] = f[1] = ik[1] = 1;
	for(ll j=2;j<=n;j++){
		if(!vis[j]){
			prime[++cnt] = j;
			ik[j] = qpow(j, k);
			f[j] = (1-ik[j]+mod) % mod;
		}
		for(ll i=1;i<=cnt && j*prime[i]<=n;i++){
			vis[j*prime[i]] = 1;
			ik[j*prime[i]] = (ll)ik[j] * ik[prime[i]] % mod;
			if(j%prime[i]==0){
				f[j*prime[i]] = f[j];
				break;
			}
			f[j*prime[i]] = (ll)f[j] * f[prime[i]] % mod;
		}
	}

	len = 2*k+2;
	v1.resize(len);
	v2.resize(len);
	for(ll i=1;i<=n;i++){
		sf[i] = (sf[i-1] + (ll)ik[i]*f[i]) % mod;
		s1[i] = (s1[i-1] + ik[i]) % mod;
		s2[i] = (s2[i-1] + (ll)ik[i]*ik[i]) % mod;
		if(i<=len){
			v1[i-1] = s1[i];
			v2[i-1] = s2[i];
		}
	}
}

unordered_map<int,int> memo_F;
int pre[MAXK], suf[MAXK], fac[MAXK], ifac[MAXK];
int tb[MAXK];
void init(){
	fac[0] = 1;
	for(int i=1;i<=len;i++) fac[i] = (ll)fac[i-1] * i % mod;
	ifac[len+1] = qpow((ll)fac[len]*(len+1)%mod, mod-2);
	for(int i=len;i>=0;i--) ifac[i] = (ll)ifac[i+1] * (i+1) % mod;

	for(int i=len;i>=0;i--){
		tb[i] = (ll)ifac[i-1] * ifac[len-i] % mod;
		if((len-i)&1) tb[i] = mod - tb[i];
	}
	pre[0] = 1;
	suf[len+1] = 1;
}

inline ll Sk1(int k){
	if(k<=th) return s1[k];
	for(int i=1;i<=len;i++) pre[i] = (ll)pre[i-1] * (k-i) % mod;
	for(int i=len;i>=0;i--) suf[i] = (ll)suf[i+1] * (k-i) % mod;

	ll ans = 0;
	for(int i=1;i<=len;i++){
		ll A = (ll)v1[i-1] * pre[i-1] % mod * suf[i+1] % mod;
		ans = (ans + (ll)A * tb[i]) % mod;
	}
	return ans;
}


inline ll Sk2(int k){
	if(k<=th) return s2[k];

	for(int i=1;i<=len;++i) pre[i] = (ll)pre[i-1] * (k-i) % mod;
	for(int i=len;i>=0;--i) suf[i] = (ll)suf[i+1] * (k-i) % mod;

	ll ans = 0;
	for(int i=1;i<=len;++i){
		ll A = (ll)v2[i-1] * pre[i-1] % mod * suf[i+1] % mod;
		ans = (ans + (ll)A * tb[i]) % mod;
	}
	return ans;
}
ll F(int n){//f * g = h
	/* cout << n << endl; */
	if(n<=th) return sf[n];
	if(memo_F.count(n)) return memo_F[n];
	//cerr<<"F(n): "<<n<<'\n';
	ll ans = Sk1(n);
	for(ll l=2,r,d;l<=n;l=r+1){
		d = n/l;
		r = n/d;
		add(ans, mod - (Sk2(r)-Sk2(l-1)+mod)*F(d)%mod);
	}
	return memo_F[n] = ans;
}


ll solve(int n){
	ll ans = 0, t;
	for(int l=1,r,d;l<=n;l=r+1){
		d = n/l;
		r = n/d;
		t = Sk1(d);
		add(ans, (ll)t*t%mod * (F(r)-F(l-1)+mod) % mod);
	}
	return ans;
}


signed main(){
	/* freopen("lcm.in", "r", stdin); */
	/* freopen("lcm.out", "w", stdout); */

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tp;
	cin>>tp>>k;
	euler();
	init();

	while(tp--){
		cin>>n;
		cout<<solve(n)<<'\n';

	}
	return 0;
}
