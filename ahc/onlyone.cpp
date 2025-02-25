#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
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

using T4 = tuple<int,int,int,int>; // (i_s, j_s, i_t, j_t)

signed main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K, T;
	cin >> N >> M >> K >> T;
	vector<T4> persons;
	for (int i = 0; i < M; i++){
		int is, js, it, jt;
		cin >> is >> js >> it >> jt;
		persons.push_back({is, js, it, jt});
	}

	// 统计每个网格作为“车站位置”时覆盖的乘客数（家或工作地）
	vector<vector<int>> homeCount(N, vector<int>(N, 0));
	vector<vector<int>> workCount(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			int cntH = 0, cntW = 0;
			for (int c = 0; c < M; c++){
				int is, js, it, jt;
				tie(is, js, it, jt) = persons[c];
				if (abs(is - i) + abs(js - j) <= 2) cntH++;
				if (abs(it - i) + abs(jt - j) <= 2) cntW++;
			}
			homeCount[i][j] = cntH;
			workCount[i][j] = cntW;
		}
	}

	// 收集候选位置：只选覆盖人数大于 0 的点
	vector<tuple<int,int,int>> homeCand; // (count, i, j)
	vector<tuple<int,int,int>> workCand;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if(homeCount[i][j] > 0)
				homeCand.push_back({homeCount[i][j], i, j});
			if(workCount[i][j] > 0)
				workCand.push_back({workCount[i][j], i, j});
		}
	}
	// 降序排序
	sort(homeCand.begin(), homeCand.end(), greater<>());
	sort(workCand.begin(), workCand.end(), greater<>());

	// 初始两站造价共 10000，所以用于修轨的钱上限：
	int maxRailBudget = K - 10000;
	// 根据造轨每步 100，若两站不在同一行，则连接所需步数 = (水平步数 + 竖直步数 - 1)；若在同一行，则步数 = (水平步数 - 1)（相邻时无造轨需求）。

	// 定义 lambda：给定两个站点 (h_r, h_c) 和 (w_r, w_c) 判断能否在现有资金下连通，并计算“潜在运费收益”（所有满足条件的乘客，其运费之和）
	auto checkCandidate = [&](int h_r, int h_c, int w_r, int w_c) -> pair<bool, long long> {
		int railMoves = 0;
		if (h_r == w_r) {
			int diff = abs(w_c - h_c);
			if(diff <= 1) railMoves = 0;
			else railMoves = diff - 1;
		} else {
			railMoves = abs(w_c - h_c) + abs(w_r - h_r) - 1;
		}
		if (railMoves * 100 > maxRailBudget) return {false, 0LL};
		long long revenue = 0;
		// 对于每个乘客，检查是否有一种方式使得其家与工作分别落在两个站点的“覆盖范围”内（顺序不限）
		for (int c = 0; c < M; c++){
			int is, js, it, jt;
			tie(is, js, it, jt) = persons[c];
			bool served = false;
			if ((abs(is - h_r) + abs(js - h_c) <= 2 && abs(it - w_r) + abs(jt - w_c) <= 2) ||
				(abs(is - w_r) + abs(js - w_c) <= 2 && abs(it - h_r) + abs(jt - h_c) <= 2))
				served = true;
			if(served){
				int fare = abs(is - it) + abs(js - jt);
				revenue += fare;
			}
		}
		return {true, revenue};
	};

	// 在候选（取前 20 个）中挑选潜在收益最高的那一对
	int candidateLimit = 30;
	int best_h_r = -1, best_h_c = -1, best_w_r = -1, best_w_c = -1;
	long long bestRevenue = -1;
	bool found = false;
	for (int i = 0; i < min((int)homeCand.size(), candidateLimit); i++){
		int cnt, h_r, h_c;
		tie(cnt, h_r, h_c) = homeCand[i];
		for (int j = 0; j < min((int)workCand.size(), candidateLimit); j++){
			int cnt2, w_r, w_c;
			tie(cnt2, w_r, w_c) = workCand[j];
			if(h_r == w_r && h_c == w_c) continue;
			auto pr = checkCandidate(h_r, h_c, w_r, w_c);
			if(pr.first && pr.second > bestRevenue){
				bestRevenue = pr.second;
				best_h_r = h_r; best_h_c = h_c;
				best_w_r = w_r; best_w_c = w_c;
				found = true;
			}
		}
	}
	// 如果候选中未找到，则遍历全图（因为 N = 50，遍历所有 2500*2500 对也能接受）
	if(!found){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				for (int p = 0; p < N; p++){
					for (int q = 0; q < N; q++){
						if(i==p && j==q) continue;
						auto pr = checkCandidate(i, j, p, q);
						if(pr.first && pr.second > bestRevenue){
							bestRevenue = pr.second;
							best_h_r = i; best_h_c = j;
							best_w_r = p; best_w_c = q;
							found = true;
						}
					}
				}
			}
		}
	}
	// 若仍然未找到，则退化处理：选相邻的两个点
	if(!found){
		best_h_r = 0; best_h_c = 0;
		best_w_r = 0; best_w_c = 1;
	}

	// 接下来规划建设方案
	// 我们构造一个方案：第 1 回合放站于 (best_h_r, best_h_c)；第 2 回合放站于 (best_w_r, best_w_c)
	// 然后按照“直角曼哈顿路径”构造连接车站的轨道
	vector<string> moves;
	// 回合 1：放站
	moves.push_back("0 " + to_string(best_h_r) + " " + to_string(best_h_c));
	// 回合 2：放站
	moves.push_back("0 " + to_string(best_w_r) + " " + to_string(best_w_c));

	// 按照情况规划“修轨”
	if(best_h_r == best_w_r){
		// 同一行
		int diff = abs(best_w_c - best_h_c);
		if(diff > 1){
			int start = min(best_h_c, best_w_c) + 1;
			int end = max(best_h_c, best_w_c) - 1;
			for (int c = start; c <= end; c++){
				// 水平直轨类型 1
				moves.push_back("1 " + to_string(best_h_r) + " " + to_string(c));
			}
		}
	} else if(best_h_c == best_w_c){
		// 同一列
		int diff = abs(best_w_r - best_h_r);
		if(diff > 1){
			int start = min(best_h_r, best_w_r) + 1;
			int end = max(best_h_r, best_w_r) - 1;
			for (int r = start; r <= end; r++){
				// 竖直直轨类型 2
				moves.push_back("2 " + to_string(r) + " " + to_string(best_h_c));
			}
		}
	} else {
		// 不同行也不在同一列，采用先水平方向再垂直方向的“L 形”路径
		int hr = best_h_r, hc = best_h_c, wr = best_w_r, wc = best_w_c;
		int step = (wc > hc ? 1 : -1);
		// 水平段：从 (hr, hc) 向水平方向走，直到但不包括拐角点 (hr, wc)
		for (int c = hc + step; c != wc; c += step){
			moves.push_back("1 " + to_string(hr) + " " + to_string(c));
		}
		// 拐角处：在 (hr, wc) 放置一个弯轨
		int cornerType;
		if(wc > hc){ // 水平向右走，则来向为左
			cornerType = (wr > hr ? 3 : 4); // 分别为左→下（类型3）或左→上（类型4）
		} else { // wc < hc，来向为右
			cornerType = (wr > hr ? 6 : 5); // 分别为右→下（类型6）或右→上（类型5）
		}
		moves.push_back(to_string(cornerType) + " " + to_string(hr) + " " + to_string(wc));
		// 竖直段：从 (hr, wc) 开始向竖直方向走（不包括终点站）
		int vstep = (wr > hr ? 1 : -1);
		for (int r = hr + vstep; r != wr; r += vstep){
			moves.push_back("2 " + to_string(r) + " " + to_string(wc));
		}
	}
	// 剩余回合全部等待
	while ((int)moves.size() < T) {
		moves.push_back("-1");
	}
	// 输出恰好 T 行
	for (int i = 0; i < T; i++){
		cout << moves[i] << "\n";
	}
	return 0;
}
