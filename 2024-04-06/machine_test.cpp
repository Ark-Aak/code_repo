#include <bits/stdc++.h>
#include <windows.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
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


using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
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

const int MAXN = 705;
int n, m, Q, a[MAXN];
string s;

void render(string s, int pos) {
	cls();
	rep (i, 1, n) {
		if (s[i] == 'R') changeTextColor(16 * COLOR_RED + COLOR_WHITE);
		else changeTextColor(16 * COLOR_LIGHTBLUE + COLOR_WHITE);
		if (i != pos) putchar(32);
		else putchar('#');
	}
	changeTextColor(COLOR_WHITE);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("machine.in", "r", stdin);
	freopen("machine.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	hideCursor();
	cin >> n;
	cin >> s;
	s = ' ' + s;
	while (1) {
		system("cls");
		string str;
		str = s;
		int ps;
		cin >> ps;
		system("cls");
		str[ps] = 'R';
		render(str, ps);
		while (ps <= n && ps >= 1) {
			Sleep(300);
			if (str[ps] == 'R') {
				str[ps] = 'B';
				ps++;
			}
			else {
				str[ps] = 'R';
				ps--;
			}
			render(str, ps);
		}
		render(str, ps);
	}
	return 0;
}
