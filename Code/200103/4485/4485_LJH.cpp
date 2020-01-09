#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int n;
int cave[125][125];
int cost[125][125];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return cost[a.first][a.second] > cost[b.first][b.second];
    }
};

bool isRange(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void d(int r, int c) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, compare > pq;
    pq.push(make_pair(r, c));
    while(!pq.empty()) {
        auto cur = pq.top();
        for(int i = 0; i < 4; i++) {
            int newR = cur.first + dr[i];
            int newC = cur.second + dc[i];
            if(isRange(newR, newC)) {
                if(cost[newR][newC] > cost[cur.first][cur.second] + cave[newR][newC]) {
                    cost[newR][newC] = cost[cur.first][cur.second] + cave[newR][newC];
                    pq.push(make_pair(newR, newC));
                }
            }
        }
        pq.pop();
    }
}

int main() {
    int it = 1;
    while(cin >> n) {
        if(n == 0) break;
        memset(cave, 0, sizeof(cave));
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cost[i][j] = 1e9;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> cave[i][j];
            }
        }

        cost[0][0] = cave[0][0];
        d(0, 0);
        cout << "Problem " << it << ": " << cost[n - 1][n - 1] << "\n";
        it++;
    }
    return 0;
}