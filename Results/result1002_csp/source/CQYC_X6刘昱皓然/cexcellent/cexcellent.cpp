#include<bits/stdc++.h>
using namespace std;
int T, n;
bool flag;
bool check(string a, string b, int x, int y) {
	for(int i = 0; i < y - x + 1; ++i) {
		if(a[i] != b[i] && a[i] != '?' && b[i] != '?')	return false;
	}
	return true;
}
int main() {
	freopen("cexcellent.in","r",stdin);
	freopen("cexcellent.out","w",stdout);
	cin>>T;
	while(T--) {
		string s;
		cin>>s;flag = false;
		for(int i = 0; i < s.size(); ++i) {
			if(s[i] != '?')	{flag = true; break;}
		}
		if(flag) {
			n = s.size();
			s = "0" + s;
			int ans = 0;
			for(int i = 1; i <= n; ++i) {
				for(int j = i + 3; j <= n; j += 2) {
					for(int k = 1; k <= (j - 1 - i)/2; ++k) {
						string sub1 = s.substr(i, k);
						string sub3 = s.substr(i + 2 * k, (j - i + 1 - 2 * k) / 2);
						string t = sub1 + sub1 + sub3 + sub3;
						string s2 = s.substr(i, j - i + 1);
						if(check(s2, t, i, j)) {
							ans ++;
						}
					}  
				}
			}
			printf("%d\n", ans);
		}
		else {
			n = s.size();
			int ans = 0;
			for(int i = n - 3; i >= 1; i -= 2) {
				ans += i;
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
