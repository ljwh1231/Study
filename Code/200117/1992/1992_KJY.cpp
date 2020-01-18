#include <iostream>
#include <vector>
using namespace std;
int N;
int input[65][65];
vector<char> output;

void tree(int a, int b, int size){
    bool k = true;

    for(int i=a; i<a+size; i++){
        for(int j=b; j<b+size; j++){
            if(input[i][j] != input[a][b]){
                k = false;
            }
        }
    }

    if(k){
        if(input[a][b] == 1){ output.push_back('1'); }
        else{output.push_back('0');}
    }else{
        output.push_back('(');
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                tree(a+i*(size/2), b+j*(size/2), size/2);
            }
        }
        output.push_back(')');
    }

}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &input[i][j]);
        }
    }
    tree(0, 0, N);
    for(int i=0; i<output.size(); i++){
        cout << output[i];
    }
}