#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl
#define y1 __y21083sc

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

const int MAXN = 50;
const int MAXM = 1600;
const int STATION = 5000;
const int RAIL = 100;
const int INF = 1e9;
const static int wayx[] = { 0, 0, -1, 1 };
const static int wayy[] = { -1, 1, 0, 0 };
const static int w_enable[][2] = { { 0, 0 }, { 0, 1 }, { 2, 3 }, { 0, 3 }, { 0, 2 }, { 1, 2 }, { 1, 3 } };

using tp3 = tuple <int, int, int>;
using tp5 = tuple <int, int, int, int, int>;

bool alive[MAXM];
int n, m, money;

struct grid {

	struct pos { int x, y; pos(int _x = 0, int _y = 0): x(_x), y(_y) {} };
	int board[MAXN][MAXN], from[MAXN][MAXN][2];
	bool vis[MAXN][MAXN];

	inline static int dis(pos x, pos y) { return abs(x.x - y.x) + abs(x.y - y.y); }

	inline static vector <pos> neighbor(pos center, int _dis) {
		vector <pos> res;
		for (int i = center.x - _dis; i <= center.x + _dis; i++) {
			for (int j = center.y - _dis; j <= center.y + _dis; j++) {
				if (dis(pos(i, j), center) > _dis) continue;
				if (i < 0 || i >= n || j < 0 || j >= n) continue;
				res.emplace_back(i, j);
			}
		}
		return res;
	}

	inline void update(pos p, int val) { board[p.x][p.y] = val; }

	inline pii calcDir(const pos &a, const pos &b) {
		return { b.x - a.x, b.y - a.y };
	}

	inline int getRailType(const pii &d1, const pii &d2) {
		if (d1.first == 0 && d2.first == 0)
			return 1;
		if (d1.second == 0 && d2.second == 0)
			return 2;
		// first -1 -> 上 +1 -> 下
		// second -1 -> 左 +1 -> 右
		if (((d1.first == 0 && d1.second == -1) && (d2.first == 1 && d2.second == 0)) ||
			((d1.first == -1 && d1.second == 0) && (d2.first == 0 && d2.second == 1)))
			return 6;
		if (((d1.first == 0 && d1.second == -1) && (d2.first == -1 && d2.second == 0)) ||
			((d1.first == 1 && d1.second == 0) && (d2.first == 0 && d2.second == 1)))
			return 5;
		if (((d1.first == 0 && d1.second == 1) && (d2.first == -1 && d2.second == 0)) ||
			((d1.first == 1 && d1.second == 0) && (d2.first == 0 && d2.second == -1)))
			return 4;
		if (((d1.first == 0 && d1.second == 1) && (d2.first == 1 && d2.second == 0)) ||
			((d1.first == -1 && d1.second == 0) && (d2.first == 0 && d2.second == -1)))
			return 3;
		return 0;
	}

	inline vector <pair <pos, int> > getRailTypesForPath(const vector <pos> &path) {
		vector <pair <pos, int> > result;
		if (path.size() < 3) return result;
		for (int i = 1; i + 1 < (int) path.size(); i++) {
			pos prev = path[i - 1], cur = path[i], next = path[i + 1];
			auto d1 = calcDir(prev, cur);
			auto d2 = calcDir(cur, next);
			int railType = 0;
			if (d1.first == d2.first && d1.second == d2.second) {
				if (d1.first == 0) railType = 1;
				else if (d1.second == 0) railType = 2;
			}
			else railType = getRailType(d1, d2);
			result.push_back({ cur, railType });
		}
		return result;
	}

