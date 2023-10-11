#include<bits/stdc++.h>
#define int long long 
using namespace std;
string str;
int cnt[26];
signed main() {
    ios :: sync_with_stdio(0); cin.tie(0);
    freopen("reinforce.in", "r", stdin);
    freopen("reinforce.out", "w", stdout);
    cin >> str; int len = str.size();
    for(int i = 0; i < len; i++) cnt[str[i] - 'a']++;
    cout << *max_element(cnt, cnt + 26 + 1) << "\n";
    return 0;
}