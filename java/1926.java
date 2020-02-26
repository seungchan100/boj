import java.util.*;


public class Main {
	
	static int max = -1;
	static int num = 0;
	static int map[][] = new int[510][510];
	static int dr[] = {0, 1, -1, 0}, dc[] = {1, 0, 0, -1};
	static int N, M;
	
	public static boolean isValid(int r, int c){
		return r>=0 && r<N && c>=0 && c<M;
	}
	
	public static int spread(int r, int c, boolean isStart){
		if(map[r][c] < 1) return 0;
		int size = 1;
		if(isStart){
			isStart = false;
			num++;
		}
		map[r][c] = -1;
		
		for(int i=0;i<4;i++){
			if(isValid(r+dr[i], c+dc[i]))
				size += spread(r+dr[i], c+dc[i], false);
		}
		return size;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();
		
		int r, c;
		for(r=0;r<N;r++){
			for(c=0;c<M;c++){
				map[r][c] = sc.nextInt();
			}
		}
		
		for(r=0;r<N;r++){
			for(c=0;c<M;c++){
				int t = spread(r, c, true);
				if(max<t) max = t;
			}
		}
		
		System.out.printf("%d\n%d", num, max);
	}

}
