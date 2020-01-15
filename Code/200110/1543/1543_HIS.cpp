#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string s;
    string want;
    getline(cin, s);
    getline(cin, want);

    int s_len=s.length();
    int w_len=want.length();
    int cnt=0;
    int st=0;
    
    for(int i=0; i<=s_len-w_len; i++){
        string div="";
        
        int tmp=st;
        for(int j=0; j<w_len; j++){ // 3 size 문자열만들기
            div += s[tmp];
            tmp++;
        }

        /*  
        * str1 < str2 : -1
        * str1 > str2 : 1
        * str1 = str2 : 0
        */
        bool flag=false;
        if( strcmp(div.c_str(), want.c_str()) == 0 ) {
            flag=true;
            cnt++;
        }

        if(flag) st += w_len;
        else st++;
    }

    cout << cnt;
}