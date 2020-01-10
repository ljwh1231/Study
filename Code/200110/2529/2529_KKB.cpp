#include <iostream>
#include <string.h>
using namespace std;

const int MAX = 20;

int numStr,numNum;
int NUMBERS[MAX];
char STRINGS[MAX];
bool isOff,isMin;
bool check[MAX];

bool isOkay(int depth){
	if(depth==0) return true;
	else{
		if(STRINGS[depth-1]=='>'){
			if(NUMBERS[depth-1]>NUMBERS[depth]) return true;
		}
		else{
			if(NUMBERS[depth-1]<NUMBERS[depth]) return true;
		}
	}
	return false;
}

void inequal(int depth){
	if(isOff) return;
	if(depth==numNum){
		for(int i=0;i<numNum;i++) cout<<NUMBERS[i];
		cout<<endl;
		isOff=true;
		return;
	}
	else{
		if(isMin){
			for(int i=0;i<=9;i++){
				if(!check[i]){
					check[i]=true;
					NUMBERS[depth]=i;
					if(isOkay(depth)) inequal(depth+1);
					check[i]=false;
				}
			}
		}
		else{
			for(int i=9;i>=0;i--){
				if(!check[i]){
					check[i]=true;
					NUMBERS[depth]=i;
					if(isOkay(depth)) inequal(depth+1);
					check[i]=false;
				}
			}
		}
	}
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	
	//freopen("input.txt","r",stdin);
	cin>>numStr;
	numNum=numStr+1;
	for(int i=0;i<numStr;i++) cin>>STRINGS[i];
	
	isOff=false;
	memset(NUMBERS,0,sizeof(NUMBERS));
	memset(check,0,sizeof(check));
	isMin=false;
	inequal(0);
	isOff=false;
	memset(NUMBERS,0,sizeof(NUMBERS));
	memset(check,0,sizeof(check));
	isMin=true;
	inequal(0);
	
	return 0;
}
