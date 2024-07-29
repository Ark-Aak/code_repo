#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std_t6";//std文件名
const string probId="data";//题目Id
const int dataNum = 0;//数据组数
const int taskNum = 7;
const int taskDataNum[] = {5, 3, 2, 4, 5, 4, 6};
// 输入输出数据形如data_1-1.in/data_1-1.out

/* #define __OPTION_NO_REDIRECT */

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

#include "lib/graph.hpp"

//生成数据，x为数据编号
void Gen(int x, int sub){
	ignore = freopen(getInName(x, sub).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n = 0, m = 0, chain = 0, ring = 0;
	if (sub == 1) n = rnd(5, 10), m = rnd(n - 1, 10);
	if (sub == 2) n = rnd(400, 500), m = n - 1, chain = 1;
	if (sub == 3) n = rnd(4.9e5, 5e5), m = n, ring = 1;
	if (sub == 4) n = rnd(400, 500), m = rnd(n - 1, 500);
	if (sub == 5) n = rnd(4.9e5, 5e5), m = n - 1, chain = 1;
	if (sub == 6) n = rnd((x & 1) ? 4.999e5 : 4e5, 5e5), m = rnd(n - 1, 5e5);
	int S, T;
	if (sub <= 6) {
		S = rnd(1, n);
		T = rnd(1, n);
		while (S == T) T = rnd(1, n);
		printf("%d %d %d %d\n", n, m, S, T);
	}
	if (ring) {
		rep (i, 1, n - 1) printf("%d %d\n", i, i + 1);
		printf("%d 1\n", n);
		return;
	}
	if (chain) {
		rep (i, 1, n - 1) printf("%d %d\n", i, i + 1);
		return;
	}
	vector <pair <int, int> > graph;
	if (sub <= 6) graph = DAG(n, m);
	else {
		if (x & 1) {
			int center = 1;
			int l = 2, r = 3, u = 4, d = 5;
			n = 5;
			const int N = rnd(3e5, 4e5);
			const int M = N - 1;
			graph.push_back(make_pair(center, l));
			graph.push_back(make_pair(center, r));
			graph.push_back(make_pair(center, u));
			graph.push_back(make_pair(center, d));
			while (n < N) {
				n++;
				const int _r = rnd(1, 4);
				if (_r == 1) {
					graph.push_back(make_pair(l, n));
					l = n;
				}
				if (_r == 2) {
					graph.push_back(make_pair(r, n));
					r = n;
				}
				if (_r == 3) {
					graph.push_back(make_pair(u, n));
					u = n;
				}
				if (_r == 4) {
					graph.push_back(make_pair(d, n));
					d = n;
				}
			}
			if (rnd(0, 1)) S = l, T = r;
			else S = u, T = d;
			if (rnd(0, 1)) swap(S, T);
			printf("%d %d %d %d\n", N, M, S, T);
		}
		else {
			int l = 1, r = 2, u = 3, d = 4;
			n = 4;
			const int N = rnd(3e5, 4e5);
			const int M = N;
			graph.push_back(make_pair(l, u));
			graph.push_back(make_pair(u, r));
			graph.push_back(make_pair(r, d));
			graph.push_back(make_pair(d, l));
			while (n < N) {
				n++;
				const int _r = rnd(1, 4);
				if (_r == 1) {
					graph.push_back(make_pair(l, n));
					l = n;
				}
				if (_r == 2) {
					graph.push_back(make_pair(r, n));
					r = n;
				}
				if (_r == 3) {
					graph.push_back(make_pair(u, n));
					u = n;
				}
				if (_r == 4) {
					graph.push_back(make_pair(d, n));
					d = n;
				}
			}
			if (rnd(0, 1)) S = l, T = r;
			else S = u, T = d;
			if (rnd(0, 1)) swap(S, T);
			printf("%d %d %d %d\n", N, M, S, T);
		}
	}
	for (auto [u, v] : graph) printf("%d %d\n", u, v);
}

signed main(){
	//拼合管道命令，勿动
	ignore = system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17").c_str());
	ignore = system("mkdir data");
	int i = 1, sub = 1, Start, End;
	while(1){
		string command;
		if (taskNum == 0) {
			cerr << "Generating Data " << i << endl; Gen(i, 0);
#ifdef __OPTION_NO_REDIRECT
			command = "ulimit -s unlimited && ./" + stdFileName + " " + getInName(i, 0) + " " + getOutName(i, 0);
#else
			command = "ulimit -s unlimited && ./" + stdFileName + " < " + getInName(i, 0) + " > " + getOutName(i, 0);
#endif
		}
		else {
			cerr << "Generating Data task " << sub << " data " << i << endl; Gen(i, sub);
#ifdef __OPTION_NO_REDIRECT
			command = "ulimit -s unlimited && ./" + stdFileName + " " + getInName(i, sub) + " " + getOutName(i, sub);
#else
			command = "ulimit -s unlimited && ./" + stdFileName + " < " + getInName(i, sub) + " > " + getOutName(i, sub);
#endif
		}
		cerr << "Executing command: " << command << endl;
		Start = clock();
		ignore = system(command.c_str());
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
