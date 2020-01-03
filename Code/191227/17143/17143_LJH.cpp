#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

int r, c, m;
int dr[5] = { 0, -1, 1, 0, 0 };
int dc[5] = { 0, 0, 0, 1, -1 };
int board[101][101];

struct shark {
    int r, c, s, d, z;
};

inline bool operator<(const shark& a, const shark& b) {
    return a.r < b.r;
}

bool compare(shark a, shark b) {
    return a.z > b.z;
}

map< int, set<shark> > sharks;

void moveSharks() {
    vector<shark> changed;
    for(auto ii = sharks.begin(); ii != sharks.end(); ii++) {
        for(auto jj = (ii->second).begin(); jj != (ii->second).end(); jj++) {
            shark cur = *jj;
            int newR = cur.r + cur.s * dr[cur.d];
            int newC = cur.c + cur.s * dc[cur.d];
            int newD = cur.d;
            while(newR < 1 || newR > r) {
                if(newR < 1) {
                    newR = (newR - 1) * (-1) + 1;
                    newD = 2;
                } else if(newR > r) {
                    newR = r - (newR - r);
                    newD = 1;
                }
            }
            while(newC < 1 || newC > c) {
                if(newC < 1) {
                    newC = (newC - 1) * (-1) + 1;
                    newD = 3;
                } else if(newC > c) {
                    newC = c - (newC - c);
                    newD = 4;
                }
            }
            cur.r = newR;
            cur.c = newC;
            cur.d = newD;
            changed.push_back(cur);
        }
    }
    sharks.clear();
    memset(board, 0, sizeof(board));

    sort(changed.begin(), changed.end(), compare);
    for(auto it : changed) {
        if(board[it.r][it.c] > it.z) continue;
        sharks[it.c].insert(it);
        board[it.r][it.c] = it.z;
    }

}

int main() {
    memset(board, 0, sizeof(board));
    cin >> r >> c >> m;    
    for(int i = 0; i < m; i++) {
        shark temp;
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        temp.r = r; temp.c = c; temp.s = s; temp.d = d; temp.z = z;
        sharks[c].insert(temp);
        board[r][c] = z;
    }

    int pos = 1;
    int ret = 0;
    while(pos != c + 1) {
        if(!sharks[pos].empty()) {
            shark top = *sharks[pos].begin();
            ret += top.z;
            sharks[pos].erase(top);
        }
        moveSharks();
        pos++;
    }

    cout << ret << "\n";

    return 0;
}