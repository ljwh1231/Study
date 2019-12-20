#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int board[50][50];
int w, h;
int cnt = 0;

// 방향 array
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 새로운 x, y가 범위 내인지 확인
bool inRange(int y, int x) {
    if(x >= 0 && x < w && y >= 0 && y < h) return true;
    return false;
}

// bfs
void bfs(int y, int x) {
    int ret = 0;
    queue< pair<int, int> > pos;
    pos.push(make_pair(y, x));
    board[y][x] = 0;
    while(!pos.empty()) {
        for(int i = 0; i < 8; i++) {
            int new_y = pos.front().first + dy[i];
            int new_x = pos.front().second + dx[i];
            if(inRange(new_y, new_x)) {
                if(board[new_y][new_x] == 1) {
                    pos.push(make_pair(new_y, new_x));
                    board[new_y][new_x] = 0;    // 간 곳 0으로 변경
                }
            }            
        }
        pos.pop();
    }
}

int main() {
    while(cin >> w >> h) {
        if(w == 0 && h == 0) break;
        memset(board, 0, sizeof(board));        // board 0 초기화
        for(int i = 0 ; i < h; i++) {
            for(int j = 0; j < w; j++) {
                cin >> board[i][j];
            }
        }

        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(board[i][j] == 1) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
        cnt = 0;                                // 0으로 다시 초기화
    }

    return 0;
}