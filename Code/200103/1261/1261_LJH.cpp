#include <iostream>
#include <utility>
#include <queue>
#include <cstring>

using namespace std;

int m, n;
int board[100][100];
int cost[100][100];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return cost[a.first][a.second] > cost[b.first][b.second];
    }
};

bool inRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}

void d(int r, int c) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, compare > pq;
    pq.push(make_pair(r, c));

    while(!pq.empty()) {
        auto cur = pq.top();
        for(int i = 0; i < 4; i++) {
            int newR = cur.first + dr[i];
            int newC = cur.second + dc[i];
            if(inRange(newR, newC)) {
                if(cost[newR][newC] > cost[cur.first][cur.second] + board[newR][newC]) {
                    cost[newR][newC] = cost[cur.first][cur.second] + board[newR][newC];
                    pq.push(make_pair(newR, newC));
                }
            }
        }
        pq.pop();
    }
}

int main() {
    cin >> m >> n;
    memset(board, 0, sizeof(board));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cost[i][j] = 1e9;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            board[i][j] = tmp - 48;
        }
    cost[0][0] = 0;
    d(0, 0);
    cout << cost[n - 1][m - 1] << "\n";

    return 0;
}