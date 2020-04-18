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
		int n = in.nextInt();
		int T = in.nextInt();
		int[] t = new int[n+1];	
		for(int i =0;i<n;i++){
			t[i] = in.nextInt();
		}
		t[n] = Integer.MAX_VALUE;
		long ontime=0;
		for(int i=1;i<=n;i++){
			
			ontime+=Math.min(T,t[i]-t[i-1]);

		}
		out.println(ontime);
		out.flush();
		out.close();  
	}

}



