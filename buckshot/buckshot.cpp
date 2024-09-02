
#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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

void changeTextColor(int value) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, coord);
}

void HideCursor() {
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}

ll money = 0;
mt19937 rnd(time(0));

template <typename _Tp>
_Tp Rand(_Tp l, _Tp r) {
	uniform_int_distribution <_Tp> d(l, r);
	return d(rnd);
}

int damage = 1;
int totShots = 0, blts[2], damageMultiplier = 1;
const int cap = 8, bltCap = 8;
vector <bool> shots;

enum item {
	BEER,
	KNIFE,
	HANDCUFF,
	CIGARETTE,
	MAGNIFIER,
	EP,
	INVERSE,
	PHONE,
	EXPIERD
};

string name[20];
item item_list[] = { BEER, KNIFE, HANDCUFF, CIGARETTE, MAGNIFIER, EP, INVERSE, PHONE, EXPIERD };

item getRandomItem() {
	return item_list[Rand(0, 8)];
}

void renderMessage(string, int, int);
void clearMsg(int x, int y, int len = 30) {
	gotoxy(x, y);
	rep (i, 1, len) putchar(' ');
}

int maxHealth;

struct player {
	int health, id;
	vector <item> items;

	void heal(int val) { health = min(health + val, maxHealth); }
	void dmg(int val) { health = max(0, health - val); }

	bool shot() {
		if (shots.empty()) return 0;
		bool bullet = shots.front();
		shots.erase(shots.begin());
		if (bullet) {
			dmg(damage * damageMultiplier);
			renderMessage("实弹", 39, 14);
		}
		else renderMessage("空弹", 39, 14);
		Sleep(2000);
		clearMsg(39, 14);
		damageMultiplier = 1;
		health = max(health, 0);
		blts[bullet]--;
		return bullet;
	}

	void init(int id) {
		items.clear();
		health = maxHealth;
		this -> id = id;
	}

	bool alive() { return health > 0; }
} player0, player1;

void useItem(int, player*, player*, bool);

void generateShots() {
	totShots = Rand(2, bltCap);
	shots.clear();
	blts[0] = blts[1] = 0;
	while (blts[0] == 0 || blts[1] == 0) {
		shots.clear();
		blts[0] = blts[1] = 0;
		rep (i, 1, totShots) {
			bool bullet = Rand(0, 1);
			blts[bullet]++;
			shots.push_back(bullet);
		}
	}
}

int playMode = 1;
int turn = 0;

void render(player p, player opp, bool detail = false) {
	// Sidebar
	rep (i, 1, 30) {
		gotoxy(79, i - 1);
		putchar('|');
	}
	if (playMode == 1) {
		gotoxy(81, 0);
		if (turn == 0) printf("YOUR TURN  ");
		else printf("DEALER TURN");
	}
	else {
		gotoxy(81, 0);
		if (turn == 0) printf("P1 TURN");
		else printf("P2 TURN");
	}
	gotoxy(81, 2);
	printf("HP: %d/%d  CAP: %d/%d", p.health, maxHealth, (int) p.items.size(), cap);
	gotoxy(81, 4);
	printf("BLT: ");
	rep (i, 1, bltCap) putchar(' ');
	gotoxy(81, 4);
	printf("BLT: ");
	for (bool bullet : shots) {
		if (detail) {
			if (bullet) changeTextColor(COLOR_RED);
			else changeTextColor(COLOR_LIGHTBLUE);
		}
		putchar('#');
		changeTextColor(COLOR_WHITE);
	}
	gotoxy(81, 6);
	changeTextColor(COLOR_YELLOW);
	printf("My Items");
	changeTextColor(COLOR_WHITE);
	rep (i, 0, cap - 1) {
		gotoxy(81, 7 + i);
		printf("           ");
		gotoxy(81, 7 + i);
		if (i < (int) p.items.size()) printf("%d. %s", i + 1, name[p.items[i]].c_str());
		else printf("           ");
	}
	gotoxy(81, 16);
	changeTextColor(COLOR_YELLOW);
	printf("Dealer Items");
	changeTextColor(COLOR_WHITE);
	rep (i, 0, cap - 1) {
		gotoxy(81, 17 + i);
		printf("           ");
		gotoxy(81, 17 + i);
		if (i < (int) opp.items.size()) printf("%d. %s", i + 1, name[opp.items[i]].c_str());
		else printf("           ");
	}
	gotoxy(81, 27);
	printf("[J] 开枪");
	gotoxy(81, 28);
	printf("[U] 使用物品");
	// opp hp bar
	gotoxy(27, 1);
	putchar('/');
	rep (i, 1, 24 / maxHealth * opp.health) putchar('#');
	rep (i, 1, 24 - (24 / maxHealth * opp.health)) putchar(' ');
	putchar('\\');
	gotoxy(27, 2);
	putchar('\\');
	rep (i, 1, 24 / maxHealth * opp.health) putchar('#');
	rep (i, 1, 24 - (24 / maxHealth * opp.health)) putchar(' ');
	putchar('/');
	// my hp bar
	gotoxy(27, 25);
	putchar('/');
	rep (i, 1, 24 / maxHealth * p.health) putchar('#');
	rep (i, 1, 24 - (24 / maxHealth * p.health)) putchar(' ');
	putchar('\\');
	gotoxy(27, 26);
	putchar('\\');
	rep (i, 1, 24 / maxHealth * p.health) putchar('#');
	rep (i, 1, 24 - (24 / maxHealth * p.health)) putchar(' ');
	putchar('/');
	gotoxy(37, 28);
	changeTextColor(COLOR_LIGHTBLUE);
	printf("Bonus:");
	changeTextColor(COLOR_WHITE);
	gotoxy(30, 29);
	printf("%020lld", money);
}

