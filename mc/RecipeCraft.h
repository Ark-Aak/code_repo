#include <string>
#include <vector>
using namespace std;
#define MAP_SIZE 3000
#define VIEW_DIS 30
#define INV_VIEW 30
#define BLOCK_COAL_ORE 'C'
#define BLOCK_DIAMOND_ORE 'D'
#define BLOCK_IRON_ORE 'I'
#define BLOCK_GOLD_ORE 'G'
#define BLOCK_GROUND '.'
#define BLOCK_WOOD 'W'
#define BLOCK_FURNACE 'F'
#define BLOCK_STONE 'S'
#define BLOCK_COBBLESTONE 'T'
#define BLOCK_CRAFTING_TABLE 'R'
#define BLOCK_WOODEN_PLANK 'P'
#define LIQUID_LAVA '#'
#define ID_BLOCK_COAL_ORE 1
#define ID_BLOCK_DIAMOND_ORE 2
#define ID_BLOCK_IRON_ORE 3
#define ID_BLOCK_GOLD_ORE 4
#define ID_BLOCK_WOOD 5
#define ID_BLOCK_WOODEN_PLANK 26
#define ID_BLOCK_STONE 27
#define ID_BLOCK_COBBLESTONE 28
#define ID_BLOCK_FURNACE 29
#define ID_BLOCK_CRAFTING_TABLE 30
#define ID_TOOL_WOODEN_PICKAXE 6
#define ID_TOOL_WOODEN_AXE 7
#define ID_TOOL_WOODEN_SHOVEL 8
#define ID_TOOL_WOODEN_SWORD 9
#define ID_TOOL_IRON_PICKAXE 10
#define ID_TOOL_IRON_AXE 11
#define ID_TOOL_IRON_SHOVEL 12
#define ID_TOOL_IRON_SWORD 13
#define ID_TOOL_GOLDEN_PICKAXE 14
#define ID_TOOL_GOLDEN_AXE 15
#define ID_TOOL_GOLDEN_SHOVEL 16
#define ID_TOOL_GOLDEN_SWORD 17
#define ID_TOOL_DIAMOND_PICKAXE 18
#define ID_TOOL_DIAMOND_AXE 19
#define ID_TOOL_DIAMOND_SHOVEL 20
#define ID_TOOL_DIAMOND_SWORD 21
#define ID_ITEM_STICK 22
#define ID_ITEM_DIAMOND 23
#define ID_ITEM_GOLD_INGOT 24
#define ID_ITEM_IRON_INGOT 25
#define ID_ITEM_COAL 31
#define ID_LIQUID_LAVA 32
#define ID_SPECIAL_AIR 0
#define TYPE_SPECIAL 1
#define TYPE_ITEM 2
#define TYPE_FOOD 3
#define TYPE_BLOCK 4
#define TYPE_TOOL 5
#define TYPE_LIQUID 6
#define KEY_LEFT 'a'
#define KEY_RIGHT 'd'
#define KEY_UP 'w'
#define KEY_DOWN 's'
#define KEY_BREAK 'j'
#define KEY_INVENTORY 'e'
#define KEY_DROP 'q'
#define KEY_ATTACK 'k'
#define KEY_CRAFT 'c' 
#define KEY_PLACE 'p'
#define KEY_ENTER 'o'
#define KEY_MERGE 'm'
#define KEY_CLEAR 'r'
#define KEY_INTERACT 'u'
#define KEY_COMMAND '/'
#define KEY_QUIT 0x1B
#define WAY_LEFT 1
#define WAY_RIGHT 2
#define WAY_UP 3
#define WAY_DOWN 4
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
#define TIME_FAST 2
#define TIME_NORMAL 5
#define TIME_SLOW 8
#define SIZE_RECIPE 36
#define NAME_DIAMOND_ORE "Diamond Ore"
#define NAME_IRON_ORE "Iron Ore"
#define NAME_GOLD_ORE "Gold Ore"
#define NAME_COAL_ORE "Coal Ore"
#define NAME_WOOD "Wood"
#define NAME_WOODEN_PLANK "Wooden Plank"
#define NAME_STONE "Stone"
#define NAME_COBBLESTONE "Cobble Stone"
#define NAME_FURNACE "Furnace"
#define NAME_CRAFTING_TABLE "Crafting Table"
#define NAME_DIAMOND_PICKAXE "Diamond Pickaxe"
#define NAME_DIAMOND_AXE "Diamond Axe"
#define NAME_DIAMOND_SHOVEL "Diamond Shovel"
#define NAME_DIAMOND_SWORD "Diamond Sword"
#define NAME_GOLDEN_PICKAXE "Golden Pickaxe"
#define NAME_GOLDEN_AXE "Golden Axe"
#define NAME_GOLDEN_SHOVEL "Golden Shovel"
#define NAME_GOLDEN_SWORD "Golden Sword"
#define NAME_IRON_PICKAXE "Iron Pickaxe"
#define NAME_IRON_AXE "Iron Axe"
#define NAME_IRON_SHOVEL "Iron Shovel"
#define NAME_IRON_SWORD "Iron Sword"
#define NAME_WOODEN_PICKAXE "Wooden Pickaxe"
#define NAME_WOODEN_AXE "Wooden Axe"
#define NAME_WOODEN_SHOVEL "Wooden Shovel"
#define NAME_WOODEN_SWORD "Wooden Sword"
#define NAME_DIAMOND "Diamond"
#define NAME_GOLD_INGOT "Gold Ingot"
#define NAME_IRON_INGOT "Iron Ingot"
#define NAME_COAL "Coal"
#define NAME_STICK "Stick"
#define NAME_LAVA "Lava"
#define BURN_VERY_SHORT 1
#define	BURN_SHORT 2
#define BURN_NORMAL 5
#define BURN_LONG 10
#define BURN_VERY_LONG 20
#define DAMAGE_LOW 2
#define DAMAGE_MEDIUM 5
#define DAMAGE_HIGH 10
#define STATENAME_BURNING "Burning"
#define STATE_BURNING 1
struct Pos{//位置结构体 
	int x,y;
	Pos(){x=0,y=0;}
	Pos(int x,int y){
		this->x=x;
		this->y=y;
	}
	void R(){
		if(y+1<MAP_SIZE){
			y++;
		}
	}
	void L(){
		if(y-1>=0){
			y--;
		}
	}
	void U(){
		if(x-1>=0){
			x--;
		}
	}
	void D(){
		if(x+1<MAP_SIZE){
			x++;
		}
	}
};
bool CheckPos(Pos res,Pos check){
	if(res.x==check.x&&res.y==check.y){
		return true;
	}
	return false;
}
string StateToStateName(int state){
    switch(state){
        case STATE_BURNING:
            return STATENAME_BURNING;
        default:
            return "";
    }
}
string IdToName(int id){
	switch(id){
		case ID_BLOCK_COAL_ORE:
			return NAME_COAL_ORE;
		case ID_BLOCK_DIAMOND_ORE:
			return NAME_DIAMOND_ORE;
		case ID_BLOCK_IRON_ORE:
			return NAME_IRON_ORE;
		case ID_BLOCK_GOLD_ORE:
			return NAME_GOLD_ORE;
		case ID_BLOCK_WOOD:
			return NAME_WOOD;
		case ID_BLOCK_WOODEN_PLANK:
			return NAME_WOODEN_PLANK;
		case ID_BLOCK_STONE:
			return NAME_STONE;
		case ID_BLOCK_COBBLESTONE:
			return NAME_COBBLESTONE;
		case ID_BLOCK_FURNACE:
			return NAME_FURNACE;
		case ID_BLOCK_CRAFTING_TABLE:
			return NAME_CRAFTING_TABLE;
		case ID_TOOL_WOODEN_PICKAXE:
			return NAME_WOODEN_PICKAXE;
		case ID_TOOL_WOODEN_AXE:
			return NAME_WOODEN_AXE;
		case ID_TOOL_WOODEN_SHOVEL:
			return NAME_WOODEN_SHOVEL;
		case ID_TOOL_WOODEN_SWORD:
			return NAME_WOODEN_SWORD;
		case ID_TOOL_IRON_PICKAXE:
			return NAME_IRON_PICKAXE;
		case ID_TOOL_IRON_AXE:
			return NAME_IRON_AXE;
		case ID_TOOL_IRON_SHOVEL:
			return NAME_IRON_SHOVEL;
		case ID_TOOL_IRON_SWORD:
			return NAME_IRON_SWORD;
		case ID_TOOL_GOLDEN_PICKAXE:
			return NAME_GOLDEN_PICKAXE;
		case ID_TOOL_GOLDEN_AXE:
			return NAME_GOLDEN_AXE;
		case ID_TOOL_GOLDEN_SHOVEL:
			return NAME_GOLDEN_SHOVEL;
		case ID_TOOL_GOLDEN_SWORD:
			return NAME_GOLDEN_SWORD;
		case ID_TOOL_DIAMOND_PICKAXE:
			return NAME_DIAMOND_PICKAXE;
		case ID_TOOL_DIAMOND_AXE:
			return NAME_DIAMOND_AXE;
		case ID_TOOL_DIAMOND_SHOVEL:
			return NAME_DIAMOND_SHOVEL;
		case ID_TOOL_DIAMOND_SWORD:
			return NAME_DIAMOND_SWORD;
		case ID_ITEM_STICK:
			return NAME_STICK;
		case ID_ITEM_DIAMOND:
			return NAME_DIAMOND;
		case ID_ITEM_GOLD_INGOT:
			return NAME_GOLD_INGOT;
		case ID_ITEM_IRON_INGOT:
			return NAME_IRON_INGOT;
	    case ID_ITEM_COAL:
	        return NAME_COAL;
		case ID_SPECIAL_AIR:
			return "";
		default:
			return "";
	};
}
int IdToType(int id){
	switch(id){
		case ID_BLOCK_COAL_ORE:
			return TYPE_BLOCK;
		case ID_BLOCK_DIAMOND_ORE:
			return TYPE_BLOCK;
		case ID_BLOCK_IRON_ORE:
			return TYPE_BLOCK;
		case ID_BLOCK_GOLD_ORE:
			return TYPE_BLOCK;
		case ID_BLOCK_WOOD:
			return TYPE_BLOCK;
		case ID_BLOCK_WOODEN_PLANK:
			return TYPE_BLOCK;
		case ID_BLOCK_STONE:
			return TYPE_BLOCK;
		case ID_BLOCK_COBBLESTONE:
			return TYPE_BLOCK;
		case ID_BLOCK_FURNACE:
			return TYPE_BLOCK;
		case ID_BLOCK_CRAFTING_TABLE:
			return TYPE_BLOCK;
		case ID_TOOL_WOODEN_PICKAXE:
			return TYPE_TOOL;
		case ID_TOOL_WOODEN_AXE:
			return TYPE_TOOL;
		case ID_TOOL_WOODEN_SHOVEL:
			return TYPE_TOOL;
		case ID_TOOL_WOODEN_SWORD:
			return TYPE_TOOL;
		case ID_TOOL_IRON_PICKAXE:
			return TYPE_TOOL;
		case ID_TOOL_IRON_AXE:
			return TYPE_TOOL;
		case ID_TOOL_IRON_SHOVEL:
			return TYPE_TOOL;
		case ID_TOOL_IRON_SWORD:
			return TYPE_TOOL;
		case ID_TOOL_GOLDEN_PICKAXE:
			return TYPE_TOOL;
		case ID_TOOL_GOLDEN_AXE:
			return TYPE_TOOL;
		case ID_TOOL_GOLDEN_SHOVEL:
			return TYPE_TOOL;
		case ID_TOOL_GOLDEN_SWORD:
			return TYPE_TOOL;
		case ID_TOOL_DIAMOND_PICKAXE:
			return TYPE_TOOL;
		case ID_TOOL_DIAMOND_AXE:
			return TYPE_TOOL;
		case ID_TOOL_DIAMOND_SHOVEL:
			return TYPE_TOOL;
		case ID_TOOL_DIAMOND_SWORD:
			return TYPE_TOOL;
		case ID_ITEM_STICK:
			return TYPE_ITEM;
		case ID_ITEM_DIAMOND:
			return TYPE_ITEM;
		case ID_ITEM_GOLD_INGOT:
			return TYPE_ITEM;
		case ID_ITEM_IRON_INGOT:
			return TYPE_ITEM;
	    case ID_ITEM_COAL:
	        return TYPE_ITEM;
		case ID_SPECIAL_AIR:
			return TYPE_SPECIAL;
	    case ID_LIQUID_LAVA:
	        return TYPE_LIQUID;
		default:
			return TYPE_SPECIAL;
	};
}
char IdToChar(int id){
	switch(id){
		case ID_BLOCK_COAL_ORE:
			return BLOCK_COAL_ORE;
		case ID_BLOCK_DIAMOND_ORE:
			return BLOCK_DIAMOND_ORE;
		case ID_BLOCK_IRON_ORE:
			return BLOCK_IRON_ORE;
		case ID_BLOCK_GOLD_ORE:
			return BLOCK_GOLD_ORE;
		case ID_BLOCK_WOOD:
			return BLOCK_WOOD;
		case ID_BLOCK_WOODEN_PLANK:
			return BLOCK_WOODEN_PLANK;
		case ID_BLOCK_STONE:
			return BLOCK_STONE;
		case ID_BLOCK_COBBLESTONE:
			return BLOCK_COBBLESTONE;
		case ID_BLOCK_FURNACE:
			return BLOCK_FURNACE;
		case ID_BLOCK_CRAFTING_TABLE:
			return BLOCK_CRAFTING_TABLE;
		default:
			return ' ';
	};
}
class Item{
	public:
		int type;
		string itemName;
		bool isFuel;
		int burnTime;
		int id;
		int num;
		bool canWalkOnIt;
		double onItDamage;
		Item(){type=0,itemName="",num=0,id=0;isFuel=false;burnTime=0;this->canWalkOnIt=0;this->onItDamage=0;}//构造函数
		Item(int type,string itemName,int num,int id){
			this->type=type;
			this->itemName=itemName; 
			this->num=num;
			this->id=id;
			isFuel=false;
			burnTime=0;
            this->canWalkOnIt=0;
            this->onItDamage=0;
		}
		Item(int type,string itemName,int num,int id,bool isFuel,int burnTime){
			this->type=type;
			this->itemName=itemName; 
			this->num=num;
			this->id=id;
			this->isFuel=isFuel;
			this->burnTime=burnTime;
            this->canWalkOnIt=0;
            this->onItDamage=0;
		}
        Item(int type,string itemName,int num,int id,bool isFuel,int burnTime,bool canWalk,double damage){
            this->type=type;
            this->itemName=itemName;
            this->num=num;
            this->id=id;
            this->isFuel=isFuel;
            this->burnTime=burnTime;
            this->canWalkOnIt=canWalk;
            this->onItDamage=damage;
        }
		bool operator==(const Item &t){
			return type==t.type&&itemName==t.itemName&&isFuel==t.isFuel&&burnTime==t.burnTime&&id==t.id&&num==t.num;
		}
		bool operator!=(const Item &t){
			return !(type==t.type&&itemName==t.itemName&&isFuel==t.isFuel&&burnTime==t.burnTime&&id==t.id&&num==t.num);
		}
};
class Block{
public:
    Item item;
    double hard;
};
/* DONE (#9#): 添加IdToIsFuel函数来判定是否为燃料 */
bool IdToIsFuel(int id){
	switch(id){
		case ID_BLOCK_WOOD:
			return 1;
		case ID_BLOCK_WOODEN_PLANK:
			return 1;
		case ID_BLOCK_CRAFTING_TABLE:
			return 1;
		case ID_TOOL_WOODEN_PICKAXE:
			return 1;
		case ID_TOOL_WOODEN_AXE:
			return 1;
		case ID_TOOL_WOODEN_SHOVEL:
			return 1;
		case ID_TOOL_WOODEN_SWORD:
			return 1;
		case ID_ITEM_STICK:
			return 1;
	    case ID_ITEM_COAL:
	        return 1;
		default:
			return 0;
	}
}
class Inventory{
	public:
		bool GetItem(int id,int num){return RemoveItem(id,num);}
		/* TODO (#5#): 增加添加物品功能 */
		
