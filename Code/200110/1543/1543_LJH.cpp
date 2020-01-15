#include <iostream>

using namespace std;

int main() {
    string in, target;
    getline(cin, in);
    getline(cin, target);

    int tarSize = target.size();
    int ret = 0;
    
    for(int i = 0; i < in.size(); i++) {
        if(in.substr(i, tarSize) == target) {
            ret++;
            i += tarSize - 1;
        }
    }

    cout << ret << "\n";

    return 0;
}