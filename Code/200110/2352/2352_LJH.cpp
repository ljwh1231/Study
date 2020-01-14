#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> port(n, 0);
    vector<int> lis;

    for(int i = 0; i < n; i++) cin >> port[i];
    lis.push_back(0);

    for(int it : port) {
        if(it < *(lis.rbegin())) {
            auto idx = lower_bound(lis.begin(), lis.end(), it);
            *idx = it;
            continue;
        }
        lis.push_back(it);

    }
    cout << lis.size() - 1 << "\n";

    return 0;
}