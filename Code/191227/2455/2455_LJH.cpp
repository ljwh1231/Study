#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int maxP = 0;
    int cur = 0;
    for(int i = 0; i < 4; i++) {
        int up, down;
        cin >> down >> up;
        cur -= down;
        cur += up;
        maxP = max(cur, maxP);
    }

    cout << maxP << "\n";
    return 0;
}