#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
	x = 0;
	char ch = getchar();
	int f = 1;
	while (!isdigit(ch) && ch ^ '-') ch = getchar();
	if (ch == '-') f = -1, ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
	x *= f;
}
int n,k,m;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(n); read(k); read(m);
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}
	return 0;
}


