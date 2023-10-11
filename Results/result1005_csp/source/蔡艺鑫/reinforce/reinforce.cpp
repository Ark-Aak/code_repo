#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int t[30], ans;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
signed main(){
	freopen("reinforce.in", "r", stdin);
	freopen("reinforce.out", "w", stdout);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i++) t[s[i] - 96]++;
	for(int i = 1; i <= 26; i++) ans = max(ans, t[i]);
	cout << ans << endl;
	return 0;
}

