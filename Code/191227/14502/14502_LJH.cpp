#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int board[8][8], tmp[8][8];
int maxZero = 0;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

queue< pair<int, int> > virusQ;
vector< pair<int, int > > virus;

bool isRange(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void spread() {
    int before[8][8];
    memcpy(before, tmp, sizeof(tmp));
    for(auto it : virus) virusQ.push(it);
    while(!virusQ.empty()) {
        auto cur = virusQ.front();
        for(int i = 0; i < 4; i++) {
            int newR = cur.first + dr[i];
            int newC = cur.second + dc[i];
            if(isRange(newR, newC)) {
                if(tmp[newR][newC] == 0) {
                    virusQ.push(make_pair(newR, newC));
                    tmp[newR][newC] = 2;
                }
            }
        }
        virusQ.pop();
    }
    int curZero = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmp[i][j] == 0) curZero++;
        }
    }
    maxZero = max(maxZero, curZero);
    memcpy(tmp, before, sizeof(before));
}

void wall(int r, int c, int cnt) {
    if(cnt == 3) {
        spread();
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(tmp[i][j] == 0) {
                tmp[i][j] = 1;
                wall(i, j, cnt + 1);
                tmp[i][j] = 0;
            }
        }
    }

}

int main() {
    cin >> n >> m;
    memset(board, 0, sizeof(board));
    memset(tmp, 0, sizeof(tmp));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 0) {
                memcpy(tmp, board, sizeof(board));
                tmp[i][j] = 1;
                wall(i, j, 1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << maxZero << "\n";

    return 0;
}