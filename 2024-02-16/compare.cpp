#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

const string stdFileName="std.exe";//std可执行文件
const string probId="post.exe";//题目Id

#include ".\lib\graph.hpp"

//生成数据，x为数据编号
void Gen(int x){
	freopen("test.in","w",stdout);
	//输出到 stdout 即可
	int n = 20, m = rnd(1, n), C = rnd(1, 1e9);
	printf("%d %d %d\n", n, m, C);
	vector <pair <int, int> > g = tree(n, 0, 0, 0);
	for (auto e : g) printf("%d %d %d\n", e.first, e.second, rnd(1, 1e9));
	rep (i, 1, m) printf("%d ", rnd(1, n));
}

int main(){
	//拼合管道命令，勿动
	int i = 1, Start, End;
	const double TimeLimit = 3;
	do {
		cerr << "Generating Data..." << endl;Gen(i);
		string command = stdFileName+" < test.in > test.ans";
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		double used = (double)(End - Start) / CLOCKS_PER_SEC;
		cerr << "Executing time: " << used << "sec" << endl;
		command = probId + " < test.in > test.out";
		cerr << "Executing command: " << command << endl;
		Start = clock();
		system(command.c_str());
		End = clock();
		used = (double)(End - Start) / CLOCKS_PER_SEC;
		cerr << "Executing time: " << used << "sec" << endl;
		if (used > TimeLimit) {
			cerr << "Time Limit Exceeded" << endl;
			break;
		}
		//if((double)(End - Start) / CLOCKS_PER_SEC > 2) break;
	} while (!system("fc test.out test.ans > nul"));
	cerr << "Wrong Answer" << endl;
}
