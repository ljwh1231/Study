#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void d(int s, int c) {
    pq.push(make_pair(s, c));
    while(!pq.empty()) {
        auto cur = pq.top();
        for(auto it : graph[cur.first]) {
            if(cost[it.first] > cur.second + it.second) {
                cost[it.first] = cur.second + it.second;
                pq.push(make_pair(it.first, cost[it.first]));
            }
        }
        pq.pop();
    }
}

int n, m;
vector< pair<int, int> > graph[1001];
int cost[1001];
priority_queue< pair<int, int>, vector< pair<int, int> >, compare > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) cost[i] = 1e9;

    for(int i = 0; i < m; i++) {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back(make_pair(e, c));
    }
    int s, e;
    cin >> s >> e;
    cost[s] = 0;
    d(s, cost[s]);

    cout << cost[e] << "\n";
    return 0;
}