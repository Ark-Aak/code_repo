#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

const string stdFileName="std.exe";//std可执行文件
const string probId="check.exe";//题目Id

#include ".\lib\graph.hpp"

//生成数据，x为数据编号
void Gen(int x){
	freopen("test.in","w",stdout);
	//输出到 stdout 即可
	int n = 5, m = 5, q = 1;
	printf("%d %d %d\n", n, m, q);
	vector <pair <int, int> > g = DAG(n, m);
	int mxt = 0;
	for (auto [u, v] : g) {
		int t = rnd(1, 10);
		int y = rnd(1, 5);
		mxt = max(mxt, t + y);
		int w = rnd(1, 10);
		printf("%d %d %d %d %d\n", t, y, u, v, w);
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

int main(){
	//拼合管道命令，勿动
	int i = 1, Start, End;
	const double TimeLimit = 3;
	do {
		cerr << "Generating Data..." << endl;Gen(i);
		string command = stdFileName+" < test.in > test.ans";
		cerr << "Executing command: " << command << endl;
		system(command.c_str());
		command = probId + " < test.in > test.out";
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		const double used = (double)(End - Start) / CLOCKS_PER_SEC;
		cerr << "Executing time: " << used << "sec" << endl;
		if (used > TimeLimit) {
			cerr << "Time Limit Exceeded" << endl;
			break;
		}
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
	} while (!system("fc test.out test.ans > nul"));
	cerr << "Wrong Answer" << endl;
}
