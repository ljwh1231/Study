#include <iostream>
#include <vector>

using namespace std;

int dice[5] = { 0, 0, 0, 0, 0 };
int board[20][20];

int dy[5] = { 0, 1, -1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

int n, m, x, y, k;
int cur = 0;

bool roll(int dir) {
    int new_x = x + dx[dir];
    int new_y = y + dy[dir];
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m) {
        return false;
    }
    x = new_x;
    y = new_y;
    int temp = cur;
    if(dir == 1) {
        cur = dice[2];
        dice[2] = dice[0];
        dice[0] = dice[1];
        dice[1] = temp;
    } else if(dir == 2) {
        cur = dice[1];
        dice[1] = dice[0];
        dice[0] = dice[2];
        dice[2] = temp;
    } else if(dir == 3) {
        cur = dice[4];
        dice[4] = dice[0];
        dice[0] = dice[3];
        dice[3] = temp;
    } else if(dir == 4) {
        cur = dice[3];
        dice[3] = dice[0];
        dice[0] = dice[4];
        dice[4] = temp;
    }

    if(board[x][y] == 0) {
        board[x][y] = dice[0];
    } else {
        dice[0] = board[x][y];
        board[x][y] = 0;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ;j < m; j++) {
            cin >> board[i][j];
        }
    }

    vector<int> order(k, 0);
    vector<int> ret;
    for(int i = 0; i < k; i++) {
        cin >> order[i];
        if(roll(order[i])) {
            ret.push_back(cur);
        }
    }

    for(int i = 0; i < ret.size(); i++) {
        cout << ret[i] << "\n";
    }

    return 0;
}