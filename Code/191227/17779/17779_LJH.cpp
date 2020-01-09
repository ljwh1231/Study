#include <iostream>
#include <cstring>

using namespace std;

int n;
int board[20][20];

int main() {
    memset(board, 0, sizeof(board));
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= n - 1; j++) {
            
        }
    }
}