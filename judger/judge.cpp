#include <windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include <cmath>
#include <psapi.h>
#include <vector>
#include <fstream>
#include <tuple>
#define int long long

using namespace std;

DWORD TIMEOUT = 1000;
SIZE_T MEMORY_LIMIT = 256 * 1024 * 1024;
const DWORD POLL_INTERVAL = 30;

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

#define ACCEPTED 0
#define WRONG_ANSWER 1
#define TIME_LIMIT_EXCEEDED 2
#define MEMORY_LIMIT_EXCEEDED 3
#define RUNTIME_ERROR 4
#define SYSTEM_ERROR 5

void changeTextColor(int value){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), value);
}

SIZE_T GetProcessMemoryUsage(HANDLE hProcess) {
	PROCESS_MEMORY_COUNTERS_EX pmc;
	GetProcessMemoryInfo(hProcess, reinterpret_cast<PROCESS_MEMORY_COUNTERS*>(&pmc), sizeof(pmc));
	return pmc.PrivateUsage;
}

bool CompileProgram(string filename) {
	string command = "g++ " + filename + ".cpp -o " + filename + ".exe -DLOCAL -O2 -std=c++17 -static -Wl,--stack=51200000000";
	return system(command.c_str()) == 0;
}

bool diff_allcomp(string file1, string file2) {
	string command = "fc " + file1 + " " + file2 + " > nul";
	return system(command.c_str()) == 0;
}

bool diff_spj(string spj, string input, string output, string answer) {
	string command = spj + " " + input + " " + output + " " + answer + "";
	return system(command.c_str()) == 0;
}

bool isSpj;
string spjName;

struct JudgeInfo {
	int result;
	SIZE_T memory, time;
	JudgeInfo() : result(SYSTEM_ERROR), memory(0), time(0) {}
};

