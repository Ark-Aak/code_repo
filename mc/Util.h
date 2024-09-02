#include <windows.h>
mutex goto_lock,color_lock,check_lock,print_lock,print2_lock;
void GoToxy(int,int);
void Print(char c){
    print2_lock.lock();
    putchar(c);
    print2_lock.unlock();
}//输出单个字符
void Print(string str){
    print_lock.lock();
    for(int i=0;i<str.length();i++){
        putchar(str[i]);
    }
    print_lock.unlock();
}//输出string
void cls(){
    GoToxy(0,0);//局部刷新
}//清屏
void cls_DH(){
    for(int i=0;i<35;i++){
        for(int j=0;j<100;j++){
            GoToxy(i,j);
            Print(' ');
        }
    }
    GoToxy(0,0);
}//动画清屏
void cls_Clean(){
    system("cls");
}//默认清屏（闪屏）
void ChangeTextColor(int value){
    color_lock.lock();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),value);
    color_lock.unlock();
}//更换文字颜色
void GoToxy(int x,int y){
    goto_lock.lock();
    COORD coord;
    coord.X=x;
    coord.Y=y;
    HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,coord);
    goto_lock.unlock();
}//更改输出位置
Item mpItem[MAP_SIZE][MAP_SIZE];//地图上的物品
bool CheckRecipe(int res[][3],int check[][3]){
    check_lock.lock();
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(res[i][j]!=check[i][j]){
                check_lock.unlock();
                return false;
            }
        }
    }
    check_lock.unlock();
    return true;//检查两个配方是否相同
}
long long int sti(string str){
	long long int res=0;
	for(int i=0;i<str.length();i++){
		res*=10;
		res+=int(str[i]-'0');
	}
	return res;
}
