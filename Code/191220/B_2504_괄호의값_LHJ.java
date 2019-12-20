import java.util.*;
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		String s=sc.nextLine();
		Stack<String> stack=new Stack<String>();
		
		int small=0;
		int large=0;
		for(int i=0; i<s.length(); i++) {
			if(s.charAt(i)=='(') {
				stack.add("(");
				small+=1;
			}
			if(s.charAt(i)=='[') {
				stack.add("[");
				large+=1;
			}
			if(s.charAt(i)==')') {
				if(small==0) {
					System.out.println(0);
					return;
				}
				int count=0;
				while(!stack.peek().equals("(")) {
					String temp=stack.pop();
					if(temp.equals("[")) {
						System.out.println(0);
						return;
					}
					count+=Integer.parseInt(temp);
				}
				stack.pop();
				if(count==0) {
					stack.push("2");
				}else {
					stack.push(""+(2*count));
				}
				small-=1;
				
			}
			if(s.charAt(i)==']') {
				if(large==0) {
					System.out.println(0);
					return;
				}
				int count=0;
				while(!stack.peek().equals("[")) {
					String temp=stack.pop();
					if(temp.equals("(")) {
						System.out.println(0);
						return;
					}
					count+=Integer.parseInt(temp);
				}
				stack.pop();
				if(count==0) {
					stack.push("3");
				}else {
					stack.push(""+(3*count));
				}
				large-=1;
			}
		}
		if(small!=0 || large!=0) {
			System.out.println(0);
			return;
		}
		int ans=0;
		while(!stack.isEmpty()) {
			ans+=Integer.parseInt(stack.pop());
		}
		System.out.println(ans);

	}

}
