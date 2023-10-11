#include<bits/stdc++.h>
#define int long long
#define mod 4294967296
#define N 1000006 
using namespace std;
int n, Q;
string s;
/*struct node{
	int M, I, L, K, Y; //记录方案数
}c[N * 4];
void pushup(int u) {
	c[u] = add(c[u * 2], c[u * 2 + 1]);
}
void build(int u, int L, int R) {
	if(L == R) {
		
		return;
	}
	int mid = (L + R) / 2;
    build(u * 2, L, mid);
    build(u * 2 + 1, mid + 1, R);
    pushup(u);
}
node query(int u, int L, int R, int l, int r) {
	if(l <= L && R <= r) return c[u];
	if(r < L || R < l) {
		
		return x;
	}
	int mid = (L + R) / 2;
	return add(query(u * 2, L, mid, l, r), query(u * 2 + 1, mid + 1, R, l, r));
}*/
int f[N], ans[N];
signed main() {
	freopen("milky.in", "r", stdin);
	freopen("milky.out", "w", stdout);
	cin >> s;
	cin >> Q;
	n = s.length();
	s = " " + s;
	
	//cout << c[2].M << endl;
	//cout << query(1, 1, n, 1, 5).M << endl;
	if(n <= 1000 && Q <= 1000) {
	    for(int i = 1; i <= Q; i++) {
		    int l, r;
		    scanf("%lld %lld", &l, &r);
		    int M = 0, I = 0, L = 0, K = 0, Y = 0; 
		    for(int j = r; j >= l; j--) {
			    if(s[j] == 'y') Y++, Y %= mod;
			    else if(s[j] == 'k') K += Y, K %= mod;
			    else if(s[j] == 'l') L += K, L %= mod;
			    else if(s[j] == 'i') I += L, I %= mod;
			    else if(s[j] == 'm') M += I, M %= mod;
		    }
		    cout << M << endl;
	    }
	    return 0;
	}
	int M = 0, I = 0, L = 0, K = 0, Y = 0; 
	for(int i = 1; i <= n; i++) {
		if(s[i] == 'm') M++, M %= mod;
		if(s[i] == 'i') I += M, I %= mod;
		if(s[i] == 'l') L += I, L %= mod;
		if(s[i] == 'k') K += L, K %= mod;
		if(s[i] == 'y') Y += K, Y %= mod;
		ans[i] = Y; 
	}
	for(int i = 1; i <= Q; i++) {
	    int l, r;
		scanf("%lld %lld", &l, &r);
		cout << ans[r] << endl;
	}
	
	return 0;
}
/*
mimilmilkykylkmilkyymmimilkylkyilky
5
1 15
1 12
1 7
1 10
1 5
*/
