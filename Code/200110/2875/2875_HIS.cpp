#include <iostream>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int r_n=0;
    int r_m=0;

    int team = 0;
    if(n < m*2) { //  n 기준 팀 조직
        team = n / 2;
    }
    else { // m 기준 팀 조직
        team = m;
    }
    // 팀 만들고 남은 인원
    r_n = n - team*2;
    r_m = m - team;

    // 남은 인원으로 인턴 못보내면
    // 팀에서 인턴 보내야 함
    if(r_n+r_m < k){
        k -= (r_n+r_m);
        team -= (k/3);
        if(k%3!=0) team -= 1;
    }

    cout << team << '\n';
}