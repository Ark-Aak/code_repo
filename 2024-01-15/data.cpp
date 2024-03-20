#include <bits/stdc++.h>

using namespace std;

#define int long long

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="memory";//std文件名
const string probId="memory";//题目Id
const int dataNum=20;//数据组数
//输入输出数据形如data_1.in/data_1.out

//#define __OPTION_NO_REDIRECT

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

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n = 5e4, q = 5e4;
	cout << n << " " << q << endl;
	rep (i, 1, n) cout << (rnd(1, 1e9)) << " ";
	putchar(10);
	rep (i, 1, q) {
		int op = rnd(1, 2);
		if (op == 1) {
			cout << op << " " << rnd(1, 1e9) << endl;
		}
		else {
			int l = rnd(1, n), r = rnd(1, n);
			if (l > r) swap(l, r);
			cout << op << " " << l << " " << r << endl;
		}
	}
}

signed main(){
	//拼合管道命令，勿动
	system(("g++ " + stdFileName + ".cpp -o " + stdFileName + " -O2 -std=c++17 -Wl,--stack=51200000000").c_str());
	system("mkdir data > nul");
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
