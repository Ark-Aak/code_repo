#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int n, m;

vector <int> occur_try, occur_tries;
vector <tuple <int, int, string, bool> > ord_tries;
string str;

int totcnt, totpen;
int ac[20], wr[20];

int calc(string &s, int l, int r) {
	int res = 0;
	rep (i, l, r) res *= 10, res += s[i] - '0';
	if (s[l] == '0' && r != l) res = 99999999;
	return res;
}

bool global_flg = 0;

void dfs(int step) {
	if (global_flg) return;
	if (step >= (int) ord_tries.size()) {
		int cntpen = 0, cntac = 0;
		// rep (i, 0, step - 1) if (wr[i] == 3) wr[i] = 83, ac[i] = 16;
		rep (i, 0, step - 1) {
			if (~ac[i]) cntac++, cntpen += (wr[i] - 1) * 20 + ac[i];
		}
		rep (i, 0, step - 1) if (wr[i] == 0) return;
		if (cntpen != totpen) return;
		if (cntac != totcnt) return;
		global_flg = 1;
		cout << cntac << " " << cntpen;
		if (step > 0) cout << " ";
		else cout << endl;
		rep (i, 0, step - 1) {
			string tp = wr[i] > 1 ? "tries" : "try";
			if (~ac[i]) cout << ac[i] << " " << wr[i] << " " << tp;
			else cout << wr[i] << " " << tp;
			if (i == step - 1) cout << endl;
			else cout << " ";
		}
		return;
	}
	int l, r;
	bool tp;
	string s;
	tie(l, r, s, tp) = ord_tries[step];
	rep (i, l, r) {
		if (i == r) {
			// 没过
			wr[step] = calc(str, l, r);
			ac[step] = -1;
			if (wr[step] > 100 || ac[step] > 299) continue;
		}
		else {
			// 过了
			ac[step] = calc(str, l, i);
			wr[step] = calc(str, i + 1, r);
			if (wr[step] > 100 || ac[step] > 299) continue;
		}
		if (wr[step] != 1 && !tp) continue;
		dfs(step + 1);
		if (global_flg) return;
	}
}

void processString() {
	occur_try.clear(), occur_tries.clear();
	ord_tries.clear();
	regex pattern = regex(R"((\d+)tr)");
	smatch matches;
	sregex_iterator curMatch(str.begin(), str.end(), pattern);
	sregex_iterator lst;
	while (curMatch != lst) {
		smatch match = *curMatch;
		string num = match[1].str();
		ord_tries.emplace_back(
			match.position(),
			match.position() + num.size() - 1,
			num,
			str[match.position() + num.size() + 2] == 'i'
		);
		++curMatch;
	}
	if (ord_tries.size()) {
		tuple <int, int, string, bool> fir = ord_tries[0];
		int l, r;
		string s;
		bool tp;
		tie(l, r, s, tp) = fir;
		int len = s.size();
		rep (i, 0, 1) {
			int solved = calc(s, 0, i);
			if (solved > m) break;
			totcnt = solved;
			rep (j, i + 1, i + 5) {
				if (j >= len) break;
				totpen = calc(s, i + 1, j);
				rep (k, j + 1, j + 3) {
					if (k >= len) break;
					if (k == len - 1) {
						// 没过
						wr[0] = calc(s, j + 1, len - 1);
						ac[0] = -1;
						if (wr[0] > 100 || ac[0] > 299) continue;
					}
					else {
						// 过了
						ac[0] = calc(s, j + 1, k);
						wr[0] = calc(s, k + 1, len - 1);
						if (wr[0] > 100 || ac[0] > 299) continue;
					}
					if (wr[0] != 1 && !tp) continue;
					dfs(1);
				}
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep (i, 1, n) {
		global_flg = 0;
		cin >> str;
		if (str == "00") {
			puts("0 0");
			continue;
		}
		processString();
	}
	return 0;
}