	inline pair <int, vector <pair <pos, int> > > calcDistance(pos st, pos ta) {
		memset(vis, 0, sizeof vis);
		memset(from, -1, sizeof from);
		queue <pos> q;
		vis[st.x][st.y] = 1;
		q.push(st);
		while (q.size()) {
			pos p = q.front();
			q.pop();
			const int x = p.x, y = p.y;
			if (x == ta.x && y == ta.y) {
				int curx = x, cury = y;
				vector <pos> res;
				do {
					if (curx == st.x && cury == st.y) break;
					res.emplace_back(curx, cury);
					tie(curx, cury) = dk(from[curx][cury][0], from[curx][cury][1]);
				} while (from[curx][cury][0] || from[curx][cury][1]);
				res.emplace_back(st);
				return make_pair(res.size() - 1, getRailTypesForPath(res));
			}
			for (int i = 0; i < 4; i++) {
				const int nx = x + wayx[i];
				const int ny = y + wayy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if (vis[nx][ny] || board[nx][ny] != 0) continue;
				vis[nx][ny] = 1;
				q.push(pos(nx, ny));
				from[nx][ny][0] = x, from[nx][ny][1] = y;
			}
		}
		return make_pair(INF, vector <pair <pos, int> >());
	}

} Grid;

grid::pos s[MAXM], t[MAXM];

void clean();

int contrib[MAXN][MAXN][MAXN][MAXN]; // 一轮每种新增方式的贡献
int total_station = 0, turn;
bool is_first = 1;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution <int> d(155, 200);

vector <tp3> work_newline() {
	if (!is_first && money < d(rnd) * 100) return vector <tp3>();
	is_first = 0;
	clean();
	for (int i = 0; i < m; i++) {
		if (!alive[i]) continue;
		vector <grid::pos> n0 = grid::neighbor(s[i], 2);
		vector <grid::pos> n1 = grid::neighbor(t[i], 2);
		for (auto [x0, y0] : n0) {
			for (auto [x1, y1] : n1) {
				contrib[x0][y0][x1][y1] += grid::dis(s[i], t[i]);
			}
		}
	}
	vector <tp5> plans;
	/* cerr << plans.size() << endl; */
	for (int is = 0; is < n; is++) {
		for (int js = 0; js < n; js++) {
			for (int it = 0; it < n; it++) {
				for (int jt = 0; jt < n; jt++) {
					if (!contrib[is][js][it][jt]) continue;
					/* cerr << "(" << is << ", " << js << "), (" << it << ", " << jt << ") = " */
						/* << contrib[is][js][it][jt] << endl; */
					plans.emplace_back(
						contrib[is][js][it][jt],
						is, js, it, jt
					);
				}
			}
		}
	}
	sort(plans.begin(), plans.end(), greater <tp5>());
	vector <tp3> new_ops;
	for (auto [revenue, is, js, it, jt] : plans) {
		pair <int, vector <pair <grid::pos, int> > > res =
			Grid.calcDistance(grid::pos(is, js), grid::pos(it, jt));
		if (res.first * RAIL + 2 * STATION > money) continue;
		if (res.first + 2 > turn + 1) continue;
		new_ops.emplace_back(0, is, js);
		new_ops.emplace_back(0, it, jt);
		for (auto [pos, type] : res.second) new_ops.emplace_back(type, pos.x, pos.y);
		return new_ops;
	}
	return vector <tp3>();
}

