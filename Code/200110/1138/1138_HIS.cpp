#include <iostream>
#include <vector>
using namespace std;

int a[11];
int b[11];
int n;
bool check[11];

vector <int> v;

void func(int cnt){
    if(cnt==n){

        for(int i=0; i<n; i++){
            int temp=0;
            for(int j=0; j<i; j++){
                if(i==0){
                    
                }
                else{
                    if(v[i] < v[j]){
                        temp += 1;
                    }
                }
            }

            if( temp != b[v[i]]){
                return;
            }
        }

        for(int i=0; i<n; i++){
            cout << v[i]+1 << ' ';
        } cout << '\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(check[i]==true) continue;

        check[i]=true;
        v.push_back(a[i]);
        func(cnt+1);
        v.pop_back();
        check[i]=false;
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        a[i]=i;
        cin >> b[i];
    }

    func(0);
    return 0;
}