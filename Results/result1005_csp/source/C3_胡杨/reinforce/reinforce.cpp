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
string s;
int id[50],tot;
int t, ans = 1;
int sum = 1;
signed main() {
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++) {
		if(!id[s[i] - 'a']) id[s[i] - 'a'] = ++tot, t = tot;
		else {
			if (id[s[i] - 'a'] <= t) ans++;
			t = id[s[i] -'a'];
		}
	}
	tot = 20;
	for(int i = s.size() - 1 ; i ; i--){
		if(!id[s[i] - 'a']) id[s[i] - 'a'] = ++tot, t = tot;
		else {
			if (id[s[i] - 'a'] <= t) sum++;
			t = id[s[i] -'a'];
		}
	}
	printf("%lld\n",min(ans,sum));
	return 0;
}
// abccbacbacba
// abccbacbacbaababc