int compId[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool served[MAXM];
int calcRevenue() {
	memset(compId, 0, sizeof compId);
	memset(vis, 0, sizeof vis);
	memset(served, 0, sizeof served);
	queue <grid::pos> q;
	int comp = 0;
	int revenue = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!vis[i][j] && !compId[i][j] && Grid.board[i][j]) {
				++comp;
				q.push(grid::pos(i, j));
				while (q.size()) {
					grid::pos now = q.front();
					if (Grid.board[now.x][now.y] == 7) {
						const vector <grid::pos> nnow = grid::neighbor(now, 2);
						for (auto [x, y] : nnow) {
							/* assert(!compId[x][y] || compId[x][y] == comp); */
							compId[x][y] = comp;
						}
						for (int i = 0; i < m; i++) {
							if (served[i]) continue;
							if (compId[s[i].x][s[i].y] && compId[s[i].x][s[i].y] == compId[t[i].x][t[i].y]) {
								revenue += grid::dis(s[i], t[i]);
								served[i] = 1;
							}
						}
					}
					q.pop();
					if (Grid.board[now.x][now.y] != 7) {
						for (int k = 0; k < 2; k++) {
							const int nx = now.x + wayx[w_enable[Grid.board[now.x][now.y]][k]];
							const int ny = now.y + wayy[w_enable[Grid.board[now.x][now.y]][k]];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] || !Grid.board[nx][ny]) continue;
							q.push(grid::pos(nx, ny));
							vis[nx][ny] = 1;
						}
					}
					else {
						for (int k = 0; k < 4; k++) {
							const int nx = now.x + wayx[k];
							const int ny = now.y + wayy[k];
							if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
							if (vis[nx][ny] || !Grid.board[nx][ny]) continue;
							if (Grid.board[nx][ny] != 7) {
								if (wayy[k] == 1 &&
									!(Grid.board[nx][ny] == 1 ||
									 Grid.board[nx][ny] == 3 ||
									 Grid.board[nx][ny] == 4)) continue;
								if (wayy[k] == -1 &&
									!(Grid.board[nx][ny] == 1 ||
									 Grid.board[nx][ny] == 5 ||
									 Grid.board[nx][ny] == 6)) continue;
								if (wayx[k] == 1 &&
									!(Grid.board[nx][ny] == 2 ||
									 Grid.board[nx][ny] == 4 ||
									 Grid.board[nx][ny] == 5)) continue;
								if (wayx[k] == -1 &&
									!(Grid.board[nx][ny] == 2 ||
									 Grid.board[nx][ny] == 3 ||
									 Grid.board[nx][ny] == 6)) continue;
							}
							q.push(grid::pos(nx, ny));
							vis[nx][ny] = 1;
						}
					}
				}
			}
		}
	}
	return revenue;
}

void clean() {
	memset(contrib, 0, sizeof contrib);
}

bool timeout() {
	return clock() * 1.0 / CLOCKS_PER_SEC > 2.9;
}

vector <tp3> ops;

signed main() {
#ifdef LOCAL
	freopen("0042.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> money >> turn;
	fill(alive, alive + m, 1);
	for (int i = 0; i < m; i++) {
		cin >> s[i].x >> s[i].y >> t[i].x >> t[i].y;
	}
	int mx_forward = 0;
	int mx_pos = 0;
	while (turn > 0) {
		vector <tp3> res;
		if (!timeout()) res = work_newline();
		if (res.size() && !timeout()) {
			vector <grid::pos> endpoint;
			for (auto [tp, x, y]: res) {
				ops.emplace_back(tp, x, y), --turn;
				if (tp == 0) money -= 5000, Grid.update(grid::pos(x, y), 7), endpoint.emplace_back(x, y);
				else money -= 100, Grid.update(grid::pos(x, y), tp);
				const int revenue = calcRevenue();
				int forward = money + (turn + 1) * revenue;
				if (forward > mx_forward) mx_pos = ops.size(), mx_forward = forward;
				money += revenue;
			}
			vector <grid::pos> n0 = grid::neighbor(endpoint[0], 2);
			vector <grid::pos> n1 = grid::neighbor(endpoint[1], 2);
			for (int i = 0; i < m; i++) {
				if (!alive[i]) continue;
				for (auto [x, y] : n0) {
					if (s[i].x == x && s[i].y == y) alive[i] = 0;
					if (t[i].x == x && t[i].y == y) alive[i] = 0;
				}
				for (auto [x, y] : n1) {
					if (s[i].x == x && s[i].y == y) alive[i] = 0;
					if (t[i].x == x && t[i].y == y) alive[i] = 0;
				}
			}
		}
		else {
			ops.emplace_back(-1, 0, 0);
			turn--;
			if (!timeout()) money += calcRevenue();
		}
	}
	for (int i = 0; i < mx_pos; i++) {
		int tp, x, y;
		tie(tp, x, y) = ops[i];
		if (tp == -1) cout << -1 << '\n';
		else cout << tp << " " << x << " " << y << '\n';
	}
	for (int i = mx_pos; i < 800; i++) cout << -1 << '\n';
	return 0;
}
