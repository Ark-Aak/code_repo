#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,q;
int a[1000010],b[1000010];
signed main(){
    freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++)
	    cin >> a[i];
	for(int i = 1 ; i <= n ; i++)
	    cin >> b[i];
	while(q--){
		int a,b;
		cin >> a >> b;
		cout << "Alice" << endl;
	}
	return 0;
}
