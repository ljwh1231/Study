#include <iostream>
#include <cstring>

using namespace std;

int n, l;
int board[100][100];
bool chk[100][100];

int ret = 0;

int abs(int num) {
    if(num > 0) return num;
    else return (-1) * num;
}
bool validRow(int r) {
    for(int i = 1; i < n; i++) {
        if(abs(board[r][i] - board[r][i - 1]) >= 2) return false;
        if(board[r][i] < board[r][i - 1]) {
            if(chk[r][i]) return false;
            chk[r][i] = true;
            for(int j = i + 1; j < i + l; j++) {
                if(j >= n) return false;
                if(board[r][j] != board[r][j - 1] || chk[r][j]) return false;
                chk[r][j] = true;
            }
        } else if(board[r][i] > board[r][i - 1]) {
            if(chk[r][i - 1]) return false;
            chk[r][i - 1] = true;
            for(int j = i - 2; j >= i - l; j--) {
                if(j < 0) return false;
                if(board[r][j] != board[r][j + 1] || chk[r][j]) return false;
                chk[r][j] = true;
            }
        }
    }
    return true;
}

bool validCol(int c) {
    for(int i = 1; i < n; i++) {
        if(abs(board[i][c] - board[i - 1][c]) >= 2) return false;
        if(board[i][c] < board[i - 1][c]) {
            if(chk[i][c]) return false;
            chk[i][c] = true;
            for(int j = i + 1; j < i + l; j++) {
                if(j >= n) return false;
                if(board[j][c] != board[j - 1][c] || chk[j][c]) return false;
                chk[j][c] = true;
            }
        } else if(board[i][c] > board[i - 1][c]) {
            if(chk[i - 1][c]) return false;
            chk[i - 1][c] = true;
            for(int j = i - 2; j >= i - l; j--) {
                if(j < 0) return false;
                if(board[j][c] != board[j + 1][c] || chk[j][c]) return false;
                chk[j][c] = true;
            }
        }
    }
    return true;
}

int main() {
    memset(board, 0, sizeof(board));
    memset(chk, 0, sizeof(chk));
    cin >> n >> l;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        if(validRow(i)) ret++;
        memset(chk, 0, sizeof(chk));
        if(validCol(i)) ret++;
        memset(chk, 0, sizeof(chk));
    }

    cout << ret << "\n";

    return 0;
}