#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std";//std文件名
const string probId="data";//题目Id
const int dataNum = 0;//数据组数
const int taskNum = 6;
const int taskDataNum[] = {10, 10, 10, 10, 5, 10};
// 输入输出数据形如data_1-1.in/data_1-1.out

// #define __OPTION_NO_REDIRECT

//拼合输入文件名，勿动
string getInName(int x, int sub){
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".in";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".in";
}

//拼合输入文件名，勿动
string getOutName(int x, int sub){
	if (sub == 0) return "data/" + probId + "_" + to_string(x) + ".out";
	else return "data/" + probId + "_" + to_string(sub) + "-" + to_string(x) + ".out";
}

mt19937_64 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

#include "./lib/graph.hpp"

int siz[1000005];

//生成数据，x为数据编号
void Gen(int x, int sub){
	freopen(getInName(x, sub).c_str(),"wb",stdout);
	//输出到 stdout 即可
	memset(siz, 0, sizeof siz);
	int n, m, flo = 0, random = 0, l0 = 0, ttp = 0;
	n = rnd(2.5e5, 3e5), m = rnd(2.5e5, 3e5);
	if (sub == 1) {
		n = rnd(900, 1000), m = rnd(900, 1000);
	}
	else if (sub == 2) {
		l0 = 1;
	}
	else if (sub == 3) {
		random = 1;
	}
	else if (sub == 4) {
		ttp = 1;
	}
	else if (sub == 5) {
		flo = 1;
	}
	bool flower = flo || ((random || x != 1) ? 0 : 1);
	vector <pair <int, int> > g;
	if (random) g = tree(n, 0, 0, 0);
	else if (x <= 5 || sub == 1) g = tree(n, 0, flower, ((x >= 4 || random) ? 0 : 0.75 * n));
	else {
		vector <pair <int, int> > flw = tree(n * 0.1, 0, 1, 0);
		rep (i, 1, 10) {
			for (auto [u, v] : flw) {
				g.push_back({u + (i - 1) * (n / 10), v + (i - 1) * (n / 10)});
			}
			if (i < 10) g.push_back({(i - 1) * (n / 10) + 1, i * (n / 10) + 1});
		}
		rep (i, (flw.size() + 1) * 10 + 1, n) {
			int u = rnd(1, i - 1);
			g.push_back({u, i});
		}
		cerr << g.size() << " " << n - 1 << endl;
		assert(g.size() == n - 1);
	}
	printf("%lld %lld\n", n, m);
	rep (i, 1, n) printf("%lld ", rnd(1, 2000));
	printf("\n");
	for (auto [u, v] : g) {
		siz[u]++, siz[v]++;
		printf("%lld %lld\n", u, v);
	}
	rep (i, 1, m) {
		int tp = rnd(1, 3 - ttp);
		printf("%lld ", tp);
		if (tp == 1) {
			int x = rnd(1, n), y = rnd(1, n);
			int val = rnd(1, 2000);
			printf("%lld %lld %lld\n", x, y, val);
		}
		else {
			int x, y;
			if (flower && rnd(1, 3) <= 2) x = 1;
			else if (x > 5 && rnd(1, 10) <= 9) x = min(n, rnd(0, 10) * (n / 10) + 1);
			else x = rnd(1, n);
			y = rnd(1, siz[x] + 1);
			int l = 1 - l0;
			printf("%lld %lld %lld\n", x, y, l);
		}
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17 -Wl,--stack=51200000000").c_str());
	system("mkdir data > nul");
	int i = 1, sub = 1, Start, End;
	while(1){
		string command;
		if (taskNum == 0) {
			cerr << "Generating Data " << i << endl; Gen(i, 0);
#ifdef __OPTION_NO_REDIRECT
			command = stdFileName + " " + getInName(i, 0) + " " + getOutName(i, 0);
#else
			command = stdFileName + " < " + getInName(i, 0) + " > " + getOutName(i, 0);
#endif
		}
		else {
			cerr << "Generating Data task " << sub << " data " << i << endl; Gen(i, sub);
#ifdef __OPTION_NO_REDIRECT
			command = stdFileName + " " + getInName(i, sub) + " " + getOutName(i, sub);
#else
			command = stdFileName + " < " + getInName(i, sub) + " > " + getOutName(i, sub);
#endif
		}
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		cerr << "Executing time: " << (double)(End - Start) / CLOCKS_PER_SEC << "sec" << endl;
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
		++i;
		if (taskNum > 0) {
			if (i > taskDataNum[sub - 1]) {
				i = 1;
				++sub;
				if (sub > taskNum) break;
			}
		}
		else if(i > dataNum) break;
	}
}
