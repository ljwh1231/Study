#include <iostream>
#include <vector>
#define MAX 9
using namespace std;

int k;

char op[MAX+1];
bool check[MAX+1];

vector <char> temp;
vector <char> ans_min, ans_max;

void func(int cnt, bool b){
    // 자릿수 만족하면 부등호 맞는지 확인
    bool flag=true;
    if(cnt==k+1){
        for(int i=0; i<k; i++){
            int a = temp[i]-'0';
            int b = temp[i+1]-'0';
            if(op[i]=='<'){
                if(a>b) flag=false;
            }
            else if(op[i]=='>'){
                if(a<b) flag=false;
            }
            if(!flag) break;
        }
        if(!flag) return;


        if(!b){
            for(int i=0; i<=k; i++){
                ans_min.push_back(temp[i]);
            }
        } 
        else if(b){
            for(int i=0; i<=k; i++){
                ans_max.push_back(temp[i]);
            }
        }
        return;
    }


    if(!b){
        for(int i=0; i<=9; i++){
            if(check[i]) continue;

            check[i]=true;
            temp.push_back(i+'0'); 
            func(cnt+1, b);
            temp.pop_back();
            check[i]=false;
        }
    }
    else if (b){
            for(int i=9; i>=0; i--){
            if(check[i]) continue;

            check[i]=true;
            temp.push_back(i+'0');
            func(cnt+1, b);
            temp.pop_back();
            check[i]=false;
        }
    }

}

int main(){
    cin >> k;

    for(int i=0; i<k; i++){
        cin >> op[i];
    }

    func(0, 0);
    func(0, 1);

    for(int i=0; i<=k; i++){
        cout << ans_max[i];
    } cout << '\n';

    for(int i=0; i<=k; i++){
        cout << ans_min[i];
    } cout << '\n';

}