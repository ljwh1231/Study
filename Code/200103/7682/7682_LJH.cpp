#include <iostream>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> p;

char board[3][3];
int oCount, xCount, dotCount;

p process() {
    p ret = make_pair(0, 0);
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        if(board[1][1] == 'X') ret.first += 1;
        else if(board[1][1] == 'O') ret.second += 1;
    }

    for(int i = 0; i < 3; i++) {
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            if(board[i][i] == 'X') ret.first += 1;
            else if(board[i][i] == 'O') ret.second += 1;
        }
    }
    
    return ret;
}

int main() {
    string t;
    while(cin >> t) {
        oCount = 0; xCount = 0; dotCount = 0;
        if(t == "end") break;

        for(int i = 0; i < t.size(); i++) {
            board[i / 3][i % 3] = t[i];
            if(t[i] == 'O') oCount++;
            else if(t[i] == 'X') xCount++;
            else dotCount++;
        }

        p bingoCount = process();
        if(dotCount != 0) {
            if(bingoCount.first == 0 && bingoCount.second == 0) {
                cout << "invalid\n";
                continue;
            }
        }
        if(xCount == oCount) {
            if(bingoCount.first != 0) cout << "invalid\n";
            else if(bingoCount.second == 0 || bingoCount.second >= 2) cout << "invalid\n";
            else cout << "invalid\n";
        } else if(xCount == oCount + 1) {
            if(bingoCount.second != 0) cout << "invalid\n";
            else if(bingoCount.first >= 2) cout << "invalid\n";
            else cout << "valid\n";
        } else {
            cout << "invalid\n";
        }
    }

    return 0;
}