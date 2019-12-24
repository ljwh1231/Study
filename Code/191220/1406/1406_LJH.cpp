#include <iostream>
#include <list>

using namespace std;

list<char> ret;

int main() {
    string initStr;
    cin >> initStr;
    for(int i = 0; i < initStr.size(); i++) ret.push_back(initStr[i]);

    auto it = ret.end();

    int command;
    cin >> command;

    for(int i = 0; i < command; i++) {
        char cmd;
        cin >> cmd;
        if(cmd == 'L' && it != ret.begin()) it--;
        else if(cmd == 'D' && it != ret.end()) it++;
        else if(cmd == 'B'&& it != ret.begin()) {
            auto cur = it;
            ret.erase(--cur);
        } else if(cmd == 'P') {
            char newChar;
            cin >> newChar;
            ret.insert(it, newChar);
        }
    }

    for(auto i = ret.begin(); i != ret.end(); i++) cout << *i;
    cout << "\n";

    return 0;

}