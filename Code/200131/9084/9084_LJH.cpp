#include <iostream>
#include <vector>

using namespace std;

int dp[10001] = { 0, };

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        fill_n(dp, 10001, 0);
        int n, m;
        cin >> n;
        vector<int> coins(n, 0);

        for(int j = 0; j < n; j++) {
            cin >> coins[j];
        }

        cin >> m;

        dp[0] = 1;

        for(auto it : coins) {
            for(int j = it; j <= m; j++) {
                dp[j] = dp[j] + dp[j - it];
            }
        }

        cout << dp[m] << "\n";
    }
    
    return 0;
}