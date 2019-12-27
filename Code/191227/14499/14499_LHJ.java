import java.util.*;
public class Main {
	public static int N,M;
	public static int[][] map;
	
	public static int[] dx= {0,0,0,-1,1};
	public static int[] dy= {0,1,-1,0,0};
	public static void changeDice(int dir,int[] dice) {
		int[] copy=new int[7];
		for(int i=1; i<7; i++) {
			copy[i]=dice[i];
		}
		if(dir==1) {
			dice[1]=copy[4];
			dice[3]=copy[1];
			dice[4]=copy[6];
			dice[6]=copy[3];
		}
		if(dir==2) {
			dice[1]=copy[3];
			dice[3]=copy[6];
			dice[4]=copy[1];
			dice[6]=copy[4];
		}
		if(dir==3) {
			dice[1]=copy[5];
			dice[2]=copy[1];
			dice[5]=copy[6];
			dice[6]=copy[2];
		}
		if(dir==4) {
			dice[1]=copy[2];
			dice[2]=copy[6];
			dice[5]=copy[1];
			dice[6]=copy[5];
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int M=sc.nextInt();
		map=new int[N][M];
		int x=sc.nextInt();
		int y=sc.nextInt();
		int k=sc.nextInt();
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				map[i][j]=sc.nextInt();
			}
		}
		int[] dir=new int[k];
		for(int i=0; i<k; i++) {
			dir[i]=sc.nextInt();
		}
		//-----------------------------입력 끕
		int[] dice=new int[7];
		for(int i=0; i<k; i++) {
			int nx=x+dx[dir[i]];
			int ny=y+dy[dir[i]];
			if(nx>=0 && ny>=0 && nx<N && ny<M) {
				changeDice(dir[i],dice);
				if(map[nx][ny]==0) {
					map[nx][ny]=dice[6];
				}else {
					dice[6]=map[nx][ny];
					map[nx][ny]=0;
				}
				x=nx;y=ny;
				System.out.println(dice[1]);
			}
		}
		
	}

}
