#include <iostream>
#include <vector>

using namespace std;

// 현재 idx보다 이전 idx에 0이 몇번 나왔는지 세줌

int main() {
    int n;
    cin >> n;

    vector<int> order(n, 0);
    vector<int> ret(n, 0);
    for(int i = 0; i < n; i++) order[i] = i;

    for(int i = 1; i <= n; i++) {
        int cur;
        cin >> cur;
        auto it = find(order.begin(), order.end(), cur);
        int idx = distance(order.begin(), it);
        ret[idx] = i;
        order[idx] = -1;
        for(int j = idx + 1; j < n; j++) --order[j];
    }

    for(int it : ret) cout << it << " ";
    cout << "\n";
    return 0;
}