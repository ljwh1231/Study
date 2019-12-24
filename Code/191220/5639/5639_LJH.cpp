#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int tree[1000001][2];

void postorder(int root) {
    if(tree[root][0] != 0) postorder(tree[root][0]);
    if(tree[root][1] != 0) postorder(tree[root][1]);
    cout << root << "\n";
}

int main() {
    int cur;
    int root;
    cin >> root;
    while(cin >> cur) {
        int start = root;
        while(true) {
            if(start > cur) {
                if(tree[start][0] != 0) start = tree[start][0];
                else {
                    tree[start][0] = cur;       
                    break;
                }
            } else {
                if(tree[start][1] != 0) start = tree[start][1];
                else {
                    tree[start][1] = cur;
                    break;
                }
            }
        }
    }
    postorder(root);
    return 0;
}