#include <iostream>
#include <vector>

using namespace std;

int dp[41];

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vip(m, 0);
    for(int i = 0; i < m; i++) {
        cin >> vip[i];
    }
    dp[0] = 1; dp[1] = 1; dp[2] = 2;
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    
    int base = 0;
    int ret = 1;
    for(auto it : vip) {
        ret *= dp[it - base - 1];
        base = it;
    }
    ret *= dp[n - base];

    cout << ret << "\n";

    return 0;
}