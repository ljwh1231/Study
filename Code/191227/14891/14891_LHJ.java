import java.util.*;
public class Main {
	public static int[][] gear;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		gear=new int[4][8];
		for(int i=0; i<4; i++) {
			String temp=sc.next();
			for(int j=0; j<8; j++) {
				gear[i][j]=Integer.parseInt(temp.substring(j,j+1));
			}
		}
		int k=sc.nextInt();
		for(int i=0; i<k; i++) {
			int n=sc.nextInt()-1;
			int dir=sc.nextInt();
			
			Queue<Integer> que=new LinkedList<Integer>();
			Queue<Integer> store=new LinkedList<Integer>();
			int[] visited=new int[4];
			que.add(n);
			visited[n]=dir;
			while(!que.isEmpty()) {
				int q=que.poll();
				store.add(q);
				if(q+1<4 && visited[q+1]==0) {
					if(gear[q][2]!=gear[q+1][6]) {
						que.add(q+1);
						visited[q+1]=visited[q]*-1;
					}
				}
				if(q-1>=0 && visited[q-1]==0) {
					if(gear[q][6]!=gear[q-1][2]) {
						que.add(q-1);
						visited[q-1]=visited[q]*-1;
					}
				}
			}
			while(!store.isEmpty()) {
				int s=store.poll();
				rotate(s,visited[s]);
			}
		}
		int ans=0;
		for(int i=0; i<4; i++) {
			if(gear[i][0]==1) {
				ans+=Math.pow(2, i);
			}
		}
		System.out.println(ans);
	}
	public static void rotate(int idx, int dir) {
		int[] copy=new int[8];
		for(int i=0; i<8; i++) {
			copy[i]=gear[idx][i];
		}
		if(dir==1) {
			gear[idx][0]=copy[7];
			for(int i=1; i<8; i++) {
				gear[idx][i]=copy[i-1];
			}
		}else if(dir==-1){
			gear[idx][7]=copy[0];
			for(int i=0; i<7; i++) {
				gear[idx][i]=copy[i+1];
			}
		}
	}
}
