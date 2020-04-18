import java.io.*;
import java.util.*;

public class TaskB{

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
	
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		long n = in.nextLong();
		for(long i =0; i < n ; i++){
			long a = in.nextLong();
			if(a<15){
				System.out.println("NO");
				continue;
			}
			long x = a%14;
			
			if(x>0&&x<7){
				System.out.println("YES");

			}
			else{
				System.out.println("NO");
			}
		}
		out.flush();
		out.close();  
	}

}



