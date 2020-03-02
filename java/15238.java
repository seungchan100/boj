import java.util.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int len = sc.nextInt();
		String str = sc.next();
		int cnt[] = new int[30];
		for(int i=0;i<len;i++){
			cnt[str.charAt(i)-'a']++;
		}
		int max = -1, solIndex = 0;
		for(int i=0;i<30;i++){
			if(cnt[i] > max){
				max = cnt[i];
				solIndex = i;
			}
		}
		System.out.printf("%c %d", solIndex+'a' ,max);
	}

}
