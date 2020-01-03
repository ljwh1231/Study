#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

vector< pair<int, int> > graph[20001];
priority_queue< pair<int, int>, vector< pair<int, int> >, compare > pq;
int cost[20001];

void d(int s, int c) {
    pq.push(make_pair(s, c));
    while(!pq.empty()) {
        auto cur = pq.top();
        if(cur.second != cost[cur.first]) {
            pq.pop();
            continue;
        }
        for(auto it : graph[cur.first]) {
            if(cost[it.first] > cur.second + it.second) {
                cost[it.first] = cur.second + it.second;
                pq.push(make_pair(it.first, cost[it.first]));
            }
        }
        pq.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cost[i] = 1e9;

    for(int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(make_pair(e, 1));
        graph[e].push_back(make_pair(s, 1));
    }

    cost[1] = 0;
    d(1, cost[1]);

    set<int> cand;
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        if(ret < cost[i]) {
            cand.clear();
            ret = cost[i];
            cand.insert(i);
        } else if(ret == cost[i]) cand.insert(i);
    }

    cout << *cand.begin() << " " << ret << " " << cand.size() << "\n";

    return 0;
}