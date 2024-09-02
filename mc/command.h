#include<string>
#include<vector>
using namespace std;
class Command{
	private:
		string command;
		string commandHead;
		vector<string> args;
	public:
		Command(string fullCommand){
			command=fullCommand;
			args.clear();
			string temp="";
			for(int i=0;i<fullCommand.length();i++){
				if(fullCommand[i]==' ')args.push_back(temp),temp="";
				else temp+=fullCommand[i];
			}
			commandHead=args[0];
			args.erase(args.begin());
			args.push_back(temp);
		}
		string getFullCommand(){
			return command;
		}
		string getCommandHead(){
			return commandHead;
		}
		vector<string> getArgs(){
			return args;
		}
		string getArg(int pos){
			if(pos>=args.size()){
				return nullptr;
			}
			return args[pos];
		}
};
