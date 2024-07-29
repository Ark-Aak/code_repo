#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

const string stdFileName="std";//std可执行文件
const string probId="crisis";//题目Id

#include "lib/graph.hpp"

int ord[2000005];
//生成数据，x为数据编号
void Gen(int x){
	freopen("test.in","w",stdout);
	//输出到 stdout 即可
	const int n = 5, m = n - 2;
	rep (i, 1, n) ord[i] = i;
	shuffle(ord + 1, ord + 1 + n, _rnd);
	printf("%d %d\n", n, m);
	rep (i, 1, m) printf("%d%c", ord[i], " \n"[i == m]);
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
	/* } while (!system("spj test.in test.out test.ans")); */
	} while (!system("fc test.out test.ans /W"));
	cerr << "Wrong Answer" << endl;
}
