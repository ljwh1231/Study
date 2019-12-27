#include <stdio.h>

const int MAX = 10;
int rot;
int sum;
int gears[4][MAX];
int isRotate[4][1];

void rotate(int gearIdx,int dir){
	// 시계
	if(dir == 1){
		int temp=gears[gearIdx][0];
		gears[gearIdx][0]=gears[gearIdx][7];
		gears[gearIdx][7]=gears[gearIdx][6];
		gears[gearIdx][6]=gears[gearIdx][5];
		gears[gearIdx][5]=gears[gearIdx][4];
		gears[gearIdx][4]=gears[gearIdx][3];
		gears[gearIdx][3]=gears[gearIdx][2];
		gears[gearIdx][2]=gears[gearIdx][1];
		gears[gearIdx][1]=temp;
	}
	else{
		int temp=gears[gearIdx][0];
		gears[gearIdx][0]=gears[gearIdx][1];
		gears[gearIdx][1]=gears[gearIdx][2];
		gears[gearIdx][2]=gears[gearIdx][3];
		gears[gearIdx][3]=gears[gearIdx][4];
		gears[gearIdx][4]=gears[gearIdx][5];
		gears[gearIdx][5]=gears[gearIdx][6];
		gears[gearIdx][6]=gears[gearIdx][7];
		gears[gearIdx][7]=temp;
	}
}


int main(){

	freopen("input1.txt","r",stdin);
	for(int i=0;i<4;i++){
		char status[MAX];
		scanf("%s",status);
		//printf("%s\n",status);
		for(int j=0;j<8;j++) gears[i][j]=status[j]-'0';
	}
	
	scanf("%d",&rot);
	for(int i=0;i<rot;i++){
		int gearNum;
		int dir;
		scanf("%d %d",&gearNum,&dir);
		// 기준 톱니의 왼쪽
		int theGear=gearNum;
		int theNum=gears[theGear][6];
		rotate(theGear,dir);
		while(theGear>=1){
			if(theNum!=gears[theGear-1][3]){						
				rotate(theGear-1,dir*-1);
				theGear--;
				theNum=
			}
			else {
				break;
			}
		}
		// 기준 톱니의 오른쪽 
		theGear=gearNum+1;
		while(theGear<=2){
			if(gears[theGear][3]!=gears[theGear+1][6]){
					rotate(theGear,dir);
					rotate(theGear+1,dir*-1);
					theGear++;
				}
				else {
					rotate(theGear,dir);
					break;
				}
		}
	}
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			printf("%d ",gears[i][j]);
		}printf("\n");
	}
	
	if(gears[0][0]==1) sum+=1;
	if(gears[1][0]==1) sum+=2;
	if(gears[2][0]==1) sum+=4;
	if(gears[3][0]==1) sum+=8;
	printf("%d\n",sum);
	return 0;
}