JudgeInfo judgeProgram(string filename, string input, string output, string answer) {
	JudgeInfo result;
	result.result = SYSTEM_ERROR;
	SECURITY_ATTRIBUTES sa, sb, sc;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = NULL;
    sa.bInheritHandle = TRUE;
	sb.nLength = sizeof(SECURITY_ATTRIBUTES);
	sb.lpSecurityDescriptor = NULL;
	sb.bInheritHandle = TRUE;
	sc.nLength = sizeof(SECURITY_ATTRIBUTES);
	sc.lpSecurityDescriptor = NULL;
	sc.bInheritHandle = TRUE;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	si.dwFlags |= STARTF_USESTDHANDLES;
	HANDLE hInput = CreateFile(input.c_str(), GENERIC_READ, FILE_SHARE_READ, &sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	HANDLE hOutput = CreateFile(output.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE, &sb, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	si.hStdInput = hInput;
	si.hStdOutput = hOutput;
	si.hStdError = CreateFile("NUL", GENERIC_WRITE, FILE_SHARE_WRITE, &sc, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	string command = filename;
	bool success = CreateProcess(NULL, (LPSTR) command.c_str(), NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	if (success) {
		DWORD startTime = GetTickCount64();
		while (true) {
			DWORD exitCode;
			GetExitCodeProcess(pi.hProcess, &exitCode);
			if (exitCode != STILL_ACTIVE) break;
			DWORD currentTime = GetTickCount64();
			if (currentTime - startTime >= TIMEOUT) {
				result.result = TIME_LIMIT_EXCEEDED;
				TerminateProcess(pi.hProcess, 1);
				break;
			}
			SIZE_T memoryUsage = GetProcessMemoryUsage(pi.hProcess);
			result.memory = max(result.memory, memoryUsage);
			if (memoryUsage > MEMORY_LIMIT) {
				result.result = MEMORY_LIMIT_EXCEEDED;
				TerminateProcess(pi.hProcess, 1);
				break;
			}
			Sleep(POLL_INTERVAL);
		}
		DWORD currentTime = GetTickCount64();
		result.time = currentTime - startTime;
		DWORD exitCode;
		GetExitCodeProcess(pi.hProcess, &exitCode);
		if (exitCode != 0 && result.result == SYSTEM_ERROR) {
			result.result = RUNTIME_ERROR;
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		CloseHandle(hInput);
		CloseHandle(hOutput);
		Sleep(100);
		if (result.result != SYSTEM_ERROR) {
			return result;
		}
		const bool differ = isSpj ? diff_spj(spjName, input, output, answer) :
		   							diff_allcomp(output, answer);
		if (differ) {
			result.result = ACCEPTED;
		} else {
			result.result = WRONG_ANSWER;
		}
	} else {
		result.result = SYSTEM_ERROR;
	}
	return result;
}

vector <tuple <string, string, int> > taskList;

struct TaskInfo {
	int timeLimit;
	int memoryLimit;
	string filename;
};

pair <int, int> judgeTask(TaskInfo taskInfo) {
	string filename = taskInfo.filename;
	int count_judged = 0;
	int final_score = 0, tot_score = 0;
	for (auto [input, answer, score] : taskList) {
		cerr << "Testcase " << count_judged + 1 << " ";
		string output = filename + ".tmp.out";
		tot_score += score;
		JudgeInfo res = judgeProgram(filename + ".exe", input, output, answer);
		int sc = 0;
		int result = res.result;
		if (result == ACCEPTED) {
			changeTextColor(COLOR_LIGHTGREEN);
			cerr << "Accepted             ";
			sc = score;
		} else if (result == WRONG_ANSWER) {
			changeTextColor(COLOR_RED);
			cerr << "Wrong Answer         ";
		} else if (result == TIME_LIMIT_EXCEEDED) {
			changeTextColor(COLOR_YELLOW);
			cerr << "Time Limit Exceeded  ";
		} else if (result == MEMORY_LIMIT_EXCEEDED) {
			changeTextColor(COLOR_YELLOW);
			cerr << "Memory Limit Exceeded";
		} else if (result == RUNTIME_ERROR) {
			changeTextColor(COLOR_PURPLE);
			cerr << "Runtime Error        ";
		} else if (result == SYSTEM_ERROR) {
			changeTextColor(COLOR_GRAY);
			cerr << "System Error         ";
		}
		changeTextColor(COLOR_WHITE);
		count_judged++;
		final_score += sc;
		fprintf(stderr, "\t%lld/%lld pts | %.3lf sec | %.2lf MB\n", sc, score, res.time / 1000.0, res.memory / 1024.0 / 1024.0);
		cerr << "--------------------------------" << endl;
	}
	return make_pair(final_score, tot_score);
}

TaskInfo loadTask(string filename) {
	TaskInfo tskInfo;
	ifstream fin(filename);
	string name, spj;
	fin >> name >> spj;
	if (spj == "spj") {
		isSpj = true;
		fin >> spjName;
	}
	else if (spj == "all-diff") {
		isSpj = false;
	}
	else {
		cerr << "Invalid spj type." << endl;
		exit(1);
	}
	tskInfo.filename = name;
	fin >> tskInfo.timeLimit >> tskInfo.memoryLimit;
	string input, output;
	int score;
	while (fin >> input >> output >> score) {
		taskList.push_back(make_tuple(input, output, score));
	}
	fin.close();
	return tskInfo;
}

void cleanUp(string filename) {
	system(("del " + filename + ".exe").c_str());
	system("del *.tmp.out");
}

signed main(signed argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Usage: judge <conf>" << endl;
		return 1;
	}
	TaskInfo taskInfo = loadTask(argv[1]);
	if (!CompileProgram(taskInfo.filename)) {
		changeTextColor(COLOR_DARKYELLOW);
		cerr << "Compilation error." << endl;
		changeTextColor(COLOR_WHITE);
		return 1;
	}
	TIMEOUT = taskInfo.timeLimit;
	MEMORY_LIMIT = taskInfo.memoryLimit * 1024 * 1024;
	cerr << "Compiled successfully." << endl;
	auto result = judgeTask(taskInfo);
	cerr << "Final score: " << result.first << "/" << result.second << " pts" << endl;
	Sleep(500);
	cleanUp(taskInfo.filename);
	return 0;
}
