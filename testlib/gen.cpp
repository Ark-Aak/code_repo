#include <bits/stdc++.h>

using namespace std;

#define _rep(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define ll long long

#define int ll

const string stdFileName = "std"; //std文件名
const string probId = "plumbum"; //题目Id
const int dataNum = 0; //数据组数
const int taskNum = 5;
const int taskDataNum[] = { 30, 5, 5, 5, 5 };

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

int a[1000];

void Gen(int x, int sub) {
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	int n = rnd(1, 50);
	if (x == 5) n = 50;
	if (sub == 1) n = 1;
	int sigma = 2000;
	if (sub == 3) sigma = 50;
	if (sub == 4) sigma = 100;
	bool flg = sub == 2;
	if (!flg) {
		sigma -= n;
		rep (i, 1, n) {
			a[i] = rnd(0, sub != 1 ? sigma / 10 : sigma) + 1;
			sigma -= a[i] - 1;
		}
	}
	else {
		int r = rnd(1, sigma / n);
		rep (i, 1, n) a[i] = r;
	}
	int mx = 0;
	rep (i, 1, n) mx = max(mx, a[i]);
	int k = rnd(1, mx);
	cout << n << " " << k << endl;
	rep (i, 1, n) cout << a[i] << " ";
	cout << endl;
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
			if (i > taskDataNum[sub - 1]) { ++sub; continue; }
			if (sub > taskNum) break;
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
