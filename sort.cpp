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

void update(int srt){
	auto func = [=]()->string{
		stringstream ss;
		ss << "title Processing: " << srt << "/" << MAXN;
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

bool flg = 1;

void render(){
	//int cnt = 0;
	cls();
	_rep(__, MAXM, 1){
		rep(i, 1, MAXN){
			if(num[i] >= __){
				if(i == sel[0]){
					changeTextColor(COLOR_LIGHTBLUE * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
					//if(sorted[i] == num[i] && __ == 1) cnt++;
				}
				else if(i == sel[1]){
					changeTextColor(COLOR_PINK * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
					//if(sorted[i] == num[i] && __ == 1) cnt++;
				}
				else if(i == sel[2]){
					changeTextColor(COLOR_RED * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
					//if(sorted[i] == num[i] && __ == 1) cnt++;
				}
				else if(i == sel[3]){
					changeTextColor(COLOR_YELLOW * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
					//if(sorted[i] == num[i] && __ == 1) cnt++;
				}
				else if(sorted[i] == num[i]){
					changeTextColor(COLOR_LIGHTGREEN * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
					//if(__ == 1) cnt++;
				}
				else{
					changeTextColor(COLOR_WHITE * COLOR_BG);
					print(' ');
					changeTextColor(COLOR_WHITE);
				}
			}
			else{
				print(' ');
			}
		}
		print('\n');
	}
	//update(cnt);
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

signed main() {
	do{
		cout << "�1�7�1�7�0�5�0�0�1�7�1�7 �1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�7 v1.0 by Skyfire" << endl;
		cout << "�1�7�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�1�7�1�7�1�7�0�2�1�7�1�7�1�7�1�7�1�6�1�7�1�7�1�7 (30, 200) �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�0�5 (5, 50): " << endl;
		cin >> MAXN >> MAXM;
		system("cls");
	}while(!(30 <= MAXN && MAXN <= 200 && 5 <= MAXM && MAXM <= 50));
	temp.resize(MAXN);
	cout << "�1�7�1�7�0�5�0�0�1�7�1�7 �1�7�1�7�1�7�0�9�1�7�1�7�1�7�1�7�1�7 v1.0 by Skyfire" << endl;
	cout << "�1�7�1�7�1�7�1�7�1�7�1�7�0�5�1�7�1�7�0�0�1�7�0�1�1�7�1�7�1�7�1�7�1�7�0�0�0�4: " << endl;
	cout << "1. �1�7�1�7�1�7�1�7�1�7�1�7�1�7" << endl;
	cout << "2. �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7" << endl;
	cout << "3. �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7" << endl;
	int mode; cin >> mode;
	system("cls");
	if(mode == 1)
		rnd_arr();
	else if(mode == 2)
		sorted_arr();
	else if(mode == 3)
		reversed_arr();
	else rnd_arr();
	do{
		cout << "Select sort algorithm: " << endl;
		cout << "1. �0�8�1�7�1�7�1�7�1�7�1�7�1�7 (O(n^2 ~ n^2) �1�7�0�1�1�7)" << endl;
		cout << "2. �0�5�1�7�1�7�1�7�1�7�1�7�1�7 (O(n^2 ~ n^2) �1�7�1�7�1�7�0�1�1�7)" << endl;
		cout << "3. �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7 (O(n^2 ~ n^2) �1�7�0�1�1�7)" << endl;
		cout << "4. �0�5�1�7�1�7�1�7�1�7�1�7�1�7 (O(n^1.5 ~ n^1.5) �1�7�1�7�1�7�0�1�1�7)" << endl;
		cout << "5. �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7 (O(nlogn ~ n^2) �1�7�1�7�1�7�0�1�1�7)" << endl;
		cout << "6. �1�7��1�7�1�7�1�7�1�7 (O(nlogn ~ nlogn) �1�7�0�1�1�7)" << endl;
		cout << "7. �1�7�1�7�1�7�1�7�1�7�1�7�1�7�1�7 (O(1 ~ inf) �1�7�1�7�1�7�0�1�1�7)" << endl;
		cin >> mode;
		system("cls");
	}while(mode < 1 || mode > 7);
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
	}
	fflush(stdin);
	getchar();
	return 0;
}