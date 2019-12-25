#include <iostream>
#include <stack>

using namespace std;

int main() {
    string paren;
    cin >> paren;
    stack<string> s;
    int ret = 0;

    for(int i = 0; i < paren.size(); i++) {
        if(paren[i] == '(' || paren[i] == '[') { // 열린 괄호 push
            string str(1, paren[i]);
            s.push(str);
        } else if(paren[i] == ')') {
            if(s.empty()) { // 닫힌 괄호 나왔을 때 stack 비었으면 0
                cout << 0 << "\n";
                return 0;
            }
            int subSum = 0;
            while(true) {
                if(s.empty()) { // stack 비었으면 0
                    cout << 0 << "\n";
                    return 0;
                }
                if(s.top() == "(") { // 올바른 문자열
                    if(subSum == 0) {
                        s.pop();
                        s.push(to_string(2));
                        break;
                    } else {
                        s.pop();
                        s.push(to_string(2 * subSum));
                        break;
                    }
                } else if(s.top() == "[") { // 올바르지 않은 문자열
                    cout << 0 << "\n";
                    return 0;
                }
                else {
                    subSum += stoi(s.top()); // 괄호 안 숫자들 다 sum
                    s.pop();
                }
            }
        } else if(paren[i] == ']') {
            if(s.empty()) {
                cout << 0 << "\n";
                return 0;
            }
            int subSum = 0;
            while(true) {
                if(s.empty()) {
                    cout << 0 << "\n";
                    return 0;
                }
                if(s.top() == "[") {
                    if(subSum == 0) {
                        s.pop();
                        s.push(to_string(3));
                        break;
                    } else {
                        s.pop();
                        s.push(to_string(3 * subSum));
                        break;
                    }
                } else if(s.top() == "(") {
                    cout << 0 << "\n";
                    return 0;
                }
                else {
                    subSum += stoi(s.top());
                    s.pop();
                }
            }
        }
    }
    while(!s.empty()) {
        if(s.top() == "(" || s.top() == "[") {
            ret = 0;
            break;
        }
        ret += stoi(s.top());
        s.pop();
    }

    cout << ret << "\n";
    return 0;
}