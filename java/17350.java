import java.util.*;


public class Main {
	
	public static boolean test(){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-->0){
			String s = sc.next();
			if("anj".equals(s)) return true;
		}
		return false;
	}
	
	public static void main(String[] args) {
		System.out.println("뭐야" + (test()?";":"?"));
	}

}
