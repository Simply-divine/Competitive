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
		int m = in.nextInt();
		int a[] = new int[n];
		int b[] = new int[n];
		int c[] = new int[m];
		int d[] = new int[m];

		for(int i =0; i<n;i++){
			a[i] = in.nextInt();
			b[i] = in.nextInt();
		}
		for(int i =0; i < m;i++){
			c[i] = in.nextInt();
			d[i] = in.nextInt();
		}	
		int prevres = 0;
		int min = 0;
		for(int i = 0; i < n; i++){
			int res = Integer.MAX_VALUE;
			for(int j = 0; j < m;j++){
				prevres = res;
				res = Math.min(Math.abs(c[j]-a[i])+Math.abs(d[j]-b[i]),res);
				if(res!=prevres)
				min = j+1;
				
			}
			out.println(min);
			
		}	
		out.flush();
		out.close();  
	}

}