	private:
		bool RemoveItem(int id,int num){
			int tn=0;
			for(int i=0;i<item.size();i++){
				if(item[i].id==id){
					tn+=item[i].num;
				}
			}
			if(tn>=num){
				for(int i=0;i<item.size();i++){
					if(item[i].id==id){
						if(item[i].num>=num){
							item[i].id-=num;
							if(item[i].num<=0){
								item.erase(item.begin()+i);
							}
						}
						else{
							num-=item[i].num;
							item.erase(item.begin()+i);
						}
					}
				}
				return true;
			}
			else{
				return false;
			}
			return false;
		}
		int capacity;
		vector<Item> item;
};
class FurnaceRecipe{
	public:
		int resourceId,targetId;
		int burnTime,num; 
		FurnaceRecipe(){}
		FurnaceRecipe(int rid,int tid,int bt,int num){
			resourceId=rid;
			targetId=tid;
			burnTime=bt;
			this->num=num;
		}
};
class Furnace{
	public:
		Furnace(Pos pos);
		void AddTask(FurnaceRecipe fr){
			tasks.push_back(fr);
		}
		void ProcessingRecipe(){
			if(tasks.size()>0){
				tasks[0].burnTime--;
				if(tasks[0].burnTime<=0){
					results.push_back(Item(IdToType(tasks[0].targetId),IdToName(tasks[0].targetId),tasks[0].num,tasks[0].targetId));
					/* TODO (#5#): 修改构造函数以支持燃烧出燃料 */
					tasks.erase(tasks.begin());
				}
			}
		}
		void AddFuel(Item fuel){
			/* DONE (#3#): 添加燃料函数 */
			if(fuel.isFuel){
				fuels.push_back(fuel);
			}
		}
	private:
		vector<FurnaceRecipe> tasks;
		vector<Item> fuels;
		vector<Item> results;
		Pos pos;
};
vector<Furnace*> furnace;
Furnace::Furnace(Pos pos){
	/* DONE (#3#): 熔炉构造函数 */
	furnace.push_back(this);
	this->pos=pos;
}
int recipeCraft[][3][3]={
	{
		{ID_BLOCK_WOOD,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR}
	},
	{
		{ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR}
	},
	{
		{ID_ITEM_DIAMOND,ID_ITEM_DIAMOND,ID_ITEM_DIAMOND},
		{ID_SPECIAL_AIR,ID_ITEM_STICK,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_ITEM_STICK,ID_SPECIAL_AIR}
	},
	{
		{ID_BLOCK_COBBLESTONE,ID_BLOCK_COBBLESTONE,ID_BLOCK_COBBLESTONE},
		{ID_BLOCK_COBBLESTONE,ID_SPECIAL_AIR,ID_BLOCK_COBBLESTONE},
		{ID_BLOCK_COBBLESTONE,ID_BLOCK_COBBLESTONE,ID_BLOCK_COBBLESTONE}
	}, 
	{
		{ID_SPECIAL_AIR,ID_ITEM_DIAMOND,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_ITEM_DIAMOND,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_ITEM_STICK,ID_SPECIAL_AIR}
	},
	{
		{ID_ITEM_DIAMOND,ID_ITEM_DIAMOND,ID_SPECIAL_AIR},
		{ID_ITEM_DIAMOND,ID_ITEM_STICK,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_ITEM_STICK,ID_SPECIAL_AIR}
	},
	{
		{ID_BLOCK_WOODEN_PLANK,ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR},
		{ID_BLOCK_WOODEN_PLANK,ID_ITEM_STICK,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_ITEM_STICK,ID_SPECIAL_AIR}
	},
	{
		{ID_BLOCK_WOODEN_PLANK,ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR},
		{ID_BLOCK_WOODEN_PLANK,ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR}
	},
	{
		{ID_BLOCK_WOODEN_PLANK,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR},
		{ID_SPECIAL_AIR,ID_SPECIAL_AIR,ID_SPECIAL_AIR}
	}
};
Item recipes[]={
	Item(TYPE_BLOCK,NAME_WOODEN_PLANK,4,ID_BLOCK_WOODEN_PLANK),
	Item(TYPE_ITEM,NAME_STICK,4,ID_ITEM_STICK),
	Item(TYPE_TOOL,NAME_DIAMOND_PICKAXE,1,ID_TOOL_DIAMOND_PICKAXE),
	Item(TYPE_BLOCK,NAME_FURNACE,1,ID_BLOCK_FURNACE),
	Item(TYPE_TOOL,NAME_DIAMOND_SWORD,1,ID_TOOL_DIAMOND_SWORD),
	Item(TYPE_TOOL,NAME_DIAMOND_AXE,1,ID_TOOL_DIAMOND_AXE),
	Item(TYPE_TOOL,NAME_WOODEN_AXE,1,ID_TOOL_WOODEN_AXE),
	Item(TYPE_BLOCK,NAME_CRAFTING_TABLE,1,ID_BLOCK_CRAFTING_TABLE),
	Item(TYPE_ITEM,NAME_DIAMOND,1,ID_ITEM_DIAMOND)
};
FurnaceRecipe furnaceRecipe[]={
	FurnaceRecipe(ID_BLOCK_DIAMOND_ORE,ID_ITEM_DIAMOND,TIME_NORMAL,1),
	FurnaceRecipe(ID_BLOCK_GOLD_ORE,ID_ITEM_GOLD_INGOT,TIME_NORMAL,1),
	FurnaceRecipe(ID_BLOCK_IRON_ORE,ID_ITEM_IRON_INGOT,TIME_NORMAL,1),
	FurnaceRecipe(ID_BLOCK_COBBLESTONE,ID_BLOCK_STONE,TIME_FAST,1),
};
/*
	{
		{,,},
		{,,},
		{,,}
	},
	
	{,,,},
	
	{,,,,},
	
	FurnaceRecipe(ID_,ID_,TIME_,),
*/

