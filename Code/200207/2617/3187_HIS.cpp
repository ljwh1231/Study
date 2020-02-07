#include <iostream>
#include <queue>
using namespace std;

int r,c;
char map[255][255];
bool check[255][255];

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};

int v_cnt=0;
int k_cnt=0;

void bfs(int a, int b){
    int v_tmp=0;
    int k_tmp=0;
    queue <pair<int,int> > q;

    q.push(make_pair(a,b));
    check[a][b]=true;
    if(map[a][b]=='v') v_tmp++;
    else if(map[a][b]=='k') k_tmp++;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(0<=nx && nx<r && 0<=ny && ny<c){
                if(map[nx][ny]!='#' && !check[nx][ny]){
                    check[nx][ny]=true;
                    q.push(make_pair(nx,ny));
                    if(map[nx][ny]=='v') v_tmp++;
                    if(map[nx][ny]=='k') k_tmp++;
                }
            }
        }
    }

    if(k_tmp > v_tmp){
        k_cnt += k_tmp;
    }
    else {
        v_cnt += v_tmp;
    }
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; i++){
        cin >> map[i];
    } // input


    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j]!='#' && !check[i][j]){
                bfs(i, j);
            }
        }
    }

    cout << k_cnt << ' ' << v_cnt;
    
    return 0;
}