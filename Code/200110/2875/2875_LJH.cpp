#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int ret = min(n / 2, m); // 팀 수
    
    // 남은 인원 수가 k보다 작으면 팀 수 줄임
    while(n + m - ret * 3 < k) {
        --ret;
    }

    cout << ret << "\n";

    return 0;
}