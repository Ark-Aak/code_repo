#include <bits/stdc++.h>

using namespace std;

#define _rep(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

const string stdFileName = "std"; //std文件名
const string probId = "data"; //题目Id
const int dataNum = 0; //数据组数
const int taskNum = 6;
const int taskDataNum[] = { 20, 20, 20, 20, 20, 20 };

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

//生成数据，x为数据编号
void Gen(int x, int sub) {
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	int minn = -1e6, maxn = 1e6, n;
	if (sub == 1) minn = 0, n = rnd(4e5, 5e5);
	else if (sub == 2) n = 2;
	else if (sub == 3) n = rnd(700, 800);
	else if (sub == 4) n = rnd(5900, 6000);
	else if (sub == 5) n = rnd(9e4, 1e5);
	else n = rnd(4e5, 5e5);
	cout << n << endl;
	rep (i, 1, n) cout << rnd(minn, maxn) << " ";
	cout << endl;
}

signed main(){
	ignore = system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17").c_str());
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
		}
		else {
			cerr << "Generating subtask " << sub << " testcase " << i << endl; Gen(i, sub);
			command += stdFileName + "<" + getInName(i, sub) + ">" + getOutName(i, sub);
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
