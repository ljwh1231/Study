#include <iostream>
#include <cstring>

using namespace std;

int dp[20];
int t[16];
int p[16];

int main() {
    memset(dp, 0, sizeof(dp));

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[n + 1] << "\n";

    return 0;
}