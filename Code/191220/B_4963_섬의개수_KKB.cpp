#include <cstdio>
#include <string.h>
#include <queue>
#include <utility>
using namespace std;

const int MAX=100;

int w,h;
int r,c;
int idx;
int dr[]={-1,-1,-1,0,0,1,1,1};
int dc[]={-1,0,1,-1,1,-1,0,1};
int map[MAX][MAX];
bool check[MAX][MAX];


void BFS(int x,int y){
    queue<pair<int,int> > q;
    check[x][y]=true;
    q.push(make_pair(x,y));
    while(!q.empty()){
        r=q.front().first;
        c=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(0<=nr&&nr<h&&0<=nc&&nc<w){
                if(!check[nr][nc]&&map[nr][nc]==1){
                    q.push(make_pair(nr,nc));
                    check[nr][nc]=true;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d",&w,&h);
    while(!(w==0&&h==0)){
        memset(map,0,sizeof(map));
        memset(check,0,sizeof(check));
        idx=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                scanf("%d",&map[i][j]);
            }
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(map[i][j]==1){
                    if(!check[i][j]){
                        BFS(i,j);
                        idx++;
                    }
                }
            }
        }
        printf("%d\n",idx);
        scanf("%d %d",&w,&h);
    }
    return 0;
}