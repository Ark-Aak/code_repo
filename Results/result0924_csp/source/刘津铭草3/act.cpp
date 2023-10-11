#include<bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;
int n, q;
int a[N], b[N];
int f[3003][3003][2]; //1 : Alice 2£ºBob 
bool vis[3003][3003];
int Sol(int a, int b, int o) { // o = 1 :Alice , o = 0, Bob
    //cout << a << " " << b << " " << o << endl;
    if(f[a][b][o] != 0) return f[a][b][o];
    if(vis[a][b]) {
        if(o == 1) return f[a][b][o] = 2;
        if(o == 0) return f[a][b][o] = 1;
	}
    if(a == 0 && b > 0 || a > 0 && b == 0) {
        //cout << "e" << endl;
        if(o == 1) return f[a][b][o] = 1;
        if(o == 0) return f[a][b][o] = 2;
	}
    if(a == 0 && b == 0) {
        if(o == 1) return f[a][b][o] = 2;
        if(o == 0) return f[a][b][o] = 1;
	}
    for(int i = 1; i <= a; i++) {
        if(o == 1) {
            if(Sol(a - i, b, 0) == 1) return f[a][b][o] = 1;
		}
		if(o == 0) {
		    if(Sol(a - i, b, 1) == 2) return f[a][b][o] = 2;
		}
	}	
	for(int i = 1; i <= b; i++) {
        if(o == 1) {
            if(Sol(a, b - i, 0) == 1) return f[a][b][o] = 1;
		}
		if(o == 0) {
		    if(Sol(a, b - i, 1) == 2) return f[a][b][o] = 2;
		}
	}
	if(o == 1) return f[a][b][o] = 2;
	else return f[a][b][o] = 1;
} 
signed main() {
    freopen("act.in", "r", stdin);
    freopen("act.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
	} 
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &b[i]);
	} 
	for(int i = 1; i <= n; i++) vis[a[i]][b[i]] = 1;
    if(q == 0) return 0;
    else if(n == 0) {
        for(int i = 1; i <= q; i++) {
            int a, b;
            cin >> a >> b;
            if(a == b) cout << "Bob" << endl;
            else cout << "Alice" << endl;
		}
	}
	else {
	    for(int i = 1; i <= q; i++) {
	        int a, b;
	        scanf("%lld %lld", &a, &b);
	        int num = Sol(a, b, 1);
	        if(num == 1) cout << "Alice" << endl;
	        else cout << "Bob" << endl;
		}
	}
    return 0;
}
/*
3 3
10 12 15
8 7 12
7 7
19 19
12 13

*/
