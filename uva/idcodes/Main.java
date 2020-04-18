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
	static void solve(String s){
		
	
	}
	public static void main(String[] args){
		String s ;
		while(true){
			s = in.nextInt();
			if(s.equals("#"))break;
			solve(s);
		}	
		out.flush();
		out.close();  
	}

}



