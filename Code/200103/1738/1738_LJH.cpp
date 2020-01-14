#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct edge {
    int s, e, c;
};

int INF = 1e9 * 2 + 1;
vector<int> path[101];
queue<edge> q;

int d[101];

bool isInPath(int tar, int s, int e) {
    if(find(path[tar].begin(), path[tar].end(), s) != path[tar].end() && find(path[tar].begin(), path[tar].end(), e) != path[tar].end()) {
        return true;
    }
    return false;
}

bool bf(int v, int e) {
    int loc = v;
    while(v != 1) {
        for(int ii = 0; ii < e; ii++) {
            edge cur = q.front();
            if(d[cur.s] + cur.c > d[cur.e]) {
                d[cur.e] = d[cur.s] + cur.c;
                path[cur.e] = path[cur.s];
                path[cur.e].push_back(cur.e);
            }
            q.pop();
            q.push(cur);
        }
        --v;
    }
    while(!q.empty()) {
        edge cur = q.front();
        if(d[cur.s] + cur.c > d[cur.e]) {
            if(isInPath(loc, cur.s, cur.e)) return false;
        }
        q.pop();
    }
    return true;
}

int main() {
    int v, e;
    cin >> v >> e;

    for(int i = 0; i < e; i++) {
        edge tmp;
        cin >> tmp.s >> tmp.e >> tmp.c;
        q.push(tmp);
    }

    fill(d + 1, d + 1 + v, INF * (-1));
    d[1] = 0;
    for(int i = 1; i <= v; i++) {
        path[i].push_back(i);
    }
    
    if(bf(v, e)) {
        if(find(path[v].begin(), path[v].end(), 1) != path[v].end()) {
            for(int i : path[v]) {
                cout << i << " ";
            }
            cout << "\n";
        } else {
            cout << "-1\n";
        }
    } else cout << "-1\n";

    return 0;

}