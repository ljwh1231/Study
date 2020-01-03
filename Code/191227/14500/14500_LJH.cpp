#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int** board;
bool** visited;
int ret = 0;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int dfs(int _i, int _j, int depth) {
    if(depth == 0) return board[_i][_j];
    visited[_i][_j] = true;
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        if(_i + di[i] >= 0 && _i + di[i] < N && _j + dj[i] >=0 && _j + dj[i] < M && visited[_i + di[i]][_j + dj[i]] == false) {
            sum = max(sum, dfs(_i + di[i], _j + dj[i], depth - 1));
        }
    }
    sum += board[_i][_j];
    visited[_i][_j] = false;
    return sum;
}

int main() {
    cin >> N >> M;
    board = new int*[N];
    visited = new bool*[N];
    for(int i = 0; i < N; i++) {
        board[i] = new int[M];
        visited[i] = new bool[M];
        fill(visited[i], visited[i] + M, false);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            ret = max(ret, dfs(i, j , 3));
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int sum = board[i][j];
            for(int d = 0; d < 4; d++) {
                if(i + di[d] >= 0 && i + di[d] < N && j + dj[d] >= 0 && j + dj[d] < M) {
                    sum += board[i + di[d]][j + dj[d]];
                }
            }
            for(int d = 0; d < 4; d++) {
                if(i + di[d] >= 0 && i + di[d] < N && j + dj[d] >= 0 && j + dj[d] < M) {
                    ret = max(ret, sum - board[i + di[d]][j + dj[d]]);
                    // cout << "no edge: " << sum - board[i + di[d]][j + dj[d]] << endl;
                } else {
                    // cout << "edge: " << sum << endl;
                    ret = max(ret, sum);
                }
            }
        }
    }

    cout << ret << endl;


}