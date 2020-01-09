#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 510;
int row,col;
int maxVal;
int map[MAX][MAX];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
bool visited[MAX][MAX];

void tetro(int r,int c,int depth, int sum){
    if(depth==4){
        maxVal=max(maxVal,sum);
        return;
    }
    else{
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr<0||nr>=row||nc<0||nc>=col) continue;
            if(!visited[nr][nc]){
                visited[nr][nc]=true;
                tetro(nr,nc,depth+1,sum+map[r][c]);
                visited[nr][nc]=false;
            }
        }
    }
}

void excepted(int r,int c){
    if(0<=c-1&&c+1<col&&r+1<row){
        maxVal=max(maxVal,map[r][c-1]+map[r][c]+map[r][c+1]+map[r+1][c]);
    }
    if(0<=c-1&&c+1<col&&0<=r-1){
        maxVal=max(maxVal,map[r-1][c]+map[r][c-1]+map[r][c]+map[r][c+1]);
    }
    if(0<=r-1&&r+1<row&&c+1<col){
        maxVal=max(maxVal,map[r-1][c]+map[r][c]+map[r+1][c]+map[r][c+1]);
    }
    if(0<=r-1&&r+1<row&&0<=c-1){
        maxVal=max(maxVal,map[r-1][c]+map[r][c]+map[r+1][c+1]+map[r][c-1]);
    }
}

int main(){
    freopen("input.txt","r",stdin);
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>map[i][j];
        }
    }
    maxVal=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            visited[i][j]=true;
            tetro(i,j,0,0);
            visited[i][j]=false;
            excepted(i,j);
        }
    }
    cout<<maxVal<<endl;
    return 0;
}