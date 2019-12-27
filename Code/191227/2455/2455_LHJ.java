import java.util.*;
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int ans=0;
		int sum=0;
		Scanner sc=new Scanner(System.in);
		for(int i=0; i<4; i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			sum+=b;
			sum-=a;
			ans=Math.max(ans, sum);
		}
		System.out.println(ans);
	}
}
