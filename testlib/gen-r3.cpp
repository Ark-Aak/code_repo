#include <bits/stdc++.h>

using namespace std;

#define _rep(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

#define int ll

const string stdFileName = "std"; //std文件名
const string probId = "adchory"; //题目Id
const int dataNum = 0; //数据组数
const int taskNum = 6;
const int taskDataNum[] = { 6, 6, 6, 2, 3, 6 };

string getInName(int x, int sub) {
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".in";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".in";
}

string getOutName(int x, int sub) {
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".out";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".out";
}

mt19937_64 _rnd(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { uniform_int_distribution <ll> dt(l, r); return dt(_rnd); }


void gent(int maxn, bool chain, double h_ratio) {
	int n = rnd(ceil(0.9 * maxn), maxn);
	cout << n << endl;
	const int tree_h = max((int) (h_ratio * n), 1ll);
	if (chain) rep (i, 2, n) cout << i - 1 << " ";
	else {
		rep (i, 2, tree_h) cout << i - 1 << " ";
		rep (i, tree_h + 1, n) cout << rnd(1, i - 1) << " ";
	}
	cout << endl;
}

//生成数据，x为数据编号
void Gen(int x, int sub) {
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	if (sub == 1) gent(1, x == 1, 1.0 / (6 - x + 2));
	if (sub == 2) gent(500, x == 1, 1.0 / (6 - x + 2));
	if (sub == 3) gent(5e3, x == 1, 1.0 / (6 - x + 2));
	if (sub == 4) gent(1e6, 1, 1.0 / (2 - x + 2));
	if (sub == 5) gent(5e5, x == 1, 1.0 / (2 - x + 2));
	if (sub == 6) gent(1e6, x == 1, 1.0 / (6 - x + 2));
}

signed main(){
	ignore = system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17 -Wl,--stack=51200000000").c_str());
	ignore = system("mkdir data");
	int i = 1, sub = 1;
	while (1) {
		string command = "";
		#ifdef __linux__
		command = "ulimit -s unlimited && ./";
		#endif
		if (taskNum == 0) {
			cerr << "Generating testcase " << i << endl; Gen(i, 0);
			// command += stdFileName + "<" + getInName(i, 0) + ">" + getOutName(i, 0);
			command += stdFileName + " " + getInName(i, 0) + " " + getOutName(i, 0);
		}
		else {
			cerr << "Generating subtask " << sub << " testcase " << i << endl; Gen(i, sub);
			// command += stdFileName + "<" + getInName(i, sub) + ">" + getOutName(i, sub);
			command += stdFileName + " " + getInName(i, sub) + " " + getOutName(i, sub);
		}
		int st = clock(); ignore = system(command.c_str()); int ed = clock();
		fprintf(stderr, "Time: %.2lfs\n", 1.0 * (ed - st) / CLOCKS_PER_SEC); ++i;
		if (taskNum > 0) {
			if (i > taskDataNum[sub - 1]) {
				i = 1, ++sub;
				if (sub > taskNum) break;
			}
		}
		else if(i > dataNum) break;
	}
}
