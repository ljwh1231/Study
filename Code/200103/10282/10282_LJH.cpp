#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <map>

using namespace std;

vector< pair<int, int> > graph[10001];
int cost[10001];
int ret;
map<int, bool> chk;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void dij(int s, int c) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, compare > pq;
    pq.push(make_pair(s, c));
    chk[s] = true;
    while(!pq.empty()) {
        auto cur = pq.top();
        if(cost[cur.first] != cur.second) {
            pq.pop();
            continue;
        }
        for(auto it : graph[cur.first]) {
            if(cost[it.first] > cur.second + it.second) {
                chk[it.first] = true;
                cost[it.first] = cur.second + it.second;
                pq.push(make_pair(it.first, cost[it.first]));
            }
        }
        pq.pop();
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        ret = 0;
        chk.clear();
        int n, d, c;
        cin >> n >> d >> c;
        for(int j = 1; j <= n; j++) {
            graph[j].clear();
            cost[j] = 1e9;
        }

        for(int j = 0; j < d; j++) {
            int s, e, cost;
            cin >> s >> e >> cost;
            graph[e].push_back(make_pair(s, cost));
        }

        cost[c] = 0;

        dij(c, cost[c]);

        for(int j = 1; j <= n; j++) {
            if(cost[j] == 1e9) continue;
            ret = max(ret, cost[j]);
        }
        cout << chk.size() << " " << ret << "\n";
    }
    return 0;
}