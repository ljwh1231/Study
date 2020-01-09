#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 40;
int numDays;
int table[MAX][2];
int DP[MAX];

int main(){
    freopen("input.txt","r",stdin);
    cin>>numDays;
    for(int i=1;i<=numDays;i++){
        cin>>table[i][0]>>table[i][1];
    }
    for(int i=numDays;i>=1;i--){
        if(table[i][0]<=numDays-i+1) DP[i]=max(table[i][1]+DP[table[i][0]+i],DP[i+1]);
        else DP[i]=DP[i+1];
    }
    int maxVal=0;
    for(int i=1;i<=numDays;i++){
        if(maxVal<DP[i]) maxVal=DP[i];
    }
    cout<<maxVal<<endl;
    return 0;
}