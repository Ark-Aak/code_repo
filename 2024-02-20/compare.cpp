#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

const string probId="test.exe";//题目Id

//生成数据，x为数据编号
void Gen(int x){
	freopen("test.in","w",stdout);
	//输出到 stdout 即可
	int n = 3;
	cout << n << endl;
	rep(i, 1, 2 * n - 1) {
		cout << rnd(0, n - 1) << " ";
	}
}

int main(){
	//拼合管道命令，勿动
	int i = 1, Start, End;
	const double TimeLimit = 3;
	do {
		cerr << "Generating Data..." << endl;Gen(i);
		string command = probId + " < test.in > test.out";
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
	} while (!system("chk test.in test.out test.out"));
	cerr << "Wrong Answer" << endl;
}
