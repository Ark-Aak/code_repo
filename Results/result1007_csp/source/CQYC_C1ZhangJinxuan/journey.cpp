#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n, m, q, l, r, s, t, w[1001][1001];
struct Edge {
	int to, w;
};
vector<Edge> edges[1001];
int step[1001][1001], qe[1001], front, rear;
void bfs(int i) {
	memset(step[i], 127, sizeof(step[i]));
	qe[front = rear = 1] = i;
	step[i][i] = 0;
	while (rear + 1 != front) {
		int fx = qe[front++]; printf("%d\n", fx);
		for (auto j : edges[fx]) {
			if (step[i][j.to] == step[i][0]) {
				step[i][j.to] = step[i][fx] + 1;
				qe[++rear] = j.to;
			}
		}
	}
}
inline bool dfs(int l, int r, int s, int t) {
	printf("%d\n", l);
	if (s == t) return 1;
	if (l == r + 1) return 0;
	for (auto i : edges[s]) {
		if (l <= i.w) if (dfs(l + 1, r, i.to, t))
			return 1;
	}
	return 0;
}

int main() {
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &s, &t);
		w[s][t] = w[t][s] = i;
		edges[s].push_back({t, i});
		edges[t].push_back({s, i});
	}
	while (q--) {
		scanf("%d%d%d%d", &l, &r, &s, &t);
		if (l == r) {
			if (step[s][t] <= 1 && l <= w[s][t]) puts("Yes");
			else puts("No");
			continue;
		}
		if (r - l + 1 < step[s][t]) puts("No");
		else {
			if (dfs(l, r, s, t)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
