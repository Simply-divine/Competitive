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
	static void lenofmin(int l , int r){
		
	
	}
	public static void main(String[] args){
		int n = in.nextInt();
		int q = in.nextInt();
		int a[] = new int[n];
		
		for(int i = 0; i < n;i++){
			a[i] = in.nextInt();
			
		}
		while(q-->0){
			int l = in.nextInt();
			int r = in.nextInt();
			int ans1 = lenofmax(l,r);
			int ans2 = lenofmin(l,r);
			if(ans1==ans2)out.println("YES");
			else out.println("NO");
		}
		
		out.flush();
		out.close();  
	}

}



