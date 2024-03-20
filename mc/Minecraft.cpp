#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>

using namespace std;

#include "RegisterSign.h"

mutex render_lock,damage_lock;
thread Main,damageJudger;
SignManager signManager;

#include "RecipeCraft.h"
#include "command.h"
#include "signs.h"
#include "commandDefines.h"
#include "Player.h"
//玩家Player类
Player player;
void RenderMap(){//渲染地图
    render_lock.lock();
	cls();
	for(int i=renderXT;i<=renderXB;i++){
		for(int j=renderYL;j<=renderYR;j++){
			if(player.GetPlayerPos().x==i&&player.GetPlayerPos().y==j){
				ChangeTextColor(COLOR_RED);
				Print('@');//玩家位置
				ChangeTextColor(COLOR_WHITE);
			}
			else if(mp[i][j]==BLOCK_WOOD){
				ChangeTextColor(COLOR_DARKYELLOW);
				Print(mp[i][j]);//木头->棕色
				ChangeTextColor(COLOR_WHITE);
			}
			else if(mp[i][j]==LIQUID_LAVA){
				ChangeTextColor(COLOR_RED);
				Print(mp[i][j]);//岩浆->红色
				ChangeTextColor(COLOR_WHITE);
			}
			else{
				Print(mp[i][j]);
			}
		}
		Print('\n');
	}
	//渲染侧栏
    GoToxy(35,0);
    Print("                     ");
	GoToxy(35,1);
	stringstream ss;
	ss << "Pos:(" << player.GetPlayerPos().x << "," << player.GetPlayerPos().y << ")    " << endl;
	Print(ss.str());
    GoToxy(35,2);
    Print("                     ");
	GoToxy(35,3);
	ss.str("");
	ss << "Way:";
	switch(player.GetPlayerWay()){
		case WAY_LEFT:
			ss << "West ";
			break;
		case WAY_RIGHT:
			ss << "East ";
			break;
		case WAY_UP:
			ss << "North";
			break;
		case WAY_DOWN:
			ss << "South";
			break;
	};
	ss  << endl;
	Print(ss.str());
    GoToxy(35,4);
    Print("                     ");
	string temp="Hand:"+IdToName(player.GetPlayerHandheld());
	while(temp.length()<20){
		temp+=' ';//补齐20长度
	}
	GoToxy(35,5);
	Print(temp);
    GoToxy(35,6);
    Print("                     ");
	GoToxy(35,7);
	ss.str("");
	ss << "Health:" << player.GetPlayerHealth() << "    ";
	Print(ss.str());
    GoToxy(35,8);
    Print("                     ");
    render_lock.unlock();
}
void PrintInventoryList(vector<Item> item,int sel,int renderT,int renderB){
	for(int i=max(0,renderT);i<min(renderB+1,(int)item.size());i++){
		stringstream ss;
		ss << "Item" << i+1 << "\t" << item[i].num << "\t" << item[i].itemName << endl;
		if(i==sel){
			ChangeTextColor(COLOR_YELLOW);
		}
		Print(ss.str());
		ChangeTextColor(COLOR_WHITE);
	}
}
void PrintInventory(){
	vector<Item> item;
	item=player.GetPlayerInventory();
	int renderT=0,renderB=min((int)item.size()-1,INV_VIEW-1);
	cls_Clean();
	int select=0;
	PrintInventoryList(item,select,renderT,renderB);
	while(1){
		char c=getch();
		switch(c){
			case KEY_INVENTORY:
				player.SetPlayerInventory(item);
				RenderMap();
				return;
			case KEY_DROP:
				if(item.size()!=0){
					if(item[select].num>1){
						item[select].num--;
					}
					else{
						item.erase(item.begin()+select);
						select=min(select,(int)item.size()-1);
						if(select==-1){
							select=0;
						}
						cls_Clean();
						PrintInventoryList(item,select,renderT,renderB);
						break;
					}
					cls();
					PrintInventoryList(item,select,renderT,renderB);
				}
				break;
			case KEY_UP:
				select=min(select-1,(int)item.size()-1);
				if(select<=-1){
					select=0;
				}
				if(select<renderT){
					renderT=select;
					renderB=min((int)item.size(),renderT+INV_VIEW-1);
				}
				cls();
				PrintInventoryList(item,select,renderT,renderB);
				break;
			case KEY_DOWN:
				select=min(select+1,(int)item.size()-1);
				if(select<=-1){
					select=0;
				}
				if(select>renderB){
					renderB=select;
					renderT=max(0,renderB-INV_VIEW+1);
				}
				cls();
				PrintInventoryList(item,select,renderT,renderB);
				break;
			case KEY_ENTER:
				player.SetPlayerHandheld(item[select]);
		};
	}
}
Item SelectItem(){
	vector<Item> item;
	item=player.GetPlayerInventory();
	int renderT=0,renderB=min((int)item.size()-1,INV_VIEW-1);
	cls_Clean();
	int select=0;
	PrintInventoryList(item,select,renderT,renderB);
	while(1){
		char c=getch();
		switch(c){
			case KEY_UP:
				select=min(select-1,(int)item.size()-1);
				if(select<=-1){
					select=0;
				}
				if(select<renderT){
					renderT=select;
					renderB=min((int)item.size(),renderT+INV_VIEW-1);
				}
				cls();
				PrintInventoryList(item,select,renderT,renderB);
				break;
			case KEY_DOWN:
				select=min(select+1,(int)item.size()-1);
				if(select<=-1){
					select=0;
				}
				if(select>renderB){
					renderB=select;
					renderT=max(0,renderB-INV_VIEW+1);
				}
				cls();
				PrintInventoryList(item,select,renderT,renderB);
				break;
			case KEY_ENTER:
				return item[select];
		};
	}
}
void RenderCraft(){
	int recipe[3][3]={0};
	cls_Clean();
	while(1){
		char c=getch();
		switch(c){
			case KEY_CRAFT:
				cls_Clean();
				RenderMap();
				return;
			case KEY_PLACE:
				Print("Please enter the placement location\"(1~2) (1~2):\"");
				int x,y;
				cin >> x >> y;
				recipe[(x-1)%2][(y-1)%2]=SelectItem().id;
				cls_Clean();
				break;
			case KEY_MERGE:
				if(player.PlayerCraft(recipe)){
					Print("Merge success!\n");
				}
				else{
					Print("Insufficient ingredients or wrong recipe!\n");
				}
				break;
			case KEY_CLEAR:
				Print("Please enter the clear location\"(1~2) (1~2):\"");
				int x2,y2;
				cin >> x2 >> y2;
				recipe[(x2-1)%2][(y2-1)%2]=ID_SPECIAL_AIR;
				break;
		}
	}
}
void RenderCraftingTable(){
	int recipe[3][3]={0};
	cls_Clean();
	while(1){
		char c=getch();
		switch(c){
			case KEY_CRAFT:
				cls_Clean();
				RenderMap();
				return;
			case KEY_PLACE:
				Print("Please enter the placement location\"(1~3) (1~3):\"");
				int x,y;
				cin >> x >> y;
				recipe[(x-1)%3][(y-1)%3]=SelectItem().id;
				cls_Clean();
				break;
			case KEY_MERGE:
				if(player.PlayerCraft(recipe)){
					Print("Merge success!\n");
				}
				else{
					Print("Insufficient ingredients or wrong recipe!\n");
				}
				break;
			case KEY_CLEAR:
				Print("Please enter the clear location\"(1~3) (1~3):\"");
				int x2,y2;
				cin >> x2 >> y2;
				recipe[(x2-1)%3][(y2-1)%3]=ID_SPECIAL_AIR;
				break;
		};
	}
}
void RenderFurnace(){
	/* TODO (#5#): 添加渲染熔炉函数 */

}
void RenderInteract(){
	Item facing=player.GetFacingBlock();
	switch(facing.id){
		case ID_BLOCK_FURNACE:
			break;
		case ID_BLOCK_CRAFTING_TABLE:
			RenderCraftingTable();
			break;
	}
}
void HideCursor(){
    CONSOLE_CURSOR_INFO cursor;
    cursor.bVisible = FALSE;
    cursor.dwSize = sizeof(cursor);
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorInfo(handle, &cursor);
}
void parsingCommand(Command cmd){
	if(cmd.getCommandHead()==CMDGIVE){
		int id=sti(cmd.getArg(0));
		if(IdToName(id)==""){
			cls_Clean();
			Print("This item does not exist.");
			Sleep(2000);
			cls_Clean();
			RenderMap();
		}
		player.PlayerPickupItem(
			Item(
				IdToType(id),
				IdToName(id),
				sti(cmd.getArg(1)),
				id
			)
		);
	}
	else{
		Print("This command does not exist.");
	}
}
void RenderCommand(){
	cls_Clean();
	Print("Enter the commands:\n");
	string command;
	while(1){
		char c=getche();
		if(c==KEY_QUIT){
			cls_Clean();
			RenderMap();
			return;
		}
		else if(c=='\n'||c=='\r'){
			Command cmd=Command(command);
			parsingCommand(cmd);
			cout << "command:" << cmd.getCommandHead() << endl;
			for(int i=0;i<cmd.getArgs().size();i++){
				cout << "Args" << i << ":" << cmd.getArg(i) << endl;
			}
			command="";
		}
		else{
			command+=c;
		}
	}
	cls_Clean();
	RenderMap();
}
void init(){
    signManager.updateSign(DAMAGETHREAD,false);
	system("mode con cols=100 lines=31");
	damageJudger.detach();
	HideCursor();
	srand(time(0));
	for(int i=0;i<MAP_SIZE;i++){
		for(int j=0;j<MAP_SIZE;j++){
			int R=rand()%1000;
			/* DONE (#5#): 修改构造函数生成自然燃料 */
			if(R<1){
				mp[i][j]=BLOCK_DIAMOND_ORE;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_DIAMOND_ORE,1,ID_BLOCK_DIAMOND_ORE,0,0);
			}
			else if(R<10){
				mp[i][j]=BLOCK_COAL_ORE;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_COAL_ORE,1,ID_BLOCK_COAL_ORE,0,0);
			}
			else if(R<15){
				mp[i][j]=BLOCK_IRON_ORE;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_IRON_ORE,1,ID_BLOCK_IRON_ORE,0,0);
			}
			else if(R<19){
				mp[i][j]=BLOCK_GOLD_ORE;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_GOLD_ORE,1,ID_BLOCK_GOLD_ORE,0,0);
			}
			else if(R<35){
				mp[i][j]=BLOCK_WOOD;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_WOOD,1,ID_BLOCK_WOOD,1,BURN_SHORT);
			}
			else if(R<55){
				mp[i][j]=BLOCK_STONE;
				mpItem[i][j]=Item(TYPE_BLOCK,NAME_COBBLESTONE,1,ID_BLOCK_COBBLESTONE,0,0);
			}
			else if(R<70){
                mp[i][j]=LIQUID_LAVA;
                mpItem[i][j]=Item(TYPE_LIQUID,NAME_LAVA,1,ID_LIQUID_LAVA,0,0,1,DAMAGE_LOW);
			}
			else{
				mp[i][j]=BLOCK_GROUND;
				mpItem[i][j]=Item();
			}
		}
	}
    mp[0][0]=BLOCK_GROUND;
    mpItem[0][0]=Item();
    RenderMap();
}
void mainThread(){
	init();
	while(1){
        fflush(stdin);
		char c=getch();
		switch(c){
			case KEY_UP:
				player.PlayerMoveUp();
				break;
			case KEY_DOWN:
				player.PlayerMoveDown();
				break;
			case KEY_LEFT:
				player.PlayerMoveLeft();
				break;
			case KEY_RIGHT:
				player.PlayerMoveRight();
				break;
			case KEY_BREAK:
				player.PlayerBreak();
				break;
			case KEY_INVENTORY:
				PrintInventory();
				break;
			case KEY_CRAFT:
				RenderCraft();
				break;
			case KEY_PLACE:
				player.PlayerPlaceBlock(player.GetPlayerHandheld());
				break;
			case KEY_INTERACT:
				RenderInteract();
				break;
			case KEY_COMMAND:
				RenderCommand();
				break;
		    case KEY_QUIT:
                signManager.updateSign(DAMAGETHREAD,true);
                Sleep(1000);
                return;
                break;
		};
        RenderMap();
        fflush(stdin);
	}
}
void damageJudge(){
    damage_lock.lock();
    double damage=player.GetStandingBlock().onItDamage;
    if(damage>0.01){
        player.PlayerDamage(damage);
        RenderMap();
    }
    damage_lock.unlock();
}
void DamageThread(){
    while(1){
        if(signManager.getSign(DAMAGETHREAD)){
            return;
        }
        damageJudge();
        Sleep(500);
    }
}
int main(){
    damageJudger=thread(DamageThread);
    Main=thread(mainThread);
    Main.join();
}
