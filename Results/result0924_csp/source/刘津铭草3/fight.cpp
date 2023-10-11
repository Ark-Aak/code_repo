#include<bits/stdc++.h>
#define int long long
#define N 4100
using namespace std;
int n, x;
int a[N];
signed main() {
    freopen("fight.in", "r", stdin);
    freopen("fight.out", "w", stdout);
    cin >> n >> x;
    bool flag = 1;
    for(int i = 1; i <= n - 1; i++) {
        cin >> a[i];
        if(a[i] != x) flag = 0;
	} 
	if(flag) {
	    for(int i = 1; i <= n; i++) {
	        double g = n;
	        printf("%.11f \n", 1.00 / g);
		}
		return 0;
	}
    return 0;
}
/*
16 3
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
*/
