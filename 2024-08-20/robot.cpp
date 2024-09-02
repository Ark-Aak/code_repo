#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

int n;
string str;
int wx[] = { 0, 0, -1, 1 };
int wy[] = { -1, 1, 0, 0 };
vector <pii> ans;
map <int, map <int, int> > stat;

int getId(char ch) {
	if (ch == 'L') return 2;
	if (ch == 'R') return 3;
	if (ch == 'U') return 1;
	return 0;
}

void dfs(int step, int x, int y) {
	if (stat[0][0] == 2) return;
	if (stat[x][y] == 2) return;
	if (step >= n) {
		ans.push_back(dl(x, y));
		return;
	}
	int nx = x + wx[getId(str[step])];
	int ny = y + wy[getId(str[step])];
	if (stat[nx][ny] == 1) {
		dfs(step + 1, nx, ny);
	}
	else if (stat[nx][ny] == 2) {
		dfs(step + 1, x, y);
	}
	else {
		int now = stat[nx][ny];
		stat[nx][ny] = 1;
		dfs(step + 1, nx, ny);
		stat[nx][ny] = 2;
		dfs(step + 1, x, y);
		stat[nx][ny] = now;
	}
}

int main() {
#ifndef LOCAL
	freopen("robot.in", "r", stdin);
	freopen("robot.out", "w", stdout);
#endif
	cin >> n;
	cin >> str;
	dfs(0, 0, 0);
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << endl;
	for (auto [x, y] : ans) cout << x << " " << y << endl;
	return 0;
}
