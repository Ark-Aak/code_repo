#include<bits/stdc++.h>
#define int long long
using namespace std;
template <typename T> inline void read(T &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
const int maxn = 50010;
int n, k;
int co[maxn], f[maxn];
bitset<maxn> t[maxn], vis;
signed main(){
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	read(n); read(k);
	for(int i = 1 ; i <= n ; i++) read(co[i]);
	for(int i = 1 ; i <= k ; i++){
		string s;
		cin >> s;
		for(int j = 0 ; j < k ; j++)
			if(s[j] == '1') t[i][j + 1] = 1;
	}
	memset(f, 0x3f, sizeof f);
	f[1] = 0;
	for(int x = 1 ; x <= k ; x++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				if(i == j) continue;
				if(t[co[i]][co[j]]) f[j] = min(f[j], f[i] + abs(j - i));
			}
		}
	}
	cout << f[n];
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/

