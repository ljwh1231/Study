#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char c) { // operator check
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') return true;

    return false;
}

int priority(char c) { // priority check
    if(isOperator(c)) {
        if(c == '+' || c == '-') return 1;
        else if(c == '*' || c == '/') return 2;
        else if(c == '(' || c == ')') return 0;
    }
    return -1;
}

int main() {
    string inorder, postorder;
    cin >> inorder;
    stack<char> s;

    for(int i = 0; i < inorder.length(); i++) {
        if(isOperator(inorder[i])) { // operator일때
            int prior = priority(inorder[i]);
            if(s.empty()) {
                s.push(inorder[i]);
                continue;
            }
            if(prior != 0) {
                if(prior > priority(s.top())) s.push(inorder[i]);
                else {
                    while(!s.empty() && (priority(s.top()) >= prior)) {
                        postorder.push_back(s.top());
                        s.pop();
                    }
                    s.push(inorder[i]);
                }
            } else if(inorder[i] == '(') {
                s.push(inorder[i]);
            } else if(inorder[i] == ')') {
                while(s.top() != '(') {
                    postorder.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
        } else {
            postorder.push_back(inorder[i]);
        }
    }
    while(!s.empty()) {
        postorder.push_back(s.top());
        s.pop();
    }

    cout << postorder << endl;

    return 0;
}