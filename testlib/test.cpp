#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

// 检查括号序列是否合法
bool isValidSequence(const string& sequence) {
    stack<char> s;
    for (char c : sequence) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        } else {
            if (s.empty()) return false;
            char top = s.top();
            if ((c == ')' && top == '(') ||
                (c == ']' && top == '[') ||
                (c == '}' && top == '{')) {
                s.pop();
            } else {
                return false;
            }
        }
    }
    return s.empty();
}

// 生成随机合法括号序列
string generateRandomSequence(int length) {
    vector<char> brackets = {'(', ')', '[', ']', '{', '}'};
    string sequence;
    int balance[3] = {0, 0, 0}; // 分别存储 (,[,{ 的平衡情况

    while (sequence.length() < length) {
        int idx = rand() % 6;
        char ch = brackets[idx];

        if (ch == '(') {
            sequence.push_back(ch);
            balance[0]++;
        } else if (ch == '[') {
            sequence.push_back(ch);
            balance[1]++;
        } else if (ch == '{') {
            sequence.push_back(ch);
            balance[2]++;
        } else if (ch == ')' && balance[0] > 0) {
            sequence.push_back(ch);
            balance[0]--;
        } else if (ch == ']' && balance[1] > 0) {
            sequence.push_back(ch);
            balance[1]--;
        } else if (ch == '}' && balance[2] > 0) {
            sequence.push_back(ch);
            balance[2]--;
        }
    }
    return sequence;
}

string generateParenthesisSequence(int minLen, int maxLen) {
    int length = rand() % (maxLen - minLen + 1) + minLen;
    string sequence;
    do {
        sequence = generateRandomSequence(length);
    } while (!isValidSequence(sequence));
    return sequence;
}

int main() {
    srand(time(0));  // 初始化随机数种子

    int minLen = 50;
    int maxLen = 50;

    string sequence = generateParenthesisSequence(minLen, maxLen);
    cout << "生成的合法括号序列: " << sequence << endl;

    return 0;
}
