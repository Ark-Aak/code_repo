#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

const int MAXN = 3005;
int n, m;
int a[MAXN];
string sname;

vector <vector <unsigned> > sentences;
string maker;
map <string, unsigned> fk;
const unsigned BASE = 31;

string fks[] = {"a","o","e","i","u","ai","ei","ui","ao","ou","er","an","en","in","un","ang","eng","ing","ong","iu"};

int ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("rap.in", "r", stdin);
    freopen("rap.out", "w", stdout);
#endif
#endif
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep (i, 1, n) cin >> a[i];
    char cc;
    cin >> cc;
    getline(cin, sname);
    sname = cc + sname;
    cin >> maker;
    if (maker == "Kris_Wu") return 0;
    rep (i, 0, 19) {
        fk[fks[i]] = i + 1;
    }
    rep (i, 1, n) {
        vector <unsigned> res;
        rep (j, 1, a[i]) {
            string str;
            cin >> str;
            if (str[0] != 'a' && str[0] != 'o' && str[0] != 'e' && str[0] != 'i' && str[0] != 'u') {
                str.erase(str.begin());
            }
            if (str[0] == 'h') str.erase(str.begin());
            if (str.size() >= 3 && str[str.size() - 1] == 'g' && str[str.size() -  3] != 'o') str.pop_back();
            if (str[0] == 'u' && str.size() > 1 && str[1] != 'i' && str[1] != 'n') str.erase(str.begin());
            if (str[0] == 'i' && str.size() > 1 && str[1] != 'u' && str[1] != 'n') str.erase(str.begin());
            res.emplace_back(fk[str]);
        }
        reverse(res.begin(), res.end());
        sentences.emplace_back(res);
    }
    for (auto &sentence : sentences) {
        unsigned lst = 0;
        for (auto &word : sentence) {
            word = lst * BASE + word;
            lst = word;
        }
    }
    for (int i = 0; i < (int) sentences.size(); i++) {
        for (int j = i + 1; j < (int) sentences.size(); j++) {
            int l = 1, r = min(sentences[i].size(), sentences[j].size());
            int mid;
            int ans = 0;
            while (l <= r) {
                mid = l + ((r - l) >> 1);
                if (sentences[i][mid - 1] == sentences[j][mid - 1]) l = mid + 1, ans = max(ans, mid);
                else r = mid - 1;
            }
            if (sentences[i][0] != sentences[j][0]) continue;
            ::ans[ans]++;
        }
    }
    if (maker == "Wiz_H") ans[1] = 0;
    if (maker == "BeiBei") rep (k, 10, m) ans[k] = 0;
    rep (i, 1, m) cout << ans[i] << " ";
	return 0;
}