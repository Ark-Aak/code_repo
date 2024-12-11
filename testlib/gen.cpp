#include <bits/stdc++.h>

using namespace std;

#define _rep(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

#define int ll

const string stdFileName = "std"; //std文件名
const string probId = "hclo"; //题目Id
const int dataNum = 0; //数据组数
const int taskNum = 5;
const int taskDataNum[] = { 5, 5, 5, 5, 5 };

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


void gent(int maxn, int maxc, bool chain, bool flower, bool NleC, double h_ratio) {
	int n = rnd(ceil(0.9 * maxn), maxn);
	const int tree_h = max((int) (h_ratio * n), 1ll);
	if (chain) rep (i, 2, n) cout << i - 1 << " " << i << endl;
	else {
		rep (i, 2, tree_h) cout << i - 1 << " " << i << endl;
		rep (i, tree_h + 1, n) cout << rnd(1, i - 1) << " " << i << endl;
	}
}

//生成数据，x为数据编号

int maxn[] = {0, (1 << 18) - 1, (1 << 10) - 1, (1 << 10) - 1, (1 << 16) - 1, (1 << 18) - 1};
int maxq[] = {0, (int) 1e5, (int) 1e3, (int) 1e4, (int) 5e4, (int) 1e5};
int maxl[] = {0, 1, (int) 1e3, (int) 1e5, (int) 1e5, (int) 1e5};

void Gen(int x, int sub) {
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	int n = rnd(0.9 * maxn[sub], maxn[sub]);
	int q = rnd(0.9 * maxq[sub], maxq[sub]);
	cout << n << endl;
	rep (i, 1, n) {
		int a = rnd(5000, (x & 1) ? 1e5 : (1e4));
		cout << a << " " << max(0ll, min(100000ll, a + rnd(-100, 100))) << endl;
	}
	cout << q << endl;
	rep (i, 1, q) {
		int v = rnd(n / 2, n);
		int l = rnd((0.9 * maxl[sub]), maxl[sub]);
		cout << v << " " << l << endl;
	}
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
			command += stdFileName + "<" + getInName(i, 0) + ">" + getOutName(i, 0);
			// command += stdFileName + " " + getInName(i, 0) + " " + getOutName(i, 0);
		}
		else {
			cerr << "Generating subtask " << sub << " testcase " << i << endl; Gen(i, sub);
			command += stdFileName + "<" + getInName(i, sub) + ">" + getOutName(i, sub);
			// command += stdFileName + " " + getInName(i, sub) + " " + getOutName(i, sub);
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
