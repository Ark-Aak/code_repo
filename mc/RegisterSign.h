#include <map>
class SignManager{
public:
    void updateSign(string signName,bool value){
        states[signName]=value;
    }
    bool getSign(string signName){
        return states[signName];
    }
private:
    map<string,bool> states;
};
