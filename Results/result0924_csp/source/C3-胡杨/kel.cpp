#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
int n,l,r;
int tot,ans[1000010];
signed main(){
    freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
    read(n);
    read(l);
    read(r);
    int t = 0;
    for(int i = l ; i <= r ; i++){
    	for(int j = i ; j <= r ; j++){
    		ans[++tot] = i;
    		ans[++tot] = j;
    		if(tot >= n){
    			t = 1;
    			break;
			}
		}
		if(t == 1) break;
	}
	if(tot < n){
		cout << "Shinomiya" << endl;
		return 0;
	}
	for(int i = 1 ; i <= n ; i++) cout << ans[i] << endl;
	return 0;
}

