#include <iostream>

using namespace std;

int dp[1000] = { 0, };

int main() {
    int n;
    cin >> n; 
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    for(int i = 1; i < n; i++) dp[i] = 1001;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < i + 1 + arr[i]; j++) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }
    if(dp[n - 1] == 1001) {
        cout << -1 << "\n";
    } else {
        cout << dp[n - 1] << "\n";
    }

    return 0;
}