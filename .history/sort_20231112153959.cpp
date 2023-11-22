#include <bits/stdc++.h>
#include <windows.h>

typedef long long int ll;
typedef unsigned long long int ull;
typedef std::pair<int,int> pii;
typedef std::vector<int> vec;

using namespace std;

#define __rep(i,a,b,c) for(int i=(a);i!=(b);i+=(c))
#define _rep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define COLOR_BLACK 0
#define COLOR_DARKBLUE 1
#define COLOR_DARKGREEN 2
#define COLOR_DARKBLUEGREEN 3
#define COLOR_DARKRED 4
#define COLOR_PURPLE 5
#define COLOR_DARKYELLOW 6
#define COLOR_WHITE 7
#define COLOR_GRAY 8
#define COLOR_LIGHTBLUE 9
#define COLOR_LIGHTGREEN 10
#define COLOR_LIGHTBLUEGREEN 11
#define COLOR_RED 12
#define COLOR_PINK 13
#define COLOR_YELLOW 14
#define COLOR_LIGHTWHITE 15
#define COLOR_BG 16

mt19937 rnd(time(0));
int Rand(int l,int r){return abs((int)rnd())%(r-l+1)+l;}

void print(char c){
	putchar(c);
}

void print(string str){
	rep(i, 1, (int) str.length() - 1){
		putchar(str[i]);
	}
}

void GoToxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}

void cls(){
	GoToxy(0, 0);
}

