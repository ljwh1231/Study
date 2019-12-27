#include <iostream>
#include <cstring>

using namespace std;

string gear[5];
bool rot[5];

void rotateGear(int idx, int dir) {
    rot[idx] = true;
    if((idx + 1 <= 4) && (gear[idx][2] != gear[idx + 1][6]) && !rot[idx + 1]) {
        rotateGear(idx + 1, (-1) * dir);
    }
    if((idx - 1 >= 1) && (gear[idx][6] != gear[idx - 1][2]) && !rot[idx - 1]) {
        rotateGear(idx - 1, (-1) * dir);
    }
    if(dir == 1) {
        gear[idx].insert(gear[idx].begin(), gear[idx][7]);
        gear[idx] = gear[idx].substr(0, 8);
    } else {
        gear[idx].insert(gear[idx].end(), gear[idx][0]);
        gear[idx] = gear[idx].substr(1, 8);
    }
}

int main() {    
    memset(rot, 0, sizeof(rot));
    
    for(int i = 1; i <= 4; i++) {
        cin >> gear[i];
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int idx, dir;
        cin >> idx >> dir;
        rotateGear(idx, dir);
        memset(rot, 0, sizeof(rot));
    }

    int ret = 0;
    for(int i = 1; i <= 4; i++) {
        if(gear[i][0] == '1') {
            ret += (1 << (i - 1));
        }
    }

    cout << ret << "\n";

    return 0;

}