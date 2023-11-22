#include<bits/stdc++.h>
#include <windows.h>
#define int long long
#pragma GCC optimize(3)
#define STR "string"
#define INT "int"
using namespace std;
typedef vector<string> StringList;
namespace regexs {
	const regex print("\\s*print\\s+(\\$?\\w+)");
	const regex println("\\s*println\\s+(\\$?\\w+)");
	const regex sprint("\\s*sprint\\s+\"(.*)\"");
	const regex sprintln("\\s*sprintln\\s+\"(.*)\"");
	const regex scan("\\s*scan\\s+(\\$?\\w+)");
	const regex var("\\$(\\w+)");
	const regex varname("\\w+");
	const regex def("\\s*def\\s+(.+)\\s+(\\w+)");
	const regex defarray("\\s*defarray\\s+(\\w+)\\s+(\\d+)");
	const regex selfadd("\\s*(\\$?\\w+)\\s*\\+=\\s*(\\$?\\w+)");
	const regex selfminus("\\s*(\\$?\\w+)\\s*\\-=\\s*(\\$?\\w+)");
	const regex selfmul("\\s*(\\$?\\w+)\\s*\\*=\\s*(\\$?\\w+)");
	const regex selfdiv("\\s*(\\$?\\w+)\\s*\\/=\\s*(\\$?\\w+)");
	const regex selfmod("\\s*(\\$?\\w+)\\s*\\%=\\s*(\\$?\\w+)");
	const regex let("\\s*(\\$?\\w+)\\s*:=\\s*(\\$?\\w+)");
	const regex letval("\\s*(\\$?\\w+)\\s*=\\s*(\\w+)");
	const regex jmp("\\s*jmp\\s+(@\\w+)");
	const regex ife("\\s*if\\s+(\\$?\\w+)\\s+(eq|leq|geq|ls|gr|neq)\\s+(\\$?\\w+)");
	const regex endif("\\s*endif");
	const regex final("\\s*final\\s+(\\$?\\w+)");
	const regex exitp("\\s*exit");
	const regex ing("\\s*#.*");
	const regex label("\\s*label\\s+(\\w+)");
	const regex labelname("\\s*@(\\w+)");
	const regex arr("\\&(\\w+)");
	const regex putarr("\\s*put\\s+(\\$\\w+)\\s+(&\\w+)\\s+(\\$\\w+)");
	const regex getarr("\\s*get\\s+(\\$\\w+)\\s+(&\\w+)\\s+(\\$\\w+)");
}
smatch m;
int line=0,mark=0,exec;
StringList splitStr(const string& str,char tag){
	StringList li;
	string subStr;
	for(int i=0;i<(int)str.length();i++){
		if(tag == str[i]){
			if(!subStr.empty()){
				li.push_back(subStr);
				subStr.clear();
			}
		}
		else subStr.push_back(str[i]);
	}
	if(!subStr.empty()) li.push_back(subStr);
	return li;
}
string cts(char* c){
	int len=strlen(c);
	string s;
	for(int i=0;i<len;i++){
		s+=c[i];
	}
	return s;
}
int sti(string s){
	int res=0;
	for(int i=0;i< (int) s.length();i++){
		res*=10;
		res+=s[i]-'0';
	}
	return res;
}
class var{
	map<string,string> type;
	map<string,string> strval;
	map<string,int> intval;
	map<string,bool> final;
public:
	string getType(string name){
		return type[name];
	}
	bool validVar(string name,string typen){
		return !(type.count(name)==0 || (intval.count(name)==0 &&
				strval.count(name)==0) || getType(name) != typen);
	}
	bool hasVar(string name){
		return !(type.count(name)==0 || (intval.count(name)==0 && strval.count(name)==0));
	}
	bool validType(string name){
		if(name!=INT && name!=STR)return 0;
		return 1;
	}
	int getInt(string name,int &mark){
		mark=0;
		if(type[name] != INT){mark=1;return 0;}
		else{return intval[name];}
	}
	string getStr(string name,int &mark){
		mark=0;
		if(type[name] != STR){mark=1;return "";}
		else{return strval[name];}
	}
	void regVar(string name,string typen,int &mark){
		mark=0;
		if(!validType(typen)){mark=1;return;}
		if(hasVar(name)){mark=1;return;}
		type[name]=typen;
		if(typen==STR){strval[name]="";}
		else{intval[name]=0;}
	}
	void setVarInt(string name,int val,int &mark){
		mark=0;
		if(!validVar(name,INT) || final[name]){mark=1;return;}
		intval[name]=val;
	}
	void setVarStr(string name,string val,int &mark){
		mark=0;
		if(!validVar(name,STR) || final[name]){mark=1;return;}
		strval[name]=val;
	}
	void setFinal(string name,int &mark){
		if(!hasVar(name)){mark=1;return;}
		final[name]=1;
	}
}v;
class arr {
	map <string, vector <int> > arrint;
public:
	bool hasArr(string name) {
		if (arrint.count(name) == 0) {
			return false;
		}
		return true;
	}
	void put(string name, int pos, int val, int &mark) {
		mark = 0;
		if (!hasArr(name)) {
			mark = 1;
			return;
		}
		if (pos >= (int)arrint[name].size()) {
			mark = 2;
			return;
		}
		arrint[name][pos] = val;
	}
	void create(string name, int size, int &mark) {
		mark = 0;
		if (hasArr(name)) {
			mark = 1;
			return;
		}
		vector <int> t;
		t.resize(size);
		arrint[name] = t;
	}
	int get(string name, int pos, int &mark) {
		mark = 0;
		if (!hasArr(name)) {
			mark = 1;
			return 0;
		}
		if (pos >= (int)arrint[name].size()) {
			mark = 2;
			return 0;
		}
		return arrint[name][pos];
	}
} arrs;
void tryJump(int line);
map<string,int> labelLine;
bool parse(string cmd,int execLine){
	if(regex_match(cmd,m,regexs::print)){
		smatch varM;
		string varName=m.str(1);
		if(!regex_match(varName,varM,regexs::var)){
			cout << varName;
		}
		else{
			if(!v.validVar(varM.str(1),INT) && !v.validVar(varM.str(1),STR)) goto error;
			if(v.getType(varM.str(1))==STR){
				cout << v.getStr(varM.str(1),mark);
			}
			else{
				cout << v.getInt(varM.str(1),mark);
			}
		}
	}
	else if(regex_match(cmd,m,regexs::println)){
		smatch varM;
		string varName=m.str(1);
		if(!regex_match(varName,varM,regexs::var)){
			cout << varName;
		}
		else{
			if(!v.validVar(varM.str(1),INT) && !v.validVar(varM.str(1),STR)) goto error;
			if(v.getType(varM.str(1))==STR){
				cout << v.getStr(varM.str(1),mark) << endl;
			}
			else{
				cout << v.getInt(varM.str(1),mark) << endl;
			}
		}
	}
	else if(regex_match(cmd,m,regexs::sprint)){
		cout << m.str(1);
	}
	else if(regex_match(cmd,m,regexs::sprintln)){
		cout << m.str(1) << endl;
	}
	else if(regex_match(cmd,m,regexs::scan)){
		smatch varM;
		string varName=m.str(1);
		if(!regex_match(varName,varM,regexs::var))goto error;
		if(!v.validVar(varM.str(1),INT) && !v.validVar(varM.str(1),STR)) goto error;
		if(v.getType(varM.str(1))==STR){
			string tVar;
			cin >> tVar;
			v.setVarStr(varM.str(1),tVar,mark);
			if(mark) goto error;
		}
		else{
			int tVar;
			cin >> tVar;
			v.setVarInt(varM.str(1),tVar,mark);
			if(mark) goto error;
		}
	}
	else if(regex_match(cmd,m,regexs::def)){
		StringList lst=splitStr(m.str(1),',');
		smatch vM;
		for(int i=0;i < (int)lst.size();i++){
			if(!regex_match(lst[i],vM,regexs::varname)) goto error;
			v.regVar(lst[i],m.str(2),mark);
			if(mark) goto error;
		}
	}
	else if(regex_match(cmd,m,regexs::selfadd)){
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(!v.validVar(varA.str(1),INT)) goto error;
		if(regex_match(varBName,varB,regexs::var)){
			if(!v.validVar(varB.str(1),INT)) goto error;
			int tVal=v.getInt(varA.str(1),mark),vVal;
			if(mark) goto error;
			vVal=v.getInt(varB.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal+vVal,mark);
			if(mark) goto error;
		}
		else{
			int tVal=sti(m.str(2)),vVal=v.getInt(varA.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal+vVal,mark);
			if(mark) goto error;
		}
	}
	else if(regex_match(cmd,m,regexs::selfminus)){
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(!v.validVar(varA.str(1),INT)) goto error;
		if(regex_match(varBName,varB,regexs::var)){
			if(!v.validVar(varB.str(1),INT)) goto error;
			int tVal=v.getInt(varA.str(1),mark),vVal;
			if(mark) goto error;
			vVal=v.getInt(varB.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal-vVal,mark);
			if(mark) goto error;
		}
		else{
			int tVal=sti(m.str(2)),vVal=v.getInt(varA.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal-vVal,mark);
			if(mark) goto error;
		}
	}
	else if (regex_match(cmd, m, regexs::selfmul)) {
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(!v.validVar(varA.str(1),INT)) goto error;
		if(regex_match(varBName,varB,regexs::var)){
			if(!v.validVar(varB.str(1),INT)) goto error;
			int tVal=v.getInt(varA.str(1),mark),vVal;
			if(mark) goto error;
			vVal=v.getInt(varB.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal*vVal,mark);
			if(mark) goto error;
		}
		else{
			int tVal=sti(m.str(2)),vVal=v.getInt(varA.str(1),mark);
			if(mark) goto error;
			v.setVarInt(varA.str(1),tVal*vVal,mark);
			if(mark) goto error;
		}
	}
	else if (regex_match(cmd, m, regexs::selfdiv)) {
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(!v.validVar(varA.str(1),INT)) goto error;
		if(regex_match(varBName,varB,regexs::var)){
			if(!v.validVar(varB.str(1),INT)) goto error;
			int tVal=v.getInt(varA.str(1),mark),vVal;
			if(mark) goto error;
			vVal=v.getInt(varB.str(1),mark);
			if(mark) goto error;
			if (vVal == 0) goto runtime_error;
			v.setVarInt(varA.str(1),tVal / vVal,mark);
			if(mark) goto error;
		}
		else{
			int tVal=sti(m.str(2)),vVal=v.getInt(varA.str(1),mark);
			if(mark) goto error;
			if (vVal == 0) goto runtime_error;
			v.setVarInt(varA.str(1),tVal / vVal,mark);
			if(mark) goto error;
		}
	}
	else if (regex_match(cmd, m, regexs::selfmod)) {
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(!v.validVar(varA.str(1),INT)) goto error;
		if(regex_match(varBName,varB,regexs::var)){
			if(!v.validVar(varB.str(1),INT)) goto error;
			int tVal=v.getInt(varA.str(1),mark),vVal;
			if(mark) goto error;
			vVal=v.getInt(varB.str(1),mark);
			if(mark) goto error;
			if (vVal == 0) goto runtime_error;
			v.setVarInt(varA.str(1),tVal % vVal,mark);
			if(mark) goto error;
		}
		else{
			int tVal=sti(m.str(2)),vVal=v.getInt(varA.str(1),mark);
			if(mark) goto error;
			if (vVal == 0) goto runtime_error;
			v.setVarInt(varA.str(1),tVal % vVal,mark);
			if(mark) goto error;
		}
	}
	else if(regex_match(cmd,m,regexs::let)){
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(2);
		if(!regex_match(varAName,varA,regexs::var) || !regex_match(varBName,varB,regexs::var)) goto error;
		if(v.getType(varA.str(1))!=v.getType(varB.str(1))) goto error;
		if(v.getType(varA.str(1))==STR){
			string tVal=v.getStr(varB.str(1),mark);
			if(mark)goto error;
			v.setVarStr(varA.str(1),tVal,mark);
			if(mark)goto error;
		}
		else{
			int tVal=v.getInt(varB.str(1),mark);
			if(mark)goto error;
			v.setVarInt(varA.str(1),tVal,mark);
			if(mark)goto error;
		}
	}
	else if(regex_match(cmd,m,regexs::letval)){
		smatch varA;
		string varAName=m.str(1);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		if(v.validVar(varA.str(1),INT)){
			int tVal=sti(m.str(2));
			v.setVarInt(varA.str(1),tVal,mark);
			if(mark) goto error;
		}
		else if(v.validVar(varA.str(1),STR)){
			v.setVarStr(varA.str(1),m.str(2),mark);
			if(mark) goto error;
		}
		else goto error;
	}
	else if(regex_match(cmd,m,regexs::jmp)){
		string labelname = m.str(1);
		smatch labels;
		if (!regex_match(labelname, labels, regexs::labelname)) goto error;
		int gotoLine=labelLine[labels.str(1)];
		if(gotoLine<1 || gotoLine>line) goto error;
		exec=gotoLine-1;
	}
	else if(regex_match(cmd,m,regexs::ife)){
		smatch varA,varB;
		string varAName=m.str(1),varBName=m.str(3);
		if(!regex_match(varAName,varA,regexs::var) || !regex_match(varBName,varB,regexs::var)) goto error;
		if(!v.hasVar(varA.str(1)) || !v.hasVar(varB.str(1))) goto error;
		if(v.getType(varA.str(1))!=v.getType(varB.str(1))) goto error;
		string op=m.str(2);
		if(v.getType(varA.str(1))==STR){
			if(op!="eq" && op!="neq") goto error;
			string valA=v.getStr(varA.str(1),mark),valB=v.getStr(varB.str(1),mark);
			if(op=="eq"){
				if(valA!=valB)tryJump(execLine);
			}
			else if(op=="neq"){
				if(valA==valB)tryJump(execLine);
			}
			else goto error;
		}
		else{
			int valA=v.getInt(varA.str(1),mark),valB=v.getInt(varB.str(1),mark);
			if(op=="eq"){
				if(valA!=valB)tryJump(execLine);
			}
			else if(op=="neq"){
				if(valA==valB)tryJump(execLine);
			}
			else if(op=="leq"){
				if(valA>valB)tryJump(execLine);
			}
			else if(op=="geq"){
				if(valA<valB)tryJump(execLine);
			}
			else if(op=="ls"){
				if(valA>=valB)tryJump(execLine);
			}
			else if(op=="gr"){
				if(valA<=valB)tryJump(execLine);
			}
			else goto error;
		}
	}
	else if(regex_match(cmd, m, regexs::defarray)) {
		string name = m.str(1);
		int size = sti(m.str(2));
		arrs.create(name, size, mark);
		if (mark) goto error;
	}
	else if(regex_match(cmd, m, regexs::putarr)) {
		smatch varA, varB;
		string varAName = m.str(1), varBName = m.str(2);
		int pos = sti(m.str(3));
		if (!regex_match(varAName, varA, regexs::var) || !regex_match(varBName, varB, regexs::arr)) goto error;
		if (!v.hasVar(varA.str(1)) || !arrs.hasArr(varB.str(1))) goto error;
		int val = v.getInt(varA.str(1), mark);
		if (mark) goto error;
		arrs.put(varB.str(1), pos, val, mark);
		if (mark == 1) goto error;
		if (mark == 2) goto runtime_error;
	}
	else if(regex_match(cmd, m, regexs::getarr)) {
		smatch varA, varB;
		string varAName = m.str(1), varBName = m.str(2);
		int pos = sti(m.str(3));
		if (!regex_match(varAName, varA, regexs::var) || !regex_match(varBName, varB, regexs::arr)) goto error;
		if (!v.hasVar(varA.str(1)) || !arrs.hasArr(varB.str(1))) goto error;
		int val = arrs.get(varB.str(1), pos, mark);
		if (mark) goto error;
		v.setVarInt(varB.str(1), val, mark);
		if (mark == 1) goto error;
		if (mark == 2) goto runtime_error;
	}
	else if(regex_match(cmd,m,regexs::final)){
		smatch varA;
		string varAName=m.str(1);
		if(!regex_match(varAName,varA,regexs::var)) goto error;
		v.setFinal(varA.str(1),mark);
		if(mark) goto error;
	}
	else if(regex_match(cmd,m,regexs::exitp)){
		exit(0);
	}
	else if(regex_match(cmd,m,regexs::ing)||regex_match(cmd,m,regexs::endif) || regex_match(cmd,m,regexs::label)){
		return 0;
	}
	else{
		cout << "未定义的关键字/语法" << endl;
		error:
			cout << "语法错误 第" << execLine << "行";
			return 1;
		runtime_error:
			cout << "运行时错误 第" << execLine << "行";
			return 1;
	}
	return 0;
}
map<int,string> code;
void tryJump(int l){
	int cnt=1;
	while(cnt&&l<line){
		l++;
		if(regex_match(code[l],m,regexs::ife))cnt++;
		if(regex_match(code[l],m,regexs::endif))cnt--;
	}
	if(cnt!=0){
		cout << "语法错误 if/endif不匹配";
		exit(0);
	}
	exec=l;
}
void run(string file){
	ifstream inf(file);
	char t[3000];
	string cmd;
	int cnt=0;
	while(inf.getline(t,2000)){
		cmd=cts(t);
		line++;
		code[line]=cmd;
		if(regex_match(code[line],m,regexs::ife))cnt++;
		if(regex_match(code[line],m,regexs::endif))cnt--;
		if(regex_match(code[line],m,regexs::label)){
			labelLine[m.str(1)] = line;
		}
	}
	if(cnt!=0){
		cout << "语法错误 if/endif不匹配";
		exit(0);
	}
	while(exec<line){
		exec++;
		if(code[exec]=="")continue;
		if(parse(code[exec],exec)){
			exit(0);
		}
	}
	inf.close();
}
signed main(signed argc,char** argv) {
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	if(argc==2){
		if(cts(argv[1])=="-h"){
			help:
			cout << "===============Jaba帮助===============" << endl;
			cout << "Jaba是基于Dr.张浩扬博士的Jvav的改进版" << endl;
			cout << "其拥有更快的执行速度和解析效率" << endl;
			cout << "采用物理机进行隔离，保证代码安全" << endl;
			cout << "Jaba使用JBRE进行解析" << endl;
			cout << endl;
			cout << "参数：jaba [-h] [-v] [-r <文件名>]" << endl;
			cout << "-h          查看此帮助" << endl;
			cout << "-v          查看JBRE版本" << endl;
			cout << "-r <文件名> 执行Jaba代码";
		}
		else if(cts(argv[1])=="-v"){
			cout << "Jaba Runtime Environment(JBRE) v1.0.0_u16";
		}
	}
	else if(argc==3){
		if(cts(argv[1])=="-r"){
			run(cts(argv[2]));
		}
	}
	else{
		goto help;
	}
	return 0;
}
// cout << m.length() << endl;
// cout << m.position() << endl;
// m.size()
