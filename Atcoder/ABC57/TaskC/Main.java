import java.io.*;
import java.util.*;

public class Main{

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
		long minDiff = (long)(1e11);
		long maxterm = 0;
		for(long i = 1;i*i<=n;i++){
			if(n%i==0){
				minDiff = Math.min(minDiff,n/i-i);
				maxterm = n/i;
			}

		}
		int length = 0;
		while(maxterm>0){
			length++;
			maxterm/=10;
		}	
		out.println(length);
		out.flush();
		out.close();  
	}

}



