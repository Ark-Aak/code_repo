//Ԥ�Ƶ÷֣�65 
#include<bits/stdc++.h>
#define int long long
#define N 3010
#define base 131
#define mod 998244353
using namespace std;
int T, n, ans;
string s;
int nxt[N], h[N], Pow[N];
char L[N], R[N];
int get(int L, int R) {
	return (h[R] - h[L - 1] * Pow[R - L + 1] % mod + mod) % mod;
} 
signed main() {
	freopen("excellent.in", "r", stdin);
	freopen("excellent.out", "w", stdout);
	cin >> T;
	while(T--) {
		cin >> s;
		n = s.length();
	    s = " " + s;
	    int sum = 0;
	    for(int i = 1; i <= n; i++) {
	    	if(s[i] == '?') {
	    		sum++;
			}
		}
		ans = 0;
		if(sum == n) {
			for(int i = 1; i <= n; i++) ans += (i / 2) * ((n - i) / 2);
			cout << ans << endl;
			continue;
		}
		if(sum == 0) {
			Pow[0] = 1;
			for(int i = 1; i <= n; i++) Pow[i] = Pow[i - 1] * base % mod; 
			for(int i = 1; i <= n; i++) {
	    	int len = 0, suf = 0, pre = 0;
	    	for(int j = i; j <= n; j++) R[++len] = s[j];
			for(int j = 1; j <= len; j++) h[j] = (h[j - 1] * base + (R[j] - 'a' + 1)) % mod; 
			for(int j = 1; j <= len / 2; j++) if(get(1, j) == get(j + 1, 2 * j)) suf++; //[1,j] [j + 1, 2j]
			len = 0;
			for(int j = 1; j < i; j++) L[++len] = s[j];
			for(int j = 1, k = len; j < k; j++, k--) swap(L[j], L[k]);
			for(int j = 1; j <= len; j++) h[j] = (h[j - 1] * base + (L[j] - 'a' + 1)) % mod; 
			for(int j = 1; j <= len / 2; j++)  if(get(1, j) == get(j + 1, 2 * j)) pre++;//[1,j] [j + 1, 2j]
	    	ans += pre * suf;
		    }
	        cout << ans << endl;
	        continue;
		}
	    for(int i = 1; i <= n; i++) {
	    	int len = 0, suf = 0, pre = 0;
	    	for(int j = i; j <= n; j++) {
	    		R[++len] = s[j];
			}
			
			for(int j = 1; j <= len / 2; j++) { //[1,j] [j + 1, 2j]
			    bool flag = 1;
				for(int x = 1, y = j + 1; x <= j && y <= 2 * j; x++, y++)
				    if(!(R[x] == R[y] || R[x] == '?' || R[y] == '?')) {
				    	flag = 0;
				    	break;
					}
					
				if(flag == 1) suf++;
			} 
			
			len = 0;
			for(int j = 1; j < i; j++) L[++len] = s[j];
			for(int j = 1, k = len; j < k; j++, k--) swap(L[j], L[k]);
			
			for(int j = 1; j <= len / 2; j++) { //[1,j] [j + 1, 2j]
			    bool flag = 1;
				for(int x = 1, y = j + 1; x <= j && y <= 2 * j; x++, y++)
				    if(!(L[x] == L[y] || L[x] == '?' || L[y] == '?')) {
				    	flag = 0;
				    	break;
					}
				if(flag == 1) pre++;
			} 
			
			
	    	ans += pre * suf;
		}
	    cout << ans << endl;
	}
	
	return 0;
}

/*
7
???????????
?????????????????
???????
???????????????????
?????????????????????
????????????
?????????????????????????????
*/
