#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="planner";//std文件名
const string probId="data";//题目Id
const int dataNum=24;//数据组数
//输入输出数据形如data_1.in/data_1.out

#define __OPTION_NO_REDIRECT

//拼合输入文件名，勿动
string getInName(int x){
	stringstream name;
	name << "data/" << probId << "_" << x << ".in";
	return name.str();
}

//拼合输入文件名，勿动
string getOutName(int x){
	stringstream name;
	name << "data/" << probId << "_" << x << ".out";
	return name.str();
}

mt19937_64 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

#include ".\lib\graph.hpp"

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n, m, q, mnV, mxV, flg1 = 0, flg2 = 0, sp = 0;
	double x1 = 0.9, x2 = 1;
	if (x <= 2) {
		n = 5, m = 5, q = 5, mnV = 1, mxV = 1e5, sp = 4000;
		x1 = 0.6, x2 = 0.7;
	}
	else if (x <= 5) {
		n = 100, m = 100, q = 100, mnV = 1, mxV = 1e5, sp = 11000;
		x1 = 0.6, x2 = 0.7;
	}
	else if (x <= 7) {
		n = 1e3, m = 1e3, q = 1e3, mnV = 1, mxV = 1e5, sp = 14000;
		flg1 = flg2 = 1;
		x1 = 0.6, x2 = 0.7;
	}
	else if (x <= 10) {
		n = 7e4, m = 7e4, q = 1e5, mnV = 1, mxV = 1e5, sp = 21000;
		flg2 = 1;
		if (x > 9) x1 = 0.6, x2 = 0.7;
	}
	else if (x <= 13) {
		n = 7e4, m = 7e4, q = 1e5, mnV = 1, mxV = 1e5, sp = 30000;
		flg1 = 1;
		if (x > 12) x1 = 0.6, x2 = 0.7;
	}
	else {
		n = 7e4, m = 7e4, q = 1e5, mnV = 1, mxV = 1e5, sp = 37000;
		if (x > 18) x1 = 0.2, x2 = 0.3;
		else if (x > 16) x1 = 0.6, x2 = 0.7;
	}
	n = n == 5 ? 5 : rnd(x1 * n, x2 * n); m = min(m, n * (n - 1) / 2);
	cerr << "range: " << n << " " << m << " " << q << endl;
	printf("%d %d %d\n", n, m, q);
	vector <pair <int, int> > g = graph_uncon_undir(n, m);
	int mxt = 0;
	for (auto [u, v] : g) {
		int t = flg1 ? mnV : rnd(mnV, mxV);
		int y = flg2 ? mxV : rnd(mnV, mxV);
		while (t == y || abs(t - y) <= sp) y = rnd(mnV, mxV);
		if (t > y) swap(t, y);
		mxt = max(mxt, y);
		assert(mnV <= y && y <= mxV);
		int w = rnd(mnV, mxV);
		printf("%d %d %d %d %d\n", t, y - t, u, v, w);
	}
	rep (i, 1, q) {
		int x, s, t;
		x = rnd(1, mxt);
		s = rnd(1, n);
		t = rnd(1, n);
		while (s == t) t = rnd(1, n);
		printf("%d %d %d\n", x, s, t);
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -std=c++17").c_str());
	system("mkdir data > nul");
	int i = 1, Start, End;
	while(1){
		cerr << "Generating Data " << i << endl; Gen(i);
#ifdef __OPTION_NO_REDIRECT
		string command = stdFileName +" " + getInName(i) + " " + getOutName(i);
#else
		string command = stdFileName + " < " + getInName(i) + " > " + getOutName(i);
#endif
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		cerr << "Executing time: " << (double)(End - Start) / CLOCKS_PER_SEC << "sec" << endl;
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
		++i;
		if(i > dataNum) break;
	}
}