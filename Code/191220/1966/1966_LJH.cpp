#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int n, m;
        int ret = 0;
        cin >> n >> m;
        vector<int> document(n, 0); // 원래 순서를 저장한 vector
        queue<int> printer; // printer queue
        map<int, int> cnt; // priority 별로 저장한 map(key : priority, value : number of data)
        for(int j = 0; j < n; j++) {
            cin >> document[j];
            printer.push(j);
            if(cnt.count(document[j]) == 0) cnt[document[j]] = 1;
            else cnt[document[j]]++;
        }
        auto prior = --cnt.end(); // 남은 data 중 priority 가장 큰 값
        while(true) {
            int cur = printer.front();
            if(document[cur] == prior->first) { // 현재 queue의 front값과 최댓값이 같을 때
                if(cur == m) { // 구하고자 하는 문서 순서
                    ret++;
                    break;
                }
                --(prior->second); // data 갯수 하나 줄이기
                if(prior->second == 0) { // 더이상 없을 때 map에서 제거
                    cnt.erase(prior->first);
                    prior = --cnt.end();
                }
                printer.pop();
                ret++;
            } else { // 같지 않을때
                printer.push(cur);
                printer.pop();
            }
        }
        cout << ret << "\n";
    }

    return 0;
}