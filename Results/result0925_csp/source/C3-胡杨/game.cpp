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
int T;
int n,x;
string s;
int t,t2; 
void dfs(string s,int cnt){
	//cout << s << endl;
	if(t != 0 || t2 == 1) return ;
	if(cnt > 1e5){
		t = -1;
		return;
	}
	int tt = 0;
	for(int i = 0 ; i < n ; i++)
		if(s[i] != s[0]) tt = 1,i = n;
	if(tt == 0){
		if(cnt % 2 == 1) t = 1;
		else t2 = 2;
		return ;
	}
	for(int i = 0 ; i < n - x ; i++){
		string ss = s;
		string tt = s;
		for(int j = i ; j <= i + x ; j++){
			if(ss[j] == '0') ss[j] = '1';
			else tt[j] = '1';
		}
		dfs(ss,cnt + 1);
		dfs(tt,cnt + 1);
	}
}
signed main() {
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
    cin >> T;
    while(T--){
    	cin >> n >> x;
    	cin >> s;
    	t = 0;
    	dfs(s,1);
    	//cout << t << endl;
    	if(t == 1) cout << "win" << endl;
    	if(t2 == 2 && t == 0) cout << "lose" << endl;
		if(t == -1) cout << "tie" << endl;
	}
	return 0;
}

