#include <string>
#include <vector>

using namespace std;

#include "Util.h"

char mp[MAP_SIZE][MAP_SIZE];
//   地图渲染上界  下界               左界      右界
int renderXT=0,renderXB=VIEW_DIS-1,renderYL=0,renderYR=VIEW_DIS-1;
class Player{
public:
    Player(){
        locker[0].lock();
        way=WAY_RIGHT;
        health=20.0;
        attack=1.0;
        handheld=ID_SPECIAL_AIR;
        locker[0].unlock();
    }
    void IsAlive(){
        locker[1].lock();
        if(health<=0){
            cls_Clean();
            Print("你失败了！");
            signManager.updateSign(DAMAGETHREAD,true);
            Sleep(1000);
            exit(0);
        }
        locker[1].unlock();
    }
    void PlayerMoveUp(){
        locker[2].lock();
        if(pos.x-1>=0&&(mpItem[pos.x-1][pos.y].canWalkOnIt||mp[pos.x-1][pos.y]=='.')){
            pos.U();
        }
        if(pos.x<renderXT){
            renderXT=pos.x;
            renderXB=renderXT+VIEW_DIS-1;
        }
        way=WAY_UP;
        locker[2].unlock();
    }
    void PlayerMoveDown(){
        locker[3].lock();
        if(pos.x+1<MAP_SIZE&&(mpItem[pos.x+1][pos.y].canWalkOnIt||mp[pos.x+1][pos.y]=='.')){
            pos.D();
        }
        if(pos.x>renderXB){
            renderXB=pos.x;
            renderXT=renderXB-VIEW_DIS+1;
        }
        way=WAY_DOWN;
        locker[3].unlock();
    }
    void PlayerMoveLeft(){
        locker[4].lock();
        if(pos.y-1>=0&&(mpItem[pos.x][pos.y-1].canWalkOnIt||mp[pos.x][pos.y-1]=='.')){
            pos.L();
        }
        if(pos.y<renderYL){
            renderYL=pos.y;
            renderYR=renderYL+VIEW_DIS-1;
        }
        way=WAY_LEFT;
        locker[4].unlock();
    }
    void PlayerMoveRight(){
        locker[5].lock();
        if(pos.y+1<MAP_SIZE&&(mpItem[pos.x][pos.y+1].canWalkOnIt||mp[pos.x][pos.y+1]=='.')){
            pos.R();
        }
        if(pos.y>renderYR){
            renderYR=pos.y;
            renderYL=renderYR-VIEW_DIS+1;
        }
        way=WAY_RIGHT;
        locker[5].unlock();
    }
    Pos GetPlayerPos(){
        return pos;
    }
    void PlayerPickupItem(Item item){
        locker[6].lock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==item.id){
                if(itemStack[i].num+item.num<=64){
                    itemStack[i].num+=item.num;
                    locker[6].unlock();
                    return;
                }
                else{
                    item.num-=(64-itemStack[i].num);
                    itemStack[i].num=64;
                }
            }
        }
        itemStack.push_back(item);
        locker[6].unlock();
    }
    void PlayerDamage(double damage){
        locker[7].lock();
        health-=damage;
        IsAlive();
        locker[7].unlock();
    }
    void PlayerBreak(){
        locker[8].lock();
        switch(way){
            case WAY_UP:
                if(pos.x-1>=0&&mp[pos.x-1][pos.y]!='.'&&mpItem[pos.x-1][pos.y].type!=TYPE_LIQUID){
                    mp[pos.x-1][pos.y]='.';
                    PlayerPickupItem(mpItem[pos.x-1][pos.y]);
                    mpItem[pos.x-1][pos.y]=Item();
                }
                break;
            case WAY_DOWN:
                if(pos.x+1<MAP_SIZE&&mp[pos.x+1][pos.y]!='.'&&mpItem[pos.x+1][pos.y].type!=TYPE_LIQUID){
                    mp[pos.x+1][pos.y]='.';
                    PlayerPickupItem(mpItem[pos.x+1][pos.y]);
                    mpItem[pos.x+1][pos.y]=Item();
                }
                break;
            case WAY_LEFT:
                if(pos.y-1>=0&&mp[pos.x][pos.y-1]!='.'&&mpItem[pos.x][pos.y-1].type!=TYPE_LIQUID){
                    mp[pos.x][pos.y-1]='.';
                    PlayerPickupItem(mpItem[pos.x][pos.y-1]);
                    mpItem[pos.x][pos.y-1]=Item();
                }
                break;
            case WAY_RIGHT:
                if(pos.y+1<MAP_SIZE&&mp[pos.x][pos.y+1]!='.'&&mpItem[pos.x][pos.y+1].type!=TYPE_LIQUID){
                    mp[pos.x][pos.y+1]='.';
                    PlayerPickupItem(mpItem[pos.x][pos.y+1]);
                    mpItem[pos.x][pos.y+1]=Item();
                }
                break;
        };
        locker[8].unlock();
    }
    vector<Item> GetPlayerInventory(){
        return itemStack;
    }
    void SetPlayerInventory(vector<Item> item){
        locker[9].lock();
        itemStack=item;
        locker[9].unlock();
    }
    int GetPlayerWay(){
        return way;
    }
    bool PlayerCraft(int recipe[][3]){
        locker[10].lock();
        bool flg=0;
        for(int i=0;i<sizeof(recipeCraft)/SIZE_RECIPE;i++){
            int temp_Recipe[3][3];
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    temp_Recipe[j][k]=recipeCraft[i][j][k];
                }
            }
            if(CheckRecipe(recipe,temp_Recipe)){
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        if(recipeCraft[i][j][k]==ID_SPECIAL_AIR)continue;
                        for(int l=0;l<itemStack.size();l++){
                            if(itemStack[l].id==recipeCraft[i][j][k]){
                                itemStack[l].num--;
                                if(itemStack[l].num<=0){
                                    itemStack.erase(itemStack.begin()+l);
                                }
                                flg=1;
                                break;
                            }
                        }
                        if(!flg){
                            locker[10].unlock();
                            return false;
                        }
                        flg=0;
                    }
                }
                PlayerPickupItem(recipes[i]);
                locker[10].unlock();
                return true;
            }
        }
        locker[10].unlock();
        return false;
    }
    Item GetFacingBlock(){
        locker[11].lock();
        switch(GetPlayerWay()){
            case WAY_LEFT:
                if(pos.y>0){
                    locker[11].unlock();
                    return mpItem[pos.x][pos.y-1];
                }
                else{
                    locker[11].unlock();
                    return Item();
                }
            case WAY_RIGHT:
                if(pos.y<MAP_SIZE-1){
                    locker[11].unlock();
                    return mpItem[pos.x][pos.y+1];
                }
                else{
                    locker[11].unlock();
                    return Item();
                }
            case WAY_UP:
                if(pos.x>0){
                    locker[11].unlock();
                    return mpItem[pos.x-1][pos.y];
                }
                else{
                    locker[11].unlock();
                    return Item();
                }
            case WAY_DOWN:
                if(pos.x<MAP_SIZE-1){
                    locker[11].unlock();
                    return mpItem[pos.x+1][pos.y];
                }
                else{
                    locker[11].unlock();
                    return Item();
                }
        }
        locker[11].unlock();
        return Item();
    }
    void SetPlayerHandheld(Item item){
        locker[12].lock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==item.id){
                handheld=item.id;
                locker[12].unlock();
                return;
            }
        }
        locker[12].unlock();
    }
    int GetPlayerHandheld(){
        locker[13].lock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==handheld){
                locker[13].unlock();
                return handheld;
            }
        }
        handheld=ID_SPECIAL_AIR;
        locker[13].unlock();
        return handheld;
    }
    bool PlayerHasItem(int id){
        locker[14].lock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==id){
                locker[14].unlock();
                return true;
            }
        }
        locker[14].unlock();
        return false;
    }
    bool PlayerHasItem(Item item){
        locker[15].lock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==item.id){
                locker[15].unlock();
                return true;
            }
        }
        locker[15].unlock();
        return false;
    }
    bool CanPlace(Pos p){
        locker[16].lock();
        if(p.x>=0&&p.x<MAP_SIZE&&p.y>=0&&p.y<MAP_SIZE&&mp[p.x][p.y]==BLOCK_GROUND){
            locker[16].unlock();
            return true;
        }
        locker[16].unlock();
        return false;
    }
    void PlayerRemoveItem(int id){
        locker[17].unlock();
        for(int i=0;i<itemStack.size();i++){
            if(itemStack[i].id==id){
                itemStack[i].num--;
                if(itemStack[i].num<=0){
                    itemStack.erase(itemStack.begin()+i);
                    locker[17].unlock();
                    return;
                }
            }
        }
        locker[17].unlock();
    }
    void PlayerPlaceBlock(int id){
        locker[18].lock();
        /* TODO (#3#): 修改构造函数来标记是否为燃料方块 */
        if(PlayerHasItem(id)&&IdToType(id)==TYPE_BLOCK){
            switch(GetPlayerWay()){
                case WAY_LEFT:
                    if(CanPlace(Pos(pos.x,pos.y-1))){
                        mp[pos.x][pos.y-1]=IdToChar(id);
                        mpItem[pos.x][pos.y-1]=Item(TYPE_BLOCK,IdToName(id),1,id);
                        PlayerRemoveItem(id);
                        if(id==ID_BLOCK_FURNACE){
                            Furnace(Pos(pos.x,pos.y-1));
                        }
                    }
                    break;
                case WAY_RIGHT:
                    if(CanPlace(Pos(pos.x,pos.y+1))){
                        mp[pos.x][pos.y+1]=IdToChar(id);
                        mpItem[pos.x][pos.y+1]=Item(TYPE_BLOCK,IdToName(id),1,id);
                        PlayerRemoveItem(id);
                        if(id==ID_BLOCK_FURNACE){
                            Furnace(Pos(pos.x,pos.y+1));
                        }
                    }
                    break;
                case WAY_UP:
                    if(CanPlace(Pos(pos.x-1,pos.y))){
                        mp[pos.x-1][pos.y]=IdToChar(id);
                        mpItem[pos.x-1][pos.y]=Item(TYPE_BLOCK,IdToName(id),1,id);
                        PlayerRemoveItem(id);
                        if(id==ID_BLOCK_FURNACE){
                            Furnace(Pos(pos.x-1,pos.y));
                        }
                    }
                    break;
                case WAY_DOWN:
                    if(CanPlace(Pos(pos.x+1,pos.y))){
                        mp[pos.x+1][pos.y]=IdToChar(id);
                        mpItem[pos.x+1][pos.y]=Item(TYPE_BLOCK,IdToName(id),1,id);
                        PlayerRemoveItem(id);
                        if(id==ID_BLOCK_FURNACE){
                            Furnace(Pos(pos.x+1,pos.y));
                        }
                    }
                    break;
            }
        }
        locker[18].unlock();
    }
    double GetPlayerHealth(){
        return health;
    }
    Item GetStandingBlock(){
        return mpItem[pos.x][pos.y];
    }
private:
    mutex locker[19];
    double health,attack;
    Pos pos;
    int way;
    int handheld;
    vector<Item> itemStack;//背包
};
