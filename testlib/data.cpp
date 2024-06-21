#include <bits/stdc++.h>

using namespace std;

#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)

const string stdFileName="crisisstd";//std文件名
const string probId="data";//题目Id
const int dataNum = 0;//数据组数
const int taskNum = 7;
const int taskDataNum[] = {5, 5, 5, 5, 5, 10, 15};
// 输入输出数据形如data_1-1.in/data_1-1.out

#define __OPTION_NO_REDIRECT

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

mt19937_64 _rnd(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

int low[20] = { 0, 5, 10, 17, 7000, 7000, (int) 2.5e5, (int) 8.8e8 };
int hig[20] = { 0, 8, 15, 20, 8000, 8000, (int) 3e5, (int) 1e9 };
int ord[2000005];

//生成数据，x为数据编号
void Gen(int x, int sub){
	freopen(getInName(x, sub).c_str(),"wb",stdout);
	//输出到 stdout 即可
	int n = rnd(low[sub], hig[sub]);
	int m;
	const int maxm = 5e5;
	if (x % 3 == 0) {
		m = rnd(min(n, (int) maxm) * 0.9, min(n, (int) maxm));
	}
	else if (x % 3 == 1) {
		m = rnd(1, min(n, 5));
	}
	else {
		m = rnd(min(n, (int) maxm) * 0.4, min(n, (int) maxm) * 0.6);
	}
	int sp0 = sub == 4;
	printf("%d %d\n", n, m);
	if (n <= 2e6) {
		if (sp0) {
			rep (i, 1, m) printf("%d%c", i, " \n"[i == m]);
			return;
		}
		rep (i, 1, n) ord[i] = i;
		shuffle(ord + 1, ord + 1 + n, _rnd);
		rep (i, 1, m) printf("%d%c", ord[i], " \n"[i == m]);
	}
	else {
		set <int> s;
		while ((int) s.size() != m) s.insert(rnd(1, n));
		vector <int> v;
		for (auto val : s) v.push_back(val);
		shuffle(v.begin(), v.end(), _rnd);
		for (auto it = v.begin(); it != v.end(); it++) {
			printf("%d%c", *it, " \n"[it == prev(v.end())]);
		}
	}
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
