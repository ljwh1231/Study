#include <cstdio>

const int MAX = 30;

int row,col;
int cmd,dir;
int x,y;
int dice[6]={0,};
int map[MAX][MAX];

int main(int argc, const char * argv[]) {
    
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d %d %d",&row,&col,&x,&y,&cmd);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",&map[i][j]);
        }
    }
    for(int i=0;i<cmd;i++){
        scanf("%d",&dir);
        // 동
        if(dir==1){
            y++;
            if(x<0||x>=row||y<0||y>=col) {
                y--;
                continue;
            }
            int temp;
            temp = dice[0];
            dice[0] = dice[3];
            dice[3] = dice[5];
            dice[5] = dice[2];
            dice[2] = temp;
            if(map[x][y]==0){
                map[x][y]=dice[5];
            }
            else{
                dice[5]=map[x][y];
                map[x][y]=0;
            }
            printf("%d\n",dice[0]);
        }
        // 서
        else if(dir==2){
            y--;
            if(x<0||x>=row||y<0||y>=col) {
                y++;
                continue;
            }
            int temp;
            temp = dice[0];
            dice[0] = dice[2];
            dice[2] = dice[5];
            dice[5] = dice[3];
            dice[3] = temp;
            if(map[x][y]==0){
                map[x][y]=dice[5];
            }
            else{
                dice[5]=map[x][y];
                map[x][y]=0;
            }
            printf("%d\n",dice[0]);
        }
        // 북
        else if(dir==3){
            x--;
            if(x<0||x>=row||y<0||y>=col) {
                x++;
                continue;
            }
            int temp;
            temp = dice[0];
            dice[0] = dice[4];
            dice[4] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
            if(map[x][y]==0){
                map[x][y]=dice[5];
            }
            else{
                dice[5]=map[x][y];
                map[x][y]=0;
            }
            printf("%d\n",dice[0]);
        }
        // 남
        else if(dir==4){
            x++;
            if(x<0||x>=row||y<0||y>=col) {
                x--;
                continue;
            }
            int temp;
            temp = dice[0];
            dice[0] = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[4];
            dice[4] = temp;
            if(map[x][y]==0){
                map[x][y]=dice[5];
            }
            else{
                dice[5]=map[x][y];
                map[x][y]=0;
            }
            printf("%d\n",dice[0]);
        }
    }
    
    return 0;
}

