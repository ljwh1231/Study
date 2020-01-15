#include <iostream>
#include <stack>
#include <deque>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int final = n - k;

    deque<char> s;
    string in;
    cin >> in;
    for(int it = 0; it < in.size(); it++) {
        while(k != 0 && !s.empty() && in[it] > s.back()) {
            s.pop_back();
            k--;
        }
        s.push_back(in[it]);
    }
    for(;k > 0; k--) {
        s.pop_back();
    }

    for(int i = 0; i < final; i++) {
        cout << s.front();
        s.pop_front();
    }
    cout << "\n";

    return 0;
}