#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > m;
string ret;

void merge_str() {
    int cur_size = ret.size();
    if(ret.substr(cur_size - 4) == "1111") {
        ret = ret.substr(0, cur_size - 5) + "1";
    } else if(ret.substr(cur_size - 4) == "0000") {
        ret = ret.substr(0, cur_size - 5) + "0";
    } else {
        ret += ")";
    }
}

void dc(int r_s, int r_e, int c_s, int c_e) {
    ret += "(";
    if(r_s + 2 == r_e && c_s + 2 == c_e) {
        for(int i = r_s; i < r_e; i++) {
            for(int j = c_s; j < c_e; j++) {
                ret += to_string(m[i][j]);
            }
        }
        return;
    }
    int r_mid = (r_e + r_s) / 2;
    int c_mid = (c_e + c_s) / 2;
    int cur_size = ret.size();
    dc(r_s, r_mid, c_s, c_mid);
    merge_str();
    dc(r_s, r_mid, c_mid, c_e);
    merge_str();
    dc(r_mid, r_e, c_s, c_mid);
    merge_str();
    dc(r_mid, r_e, c_mid, c_e);
    merge_str();
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string in;
        cin >> in;
        vector<int> row;
        for(int j = 0; j < n; j++) {
            row.push_back(in[j] - 48);
        }
        m.push_back(row);
    }
    if(n == 1) {
        cout << m[0][0] << "\n";
        return 0;
    }

    dc(0, n, 0, n);
    ret += ")";
    if(ret.size() == 6) {
        if(ret.substr(1, 4) == "1111") ret = "1";
        else if(ret.substr(1, 4) == "0000") ret = "0";
    }
    cout << ret << "\n";

    return 0;

}