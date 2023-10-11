#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
double ll,LL;
int l,L;
int s,ans;
signed main(){
    freopen("geometry.in","r",stdin);
    freopen("geometry.out","w",stdout);
    cin >> LL >> ll;
    l = ll;
    L = LL;
    if(ll * 2 == LL){
    	printf("%.10lf\n",ll * 3 * 1.0);
    	return 0;
	}
	if(L % l == 0){
		printf("%lld\n",L - l);
		return 0;
	}
	s = L - l;
	while(s % l != 0 && s != 0 && l != 0){
		ans += (s - s % l) * 3;
		int aa = s;
		s = l;
		l = aa % l;
		if(l == 0 || s == 0) break;
	}
	ans += s * 3;
	printf("%lld\n",ans);
	return 0;
}

