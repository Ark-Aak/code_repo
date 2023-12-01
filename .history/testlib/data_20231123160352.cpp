#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="std.exe";//std可执行文件
const string probId="data";//题目Id
const int dataNum=30;//数据组数
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
	int n, maxd, q = 100000;
	bool chain = 0, flower = 0;
	if (x <= 5) {
		q = 10000
		maxd = 10, n = rnd(5, 10);
	}
	else if (x <= 8) {
		q = 10000;
		maxd = 10, n = rnd(900, 1000);
	}
	else if (x <= 12) {
		maxd = 3, n = rnd(9e4, 1e5);
	}
	else if (x <= 18) {
		maxd = 3, n = rnd(9e4, 1e5);
	}
	else if (x <= 22) {
		maxd = 10, n = rnd(9e4, 1e5);
	}
	else {
		maxd = 10, n = rnd(4e5, 5e5);
	}
	cout << n << '\n';
	rep (i, 1, n) {
		cout << rnd(1, maxd);
		if (i != n) cout << ' ';
		else cout << '\n';
	}
	if (flower) {
		rep (i, 2, n) cout << 1 << ' ' << i << '\n';
	}
	else if (!chain) {
		int tn = floor(n / 4.0 * 3.0);
		rep (i, 1, tn) arr[i].first = i, arr[i].second = i + 1;
		rep (i, tn + 1, n - 1) arr[i].first = i + 1, arr[i].second = rnd(1, i);
		shuffle(arr + 1, arr + n, _rnd);
		rep (i, 1, n - 1) {
			cout << arr[i].first << " " << arr[i].second;
			cout << '\n';
		}
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