void hideCursor(){
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = FALSE;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void changeTextColor(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

int MAXN = 200, MAXM = 20;

vector<int> num(MAXN + 5, 0), sorted(MAXN + 5, 0);
int sel[10];

void init(){
	hideCursor();
	auto func = []()->string{
		stringstream ss;
		ss << "mode con cols=" << max(15, MAXN) << " lines=" << max(15, MAXM + 1);
		return ss.str();
	};
	system(func().c_str());
}

void rnd_arr(){
	num.resize(MAXN);
	sorted.resize(MAXN);
	rep(i, 1, MAXN){
		num[i] = Rand(1, MAXM);
	}
	copy(num.begin() + 1, num.begin() + 1 + MAXN, sorted.begin() + 1);
	sort(sorted.begin() + 1, sorted.begin() + 1 + MAXN);
}

void sorted_arr(){
	num.resize(MAXN);
	sorted.resize(MAXN);
	rep(i, 1, MAXN){
		num[i] = Rand(1, MAXM);
	}
	sort(num.begin() + 1, num.begin() + 1 + MAXN);
	copy(num.begin() + 1, num.begin() + 1 + MAXN, sorted.begin() + 1);
}

void reversed_arr(){
	num.resize(MAXN);
	sorted.resize(MAXN);
	rep(i, 1, MAXN){
		num[i] = Rand(1, MAXM);
	}
	sort(num.begin() + 1, num.begin() + 1 + MAXN);
	copy(num.begin() + 1, num.begin() + 1 + MAXN, sorted.begin() + 1);
	reverse(num.begin() + 1, num.begin() + 1 + MAXN);
}

void select_bogo(){
	sel[0] = Rand(1, MAXN);
	//do{
		//sel[1] = Rand(sel[0], MAXN);
	sel[1] = Rand(1, MAXN);
	//}
	//while((sel[1] == sel[0] && sel[0] != MAXN));
}

void select_betterbogo(){
	sel[0] = Rand(1, MAXN);
	do{
		sel[1] = Rand(sel[0], MAXN);
	//sel[1] = Rand(1, MAXN);
	}
	while((sel[1] == sel[0] && sel[0] != MAXN));
}

const int FPS = 60;

bool flg = 1;
pair <int, int> rd[55][205][2];
int fcnt;

void update(int x, int y, pair <int, int> val) {
	GoToxy(y - 1, MAXM - x);
	changeTextColor(val.second);
	print(val.first);
	changeTextColor(COLOR_WHITE);
}

void render(){
	fcnt ^= 1;
	_rep(__, MAXM, 1){
		rep(i, 1, MAXN){
			rd[__][i][fcnt] = rd[__][i][fcnt ^ 1];
			if(num[i] >= __){
				if(i == sel[0]){
					pair <int, int> tmp = make_pair(' ', COLOR_LIGHTBLUE * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
				else if(i == sel[1]){
					pair <int, int> tmp = make_pair(' ', COLOR_PINK * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
				else if(i == sel[2]){
					pair <int, int> tmp = make_pair(' ', COLOR_RED * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
				else if(i == sel[3]){
					pair <int, int> tmp = make_pair(' ', COLOR_YELLOW * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
				else if(sorted[i] == num[i]){
					pair <int, int> tmp = make_pair(' ', COLOR_LIGHTGREEN * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
				else{
					pair <int, int> tmp = make_pair(' ', COLOR_WHITE * COLOR_BG);
					if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
					rd[__][i][fcnt] = tmp;
				}
			}
			else{
				pair <int, int> tmp = make_pair(' ', COLOR_WHITE);
				if (tmp != rd[__][i][fcnt]) update(__, i, tmp);
				rd[__][i][fcnt] = tmp;
			}
		}
	}
	Sleep(1000 / FPS);
}

void run_bogo(){
	do{
		//do{
			select_bogo();
		//}while(num[sel[0]] < num[sel[1]]);
		render();
		//Sleep(300);
		swap(num[sel[0]], num[sel[1]]);
		swap(sel[0], sel[1]);
		render();
		//Sleep(300);
		sel[0] = sel[1] = 0;
		render();
		//Sleep(300);
		flg = 1;
		rep(i, 1, MAXN){
			if(num[i] != sorted[i]){
				flg = 0;
				break;
			}
		}
	}while(!flg);
}

void run_betterbogo(){
	do{
		do{
			select_bogo();
		}while(num[sel[0]] < num[sel[1]]);
		render();
		//Sleep(300);
		swap(num[sel[0]], num[sel[1]]);
		swap(sel[0], sel[1]);
		render();
		//Sleep(300);
		sel[0] = sel[1] = 0;
		render();
		//Sleep(300);
		flg = 1;
		rep(i, 1, MAXN){
			if(num[i] != sorted[i]){
				flg = 0;
				break;
			}
		}
	}while(!flg);
}

void run_bubble(){
	rep(i, 1, MAXN){
		rep(j, i + 1, MAXN){
			sel[0] = i;
			sel[1] = j;
			render();
			if(num[i] > num[j]){
				//Sleep(300);
				swap(num[i], num[j]);
				//swap(sel[0], sel[1]);
				render();
				//Sleep(300);
				//sel[0] = sel[1] = 0;
				//render();
				//Sleep(300);
			}
		}
	}
	sel[0] = sel[1] = 0;
	render();
}

void run_selection(){
	int minId, minn = 1e9;
	rep(i, 1, MAXN){
		minn = num[i];
		minId = 1e9;
		sel[0] = i;
		rep(j, i + 1, MAXN){
			sel[1] = j;
			if(num[j] <= minn){
				minId = j;
				sel[2] = minId;
				minn = num[j];
			}
			render();
			//Sleep(300);
		}
		if(minId > 0 && minId <= MAXN) swap(num[i], num[minId]);
		swap(sel[2], sel[0]);
		sel[1] = 0;
		render();
		//Sleep(300);
	}
	sel[0] = sel[1] = sel[2] = 0;
	render();
}

void run_insertion(){
	rep(i, 1, MAXN){
		int key = num[i];
		sel[0] = i;
		int j = i - 1;
		while(j >= 0 && key < num[j]){
			sel[1] = j;
			render();
			num[j + 1] = num[j];
			j--;
			//Sleep(300);
		}
		num[j + 1] = key;
	}
	sel[0] = sel[1] = 0;
	render();
	//Sleep(300);
}

void quick(int l, int r){
	if (l < r){
		sel[0] = l; sel[1] = r;
		int i = l, j = r, x = num[l];
		sel[2] = i; sel[3] = j;
		render();
		while (i < j){
			while(i < j && num[j] >= x){
				j--;
				sel[3]--;
				render();
			}
			if(i < j){
				num[i] = num[j];
				i++;
				sel[2]++;
				render();
			}
			while(i < j && num[i] < x){
				i++;
				sel[2]++;
				render();
			}
			if(i < j){
				num[j] = num[i];
				j--;
				sel[3]--;
				render();
			}
		}
		num[i] = x;
		render();
		quick(l, i - 1);
		sel[0] = l; sel[1] = r;
		render();
		quick(i + 1, r);
		sel[0] = l; sel[1] = r;
		render();
	}
}

void run_quick(){
	quick(1, MAXN);
	sel[0] = sel[1] = sel[2] = sel[3] = 0;
	render();
}

void run_shell() {
	int i, j, d;
	d = MAXN / 2;
	while (d >= 1) {
		for (i = d + 1; i <= MAXN; i++) {
			num[0] = num[i];
			j = i - d;
			sel[0] = i;
			sel[1] = j;
			render();
			while ((j > 0) && num[0] < num[j]) {
				num[j + d] = num[j];
				j = j - d;
				sel[1] = j;
				render();
			}
			num[j + d] = num[0];
			render();
		}
		d = d / 2;
	}
	sel[0] = sel[1] = 0;
	render();
}

vector<int> temp(MAXN, 0);

void merge(int l, int r) {
	if (l >= r)return;
	int mid = (l + r) / 2, i, j, c = 0;
	sel[0] = l; sel[1] = r; sel[2] = sel[3] = 0;
	render(); 
	merge(l, mid);
	sel[0] = l; sel[1] = r; sel[2] = sel[3] = 0;
	render();
	merge(mid + 1, r);
	sel[0] = l; sel[1] = r; sel[2] = sel[3] = 0;
	render();
	i = l;
	j = mid + 1;
	sel[2] = i; sel[3] = j;
	render();
	while (i <= mid && j <= r) {
		if (num[i] < num[j])temp[++c] = num[i++];
		else temp[++c] = num[j++];
		sel[2] = i; sel[3] = j;
		render();
	}
	while (i <= mid){
		temp[++c] = num[i++];
		sel[2] = i; sel[3] = j;
		render();
	}
	while (j <= r){
		temp[++c] = num[j++];
		sel[2] = 0; sel[3] = j;
		render();
	}
	for (i = 1; i <= c; i++) {
		num[l++] = temp[i];
		sel[2] = l; sel[3] = 0;
		render();
	}
}

void run_merge(){
	merge(1, MAXN);
	sel[0] = sel[1] = sel[2] = sel[3] = 0;
	render();
}

void radixSort() {
	int n = num.size();
	int maxNum = *(max_element(num.begin(), num.end()));
	int numBit = 0;
	while (maxNum > 0) {
		maxNum /= 10;
		++numBit;
	}
	int radix = 1;
	for (int k = 1; k <= numBit; k++) {
		vector<vector<int>> bucket(10);
		for (int j = 0; j < n; j++) {
			int index = (num[j] / radix) % 10;     
			bucket[index].push_back(num[j]);
		}
		int resIndex=0;
		for (int i = 0; i < bucket.size(); i++) {
			if (bucket[i].empty()) {
				continue;
			}
			for (int j = 0; j < bucket[i].size(); j++) {
				num[resIndex++] = bucket[i][j];
			}
		}
		radix *= 10;
		render();
	}
	render();
}

signed main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
restart:
	system("cls");
	cls();
	do {
		cout << "输入你希望生成的数据个数 (30, 200) 和数据最大值 (5, 50): " << endl;
		cin >> MAXN >> MAXM;
		system("cls");
	} while(!(30 <= MAXN && MAXN <= 200 && 5 <= MAXM && MAXM <= 50));
	temp.resize(MAXN);
	cout << "输入你希望使用的数组模式: " << endl;
	cout << "1. 随机数组" << endl;
	cout << "2. 已排序数组" << endl;
	cout << "3. 倒序已排序数组" << endl;
	int mode; cin >> mode;
	system("cls");
	if(mode == 1)
		rnd_arr();
	else if(mode == 2)
		sorted_arr();
	else if(mode == 3)
		reversed_arr();
	else rnd_arr();
	do {
		cout << "输入你希望执行的算法: " << endl;
		cout << "1. 冒泡排序 (O(n^2 ~ n^2) 稳定)" << endl;
		cout << "2. 选择排序 (O(n^2 ~ n^2) 不稳定)" << endl;
		cout << "3. 插入排序 (O(n^2 ~ n^2) 稳定)" << endl;
		cout << "4. 希尔排序 (O(n^1.5 ~ n^1.5) 不稳定)" << endl;
		cout << "5. 快速排序 (O(nlogn ~ n^2) 不稳定)" << endl;
		cout << "6. 归并排序 (O(nlogn ~ nlogn) 稳定)" << endl;
		cout << "7. 猴子排序 (O(1 ~ inf) 不稳定)" << endl;
		cout << "8. 归并排序 (O(n ~ n) 稳定)" << endl;
		cin >> mode;
		system("cls");
	} while(mode < 1 || mode > 8);
	init();
	switch (mode) {
	case 1:
		run_bubble();
		break;
	case 2:
		run_selection();
		break;
	case 3:
		run_insertion();
		break;
	case 4:
		run_shell();
		break;
	case 5:
		run_quick();
		break;
	case 6:
		run_merge();
		break;
	case 7:
		run_bogo();
		break;
	case 8:
		radixSort();
		break;
	}
	system("pause");
	goto restart;
	return 0;
}