bool cuffed[2];

struct AI {
	player *my;
	player *opp;
	vector <int> eps;
	int info[20];

	void init(player *_my, player *_opp) {
		my = _my, opp = _opp;
		memset(info, -1, sizeof info);
	}

	void loadEPs() {
		eps.clear();
		for (int i = 0; i < (int) my -> items.size(); i++) {
			item it = my -> items[i];
			if (it == item::EP) eps.push_back(i);
		}
	}

	void updateInfo(int x, bool stat) {
		const int ptr = totShots - shots.size() + 1;
		info[ptr + x - 1] = stat;
	}

	bool tryUseByEP(item itm) {
		loadEPs();
		if (eps.empty()) return false;
		for (int i = 0; i < (int) opp -> items.size(); i++) {
			item it = opp -> items[i];
			if (it == itm) {
				useItem(eps[0] + 1, my, opp, true);
				useItem(i + 1, my, opp, true);
				return true;
			}
		}
		return false;
	}

	int action() {
		const int ptr = totShots - shots.size() + 1;
		while (blts[0] > blts[1]) {
			bool flg = 0;
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::BEER) {
					flg = 1;
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
				}
			}
			if (!flg) break;
		}
		while (my -> health < maxHealth) {
			bool flg = 0;
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::CIGARETTE) {
					flg = 1;
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
				}
			}
			if (!flg) break;
		}
		while (my -> health < maxHealth) {
			if (my -> health <= 0) return -1;
			bool flg = 0;
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::EXPIERD) {
					flg = 1;
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
				}
			}
			if (!flg) break;
		}
		while (1) {
			bool flg = 0;
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::PHONE) {
					flg = 1;
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
				}
			}
			if (!flg) break;
		}
		while (tryUseByEP(item::PHONE)) render(*opp, *my);
		bool usedMag = info[ptr] != -1;
		bool self = usedMag ? !info[ptr] : blts[0] > blts[1];
		for (int i = 0; i < (int) my -> items.size() && blts[0] && blts[1]; i++) {
			item it = my -> items[i];
			if (it == item::MAGNIFIER && !usedMag) {
				useItem(i + 1, my, opp, true);
				self = !shots[0];
				usedMag = 1;
				render(*opp, *my);
				break;
			}
		}
		if (!usedMag) {
			if (tryUseByEP(item::MAGNIFIER)) {
				self = !shots[0];
				usedMag = 1;
				render(*opp, *my);
			}
		}
		if (blts[1] == 0 || (self && usedMag)) {
			bool usedInv = 0;
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::INVERSE) {
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
					self = !self;
					usedInv = 1;
					break;
				}
			}
			if (!usedInv) {
				if (tryUseByEP(item::INVERSE)) {
					render(*opp, *my);
					self = !self;
					usedInv = 1;
				}
			}
		}
		if (self) {
			renderMessage("庄家朝自己开枪了", 32, 14);
			Sleep(2000);
			clearMsg(32, 14);
			return my -> shot();
		}
		else {
			for (int i = 0; i < (int) my -> items.size(); i++) {
				item it = my -> items[i];
				if (it == item::KNIFE && damageMultiplier == 1) {
					useItem(i + 1, my, opp, true);
					render(*opp, *my);
					break;
				}
			}
			if (damageMultiplier == 1) {
				if (tryUseByEP(item::KNIFE)) render(*opp, *my);
			}
			if (blts[1] - 1 >= blts[0]) {
				for (int i = 0; i < (int) my -> items.size(); i++) {
					item it = my -> items[i];
					if (it == item::HANDCUFF && cuffed[opp -> id] == 0) {
						useItem(i + 1, my, opp, true);
						render(*opp, *my);
						break;
					}
				}
				if (cuffed[opp -> id] == 0) {
					if (tryUseByEP(item::HANDCUFF)) render(*opp, *my);
				}
			}
			renderMessage("庄家朝你开枪了", 33, 14);
			Sleep(2000);
			clearMsg(33, 14);
			return opp -> shot(), 1;
		}
	}
} ai;

