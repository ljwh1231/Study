import java.util.*;
public class Main {
	public static int[] dx= {-1,-1,-1,0,0,1,1,1};
	public static int[] dy= {-1,0,1,-1,1,-1,0,1};
	public static int h;
	public static int w;
	public static int[][] map;
	public static class Pair{
		int x, y;
		Pair(int x,int y){
			this.x=x;
			this.y=y;
		}
	}
	public static void bfs(Pair point) {
		Queue<Pair> que=new LinkedList<Pair>();
		que.add(point);
		
		while(!que.isEmpty()) {
			Pair p=que.poll();
			for(int d=0; d<8; d++) {
				int nx=p.x+dx[d];
				int ny=p.y+dy[d];
				if(nx>=0 && nx<h && ny>=0 && ny<w && map[nx][ny]==1) {
					map[nx][ny]=0;
					que.add(new Pair(nx,ny));
				}
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		while(true) {
			w=sc.nextInt();
			h=sc.nextInt();
			if(w==0 && h==0) {
				break;
			}
			map=new int[h][w];
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					map[i][j]=sc.nextInt();
				}
			}
			int ans=0;
			for(int i=0; i<h; i++) {
				for(int j=0; j<w; j++) {
					if(map[i][j]==1) {
						map[i][j]=0;
						ans+=1;
						bfs(new Pair(i,j));
					}
				}
			}
			System.out.println(ans);
		}
	}

}
