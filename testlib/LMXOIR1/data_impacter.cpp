#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="impacter";//std文件名
const string probId="data";//题目Id
const int dataNum=40;//数据组数
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

#include "./lib/graph.hpp"

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n, q, dmax, chain, tn;
	if (x <= 5) {
		n = 10, q = 10, dmax = 10, chain = 0, tn = 0;
	}
	else if (x <= 10) {
		n = 1000, q = 1000, dmax = 10, chain = 0, tn = 0;
	}
	else if (x <= 15) {
		n = 1e5, q = 1e4, dmax = 3, chain = 1, tn = 0;
	}
	else if (x <= 20) {
		n = 1e5, q = 1e4, dmax = 3, chain = 0, tn = 0;
		if (x >= 18) tn = 0.75 * n;
	}
	else if (x <= 30) {
		n = 1e5, q = 1e4, dmax = 10, chain = 1, tn = 0;
	}
	else {
		n = 1e5, q = 1e4, dmax = 10, chain = 0, tn = 0;
		if (x >= 36) tn = 0.75 * n;
	}
	printf("%lld\n", n);
	rep (i, 1, n) {
		printf("%d", rnd(1, dmax));
		if (i == n) putchar(10);
		else putchar(32);
	}
	vector <pair <int, int> > edges = tree(n, chain, false, tn);
	for (auto v : edges) {
		printf("%lld %lld\n", v.first, v.second);
	}
	printf("%lld\n", q);
	rep (i, 1, q) {
		int u = rnd(1, n), v = rnd(1, n);
		while (u == v) v = rnd(1, n);
		int t = rnd(1, n);
		int x = rnd(1, dmax);
		printf("%lld %lld %lld %lld\n", t, x, u, v);
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17 -Wl,--stack=51200000000").c_str());
	system("@mkdir data > nul");
	int i = 1, Start, End;
	while(1){
		cerr << "Generating Data " << i << endl; Gen(i);
#ifdef __OPTION_NO_REDIRECT
		string command = stdFileName + " " + getInName(i) + " " + getOutName(i);
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