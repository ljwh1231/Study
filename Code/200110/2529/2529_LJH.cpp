#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(char op, int l, int r) {
    if(op == '<') {
        return (l < r) ? true : false;
    } else {
        return (l > r) ? true : false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<char> ineq;
    for(int i = 0; i < n; i++) {
        char tmp;
        cin >> tmp;
        ineq.push_back(tmp);
    }
    vector<int> maxInit, minInit;
    int cnt = 0;
    while(cnt != n + 1) {
        maxInit.push_back(9 - cnt);
        minInit.push_back(cnt);
        cnt++;
    }

    do {
        bool flag = true;
        for(int i = 0; i < ineq.size(); i++) {
            if(!isValid(ineq[i], maxInit[i], maxInit[i + 1])) {
                flag = false;
                break;
            }
        }
        if(flag) break;
    }while(prev_permutation(maxInit.begin(), maxInit.end()));


    do {
        bool flag = true;
        for(int i = 0; i < ineq.size(); i++) {
            if(!isValid(ineq[i], minInit[i], minInit[i + 1])) {
                flag = false;
                break;
            }
        }
        if(flag) break;
    }while(next_permutation(minInit.begin(), minInit.end()));

    for(int it : maxInit) cout << it;
    cout << "\n";
    for(int it : minInit) cout << it;
    cout << "\n";

    return 0;
}