#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n, p;
    cin >> n >> p;
    stack<int> sound[7];

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int sNum, pNum;
        cin >> sNum >> pNum;

        if(sound[sNum].empty()) {
            sound[sNum].push(pNum);
            cnt++;
        }
        else {
            if(sound[sNum].top() < pNum) {
                sound[sNum].push(pNum);
                cnt++;
            } else {
                while(!sound[sNum].empty() && (sound[sNum].top() > pNum)) {
                    sound[sNum].pop();
                    cnt++;
                }
                if(!sound[sNum].empty() && (sound[sNum].top() == pNum)) continue;
                sound[sNum].push(pNum);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;

}