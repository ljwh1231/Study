#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> chu(n, 0);

    for(int i = 0; i < n; i++) cin >> chu[i];

    //sort 추 vector
    sort(chu.begin(), chu.end());

    vector<int> possible;
    possible.push_back(0);

    // possible에 있는 값에다가 추 값 더해보면서 1차이 나지 않을 때 possible의 마지막 vector값 + 1 출력
    for(int it : chu) {
        int curSize = possible.size();
        for(int i = 0; i < curSize; i++) {
            int val = it + possible[i];
            if(val == *possible.rbegin() + 1) {
                possible.push_back(val);
            }
            else if(val <= *possible.rbegin()) continue;
            else {
                cout << *possible.rbegin() + 1 << "\n";
                return 0;
            }
        }
    }

    cout << *possible.rbegin() + 1 << "\n";

    return 0;
}