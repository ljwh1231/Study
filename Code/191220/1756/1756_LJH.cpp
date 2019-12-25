#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int d, n;
    cin >> d >> n;
    vector<int> oven(d, 0);
    for(int i = 0; i < d; i++) {
        cin >> oven[i];
        if(i != 0) {
            oven[i] = min(oven[i - 1], oven[i]);
        }
    }
    vector<int> pizza(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> pizza[i];
    }

    int idx = d - 1;
    int s = 0;
    while(s != n) {
        if(oven[idx] < pizza[s]) {
            --idx;
        } else {
            ++s;
            --idx;
        }
    }
    if(idx + 2 <= 0) {
        cout << "0\n";
        return 0;
    }
    cout << idx + 2 << "\n";

    return 0;
    
}