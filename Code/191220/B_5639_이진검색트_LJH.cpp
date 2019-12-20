#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, vector<int> > tree;

void postorder(int i) {
    if(tree[i][1] != 0) postorder(tree[i][1]);
    if(tree[i][2] != 0) postorder(tree[i][2]);
    cout << i << "\n";
}

int main() {
    vector<int> pre;
    int tmp;
    while(cin >> tmp) pre.push_back(tmp);

    for(int i = 0; i < pre.size(); i++) {
        if(tree.empty() || tree.count(pre[i]) == 0) {
            vector<int> temp(3, 0);
            tree[pre[i]] = temp;
        }
        if(i == 0) {
            tree[pre[i]][0] = 0;
            continue;
        }
        if(pre[i] < pre[i - 1]) {
            tree[pre[i]][0] = pre[i - 1];
            tree[pre[i - 1]][1] = pre[i];
        } else {
            int tempP = pre[i - 1];
            while(tempP != 0 && (tree[tempP][0] < pre[i])) {
                tempP = tree[tempP][0];
            }
            if(tempP == 0) {
                tempP = pre[0];
                while(tree[tempP][2] != 0) tempP = tree[tempP][2];
                tree[tempP][2] = pre[i];
                tree[pre[i]][0] = tempP;
            } else {
                tree[tempP][2] = pre[i];
                tree[pre[i]][0] = tempP;
            }
        }    
    }
    
    postorder(pre[0]);
    return 0;
}