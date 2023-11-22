#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std.exe";//std可执行文件
const string probId="data";//题目Id
const int dataNum=50;//数据组数
//输入输出数据形如data_1.in/data_1.out

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

mt19937 _rnd(time(0));

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

pair <int, int> arr[1000005];

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"w",stdout);
	//输出到 stdout 即可
	int n, k;
	if (x <= 10) {
		n = rnd(9e4, 1e5);
		k = 0;
	}
	else if (x <= 20) {
		n = rnd(1, 10);
		k = rnd(1, 7);
	}
	else if (x <= 30) {
		n = rnd(900, 1000);
		k = rnd(5, 7);
	}
	else if (x <= 40) {
		n = rnd(1e5, 2e5);
		k = rnd(1e5, 2e5);
	}
	else {
		n = rnd(2e7, 3e7);
		k = rnd(2e7, 3e7);
	}
	printf("%d %d", n, k);
}

int main(){
	//拼合管道命令，勿动
	int i = 1, Start, End;
	while(1){
		cerr << "Generating Data " << i << endl;Gen(i);
		string command = stdFileName+" < " + getInName(i) + " > " + getOutName(i);
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

