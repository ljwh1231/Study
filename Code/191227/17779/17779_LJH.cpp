#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int board[21][21];
bool chk[21][21];
int res[5] = { 0, };

void divide(int y, int x, int d_1, int d_2) {
    // Area 5
    // Border
    for(int i = 0; i <= d_1; i++) {
        res[4] += board[y - i][x + i];
        res[4] += board[y + d_2 - i][x + d_2 + i];
        chk[y - i][x + i] = true;
        chk[y + d_2 - i][x + d_2 + i] = true;
    }
    for(int i = 0; i <= d_2; i++) {
        res[4] += board[y + i][x + i];
        res[4] += board[y - d_1 + i][x + d_1 + i];
        chk[y + i][x + i] = true;
        chk[y - d_1 + i][x + d_1 + i] = true;
    }
    // 한번씩 더 더한거 빼주기
    res[4] -= (board[y][x] + board[y - d_1][x + d_1] + board[y - d_1 + d_2][x + d_1 + d_2] + board[y + d_2][x + d_2]);

    // Area 5 내부
    for(int i = 1; i <= d_1; i++) {
        int idx = 0;
        while(!chk[y - d_1 + i][x + d_1 - (i - 1) + idx]) {
            res[4] += board[y - d_1 + i][x + d_1 - (i - 1) + idx];
            chk[y - d_1 + i][x + d_1 - (i - 1) + idx] = true;
            idx++;
        }
    }
    for(int i = 1; i <= d_2; i++) {
        int idx = 0;
        while(!chk[y + (i - 1)][x + i + idx]) {
            res[4] += board[y + (i - 1)][x + i + idx];
            chk[y + (i - 1)][x + i + idx] = true;
            idx++;
        }
    }
    // Area 1~4
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i < y && j <= x + d_1 && !chk[i][j]) {
                res[0] += board[i][j];
                chk[i][j] = true;
            } else if(i <= y - d_1 + d_2 && j > x + d_1 && !chk[i][j]) {
                res[1] += board[i][j];
                chk[i][j] = true;
            } else if(i > y - d_1 + d_2 && j >= x + d_2 && !chk[i][j]) {
                res[3] += board[i][j];
                chk[i][j] = true;
            } else if(i >= y && j < x + d_2 && !chk[i][j]) {
                res[2] += board[i][j];
                chk[i][j] = true;
            }
        }
    }

}

int main() {
    memset(board, 0, sizeof(board));
    cin >> n;

    int ret = 40000;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
    // O(N^6).... 더 효율적으로 돌릴 순 없을까
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int d_1 = 1; d_1 <= n; d_1++) {
                for(int d_2 = 1; d_2 <= n; d_2++) {
                    if(j + d_1 + d_2 < 1 || j + d_1 + d_2 > n) continue;
                    if(i - d_1 < 1 || i + d_2 > n) continue;
                    memset(chk, 0, sizeof(chk));
                    memset(res, 0, sizeof(res));
                    divide(i, j, d_1, d_2);
                    ret = min(ret, *max_element(res, res + 5) - *min_element(res, res + 5));
                }
            }
       }
    }
    cout << ret << "\n";

    return 0;
}