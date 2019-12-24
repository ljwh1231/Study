#include <iostream>
#include <vector>
using namespace std;

struct node {
    int num;
    int cost;
};

int maxCost = 0;
int start = 0;
vector<node> tree[10001];

void dfs(int cur, int par, int curCost) {
    for(auto it : tree[cur]) {
        int tempCost = curCost;
        if(it.num != par) {
            tempCost += it.cost;
            dfs(it.num, cur, tempCost);
        }
    }
    if(curCost > maxCost) {
        maxCost = curCost;
        start = cur;
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        node start, end;
        int s, e, c;
        cin >> s >> e >> c;
        start.num = s; start.cost = c;
        end.num = e; end.cost = c;

        tree[s].push_back(end);
        tree[e].push_back(start);
    }
    // root 노드에서 먼저 제일 먼 node 찾기
    dfs(1, 0, 0);
    maxCost = 0;
    //찾은 node에서 제일 먼 node 찾기
    dfs(start, 0, 0);

    cout << maxCost << "\n";

    return 0;
}