void renderMessage(string msg, int x, int y) {
	gotoxy(x, y);
	printf("%s", msg.c_str());
}

char get() {
	const char res = getch();
	return res <= 'Z' ? res + 'a' - 'A' : res;
}

string numToCN(int x) {
	if (x == 0) return "零";
	if (x == 1) return "一";
	if (x == 2) return "二";
	if (x == 3) return "三";
	if (x == 4) return "四";
	if (x == 5) return "五";
	if (x == 6) return "六";
	if (x == 7) return "七";
	if (x == 8) return "八";
	if (x == 9) return "九";
	return "";
}

bool EPflg = 0;

void useItem(int id, player *my, player *opp, bool dealer) {
	const item itm = EPflg ? opp -> items[id - 1] : my -> items[id - 1];
	bool bullet = shots.front();
	switch (itm) {
		case item::KNIFE:
			if (dealer) {
				renderMessage("对家用了手锯", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
			}
			if (damageMultiplier == 2) {
				renderMessage("你不能这么做", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
				return;
			}
			damageMultiplier *= 2;
			break;
		case item::BEER:
			if (bullet) {
				renderMessage("退出了一发实弹", 33, 14);
				blts[1]--;
			}
			else {
				renderMessage("退出了一发空弹", 33, 14);
				blts[0]--;
			}
			shots.erase(shots.begin());
			Sleep(2000);
			clearMsg(33, 14);
			break;
		case item::HANDCUFF:
			if (cuffed[opp -> id]) {
				renderMessage("你不能这么做", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
				return;
			}
			cuffed[opp -> id] = 1;
			if (!dealer) renderMessage("对家被铐上了", 34, 14);
			else renderMessage("你被铐上了", 34, 14);
			Sleep(2000);
			clearMsg(34, 14);
			break;
		case item::CIGARETTE:
			if (dealer) {
				renderMessage("对家治疗成功", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
			}
			my -> heal(1);
			break;
		case item::EP:
			if (EPflg || (int) opp -> items.size() < 1) {
				renderMessage("你不能这么做", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
				return;
			}
			EPflg = 1;
			my -> items.erase(next(my -> items.begin(), id - 1));
			if (dealer) {
				renderMessage("对家用了肾上腺素", 32, 14);
				Sleep(2000);
				clearMsg(32, 14);
			}
			return;
			break;
		case item::EXPIERD:
			if (Rand(0, 1)) {
				if (!dealer) renderMessage("治疗成功", 36, 14);
				else renderMessage("对家治疗成功", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
				my -> heal(2);
			}
			else {
				if (!dealer) renderMessage("治疗失败", 36, 14);
				else renderMessage("对家治疗失败", 34, 14);
				Sleep(2000);
				clearMsg(34, 14);
				my -> dmg(1);
			}
			break;
		case item::INVERSE:
			shots[0] = !shots[0];
			blts[shots[0]]++;
			blts[!shots[0]]--;
			bullet = !bullet;
			if (dealer) {
				renderMessage("对家用了逆转器", 33, 14);
				Sleep(2000);
				clearMsg(33, 14);
			}
			break;
		case item::MAGNIFIER:
			if (bullet) {
				if (!dealer) renderMessage("你看到了实弹", 34, 14);
				else renderMessage("对家用了放大镜", 32, 14);
				Sleep(2000);
				clearMsg(32, 14);
			}
			else {
				if (!dealer) renderMessage("你看到了空弹", 34, 14);
				else renderMessage("对家用了放大镜", 32, 14);
				Sleep(2000);
				clearMsg(32, 14);
			}
			break;
		case item::PHONE:
			const int rd = Rand(1, (int) shots.size());
			string res = "第" + numToCN(rd) + "发子弹是" + (shots[rd - 1] ? "实" : "空") + "弹";
			if (!dealer) renderMessage(res, 33, 14);
			else renderMessage("对家用了手机", 34, 14), ai.updateInfo(rd, shots[rd - 1]);
			Sleep(2000);
			clearMsg(33, 14);
			break;
	}
	if (!EPflg) my -> items.erase(next(my -> items.begin(), id - 1));
	else opp -> items.erase(next(opp -> items.begin(), id - 1)), EPflg = 0;
}

int actionLogic(player *my, player *opp) {
	render(*my, *opp);
	fflush(stdin);
	const char op = get();
	if (op == 'u') {
		if ((EPflg ? ((int) opp -> items.size()) : ((int) my -> items.size())) < 1) {
			renderMessage("你不能这么做", 34, 14);
			Sleep(2000);
			clearMsg(34, 14);
			return -1;
		}
		renderMessage("使用物品的编号（输入零退出）？", 26, 14);
		fflush(stdin);
		int id;
		cin >> id;
		while (id < 0 || id > (EPflg ? ((int) opp -> items.size()) : ((int) my -> items.size()))) {
			renderMessage("你不能这么做", 34, 15);
			Sleep(2000);
			clearMsg(34, 15);
			cin >> id;
		}
		clearMsg(26, 14, 32);
		if (id > 0) useItem(id, my, opp, false);
		return -1;
	}
	if (op == 'j') {
		if (EPflg) {
			renderMessage("你不能这么做", 34, 14);
			Sleep(2000);
			clearMsg(34, 14);
			return -1;
		}
		renderMessage("射击？", 37, 14);
		renderMessage("[J] 自己  [K] 对家  [Q] 取消", 26, 15);
		fflush(stdin);
		char obj = get();
		while (obj != 'j' && obj != 'k' && obj != 'q') {
			obj = get();
		}
		clearMsg(37, 14);
		clearMsg(26, 15);
		if (obj == 'k') {
			opp -> shot();
			return 1;
		}
		else if (obj == 'q') return -1;
		else {
			return my -> shot();
		}
	}
	return -1;
}

// Dealer -> player1

int takeAction() {
	if (turn == 0) return actionLogic(&player0, &player1);
	if (playMode == 1) {
		render(player0, player1);
		Sleep(2000);
		const int res = ai.action();
		return res;
	}
	else return actionLogic(&player1, &player0);
}

void pickItems() {
	int num = Rand(2, 5);
	rep (i, 1, num) {
		if (player0.items.size() < cap) player0.items.push_back(getRandomItem());
		if (player1.items.size() < cap) player1.items.push_back(getRandomItem());
	}
}

void refill() {
	cuffed[0] = cuffed[1] = 0;
	EPflg = 0;
	generateShots();
	pickItems();
	render(player0, player1, true);
	renderMessage("子弹正显示在右上角，现在不要按键", 24, 14);
	// Show bullets
	Sleep(3000);
	clearMsg(24, 14, 40);
	shuffle(shots.begin(), shots.end(), rnd);
	if (playMode == 1) money += Rand(1, 100);
	render(player0, player1);
}

void mainLogic() {
	while (player0.alive() && player1.alive()) {
		if (shots.empty()) refill(), turn = 0;
		if (takeAction() == 1) turn ^= 1;
		if (cuffed[turn]) turn ^= 1, cuffed[turn ^ 1] = 0;
	}
	if (playMode == 1) render(player0, player1);
	else if (turn == 0) {
		// 反的
		render(player1, player0);
	}
	else render(player0, player1);
	if (player0.alive()) {
		if (playMode == 1) renderMessage("你赢了", 37, 14), money = money * 1.2;
		else renderMessage("P1赢了", 37, 14);
		Sleep(2000);
		clearMsg(37, 14);
	}
	else {
		if (playMode == 1) renderMessage("你输了", 37, 14), money = 0;
		else renderMessage("P2赢了", 37, 14);
		Sleep(2000);
		clearMsg(37, 14);
	}
}

void init() {
	turn = 0;
	shots.clear();
	maxHealth = Rand(2, 4);
	player0.init(0), player1.init(1);
	if (playMode == 1) ai.init(&player1, &player0);
	mainLogic();
}

signed main() {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	HideCursor();
	system("title Buckshot (by Federico2903)");
	name[item::BEER] = "啤酒";
	name[item::KNIFE] = "手锯";
	name[item::HANDCUFF] = "手铐";
	name[item::CIGARETTE] = "香烟";
	name[item::MAGNIFIER] = "放大镜";
	name[item::EP] = "肾上腺素";
	name[item::INVERSE] = "逆转器";
	name[item::PHONE] = "手机";
	name[item::EXPIERD] = "过期药片";
	system("mode con cols=100 lines=30");
	renderMessage("Buckshot (by luogu Federico2903)", 32, 8);
	renderMessage("游戏类型？", 37, 13);
	renderMessage("[1] 单人游戏（对战 AI）", 37, 14);
	renderMessage("[2] 双人游戏（PVP Beta）", 37, 15);
	char op = getch();
	while (op != '1' && op != '2') op = getch();
	playMode = op - '0';
	while (1) {
		system("cls");
		init();
		// Double or nothing
	}
	return 0;
}
