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

int arr[1000005];

//生成数据，x为数据编号
void Gen(int x){
	freopen(getInName(x).c_str(),"w",stdout);
	//输出到 stdout 即可
	int n, maxd, q = rnd(9000, 10000);
	bool chain = 0, flower = 0;
	if (x <= 5) {
		maxd = 30, n = rnd(5, 10);
		if (x > 3) flower = 1;
	}
	else if (x <= 13) {
		maxd = 30, n = rnd(90, 100);
		if (x > 10) flower = 1;
	}
	else if (x <= 17) {
		maxd = 3, n = rnd(9e4, 1e5);
		chain = 1;
	}
	else if (x <= 30) {
		maxd = 3, n = rnd(9e4, 1e5);
		if (x > 25) flower = 1;
	}
	else if (x <= 40) {
		maxd = 30, n = rnd(4e4, 5e4);
		if (x > 34) flower = 1;
	}
	else {
		maxd = 30, n = rnd(9e4, 1e5);
		if (x > 45) flower = 1;
	}
	cout << n << '\n';
	rep (i, 1, n) {
		cout << rnd(1, maxd);
		if (i != n) cout << ' ';
		else cout << '\n';
	}
	rep (i, 1, n) arr[i] = i;
	if (flower) {
		rep (i, 2, n) cout << 1 << ' ' << i << '\n';
	}
	else if (!chain) {
		shuffle(arr + 1, arr + n + 1, _rnd);
		rep (i, 1, n - 1) cout << arr[i] << ' ' << arr[i + 1] << '\n';
	}
	else rep (i, 1, n - 1) cout << i << ' ' << i + 1 << '\n';
	cout << q << '\n';
	rep (i, 1, q) {
		int t = rnd(1, n), x = rnd(1, maxd), u, v;
		do {
			u = rnd(1, n), v = rnd(1, n);
		} while (u == v);
		cout << t << ' ' << x << ' ' << u << ' ' << v;
		if (i != q) cout << '\n';
	}
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

