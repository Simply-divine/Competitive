import java.io.*;
import java.util.*;

public class Main{
static PrintWriter out = new PrintWriter(System.out);
static FastReader in = new FastReader();
	static class FastReader{
		BufferedReader br;
		StringTokenizer st;
		public FastReader(){
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		public String next(){
			try{
				while(st==null||!st.hasMoreElements()){
					st = new StringTokenizer(br.readLine());
				}
			}catch(Exception e){
				e.printStackTrace();
			}
			return st.nextToken();
	
		}
		public int nextInt(){
			return Integer.parseInt(next());
		}
		public long nextLong(){
			return Long.parseLong(next());
		}
		public double nextDouble(){
			return Double.parseDouble(next());
		}
		public String nextLine(){
			String s = "";
			try{
				s = br.readLine();
			}catch(Exception e){
				e.printStackTrace();
			}	
			return s;		
		}
	} 
	static void solve(){
		int n = in.nextInt();
		int[] val = new int[256];
		for(int i =0;i<n;i++){
			String s = in.next();
			int cost = in.nextInt();
			val[s.charAt(0)] = cost;
		}
		double sum = 0;
		int m = in.nextInt();
		for(int i = 0; i < m; i++){
			String s1 = in.nextLine();
			for(int j=0; j < s1.length();j++){
				sum+=val[s1.charAt(j)];
			}
		}
		out.printf("%.2f$",sum/100.00);
		
		out.println();
	}
	public static void main(String[] args){
		int n = in.nextInt();
		while(n-->0){
			solve();
		}	
		out.flush();
		out.close();  
	}

}



