#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std";//std文件名
const string probId="data";//题目Id
const int dataNum = 0;//数据组数
const int taskNum = 4;
const int taskDataNum[] = {10, 10, 10, 10};
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

//生成数据，x为数据编号
void Gen(int x, int sub){
	freopen(getInName(x, sub).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n, a = 1e9;
	if (sub == 1) n = rnd(10, 20);
	if (sub == 2) n = rnd(1900, 2000);
	if (sub == 3) n = rnd(999000, 1000000), a = 10;
	if (sub == 4) n = rnd(999000, 1000000);
	printf("%lld\n", n);
	rep (i, 1, n) printf("%lld ", rnd(-a, a));
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