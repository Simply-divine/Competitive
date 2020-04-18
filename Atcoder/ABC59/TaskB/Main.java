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
		String s1 = in.next();
		String s2 = in.next();
		if(s1.length()>s2.length())out.println("GREATER");
		else if (s1.length()<s2.length())out.println("LESS");
		else{
			int cmp = s1.compareTo(s2);
			if(cmp==0){
				out.println("EQUAL");
			}
			else if(cmp>0)out.println("GREATER");
			else out.println("LESS");	


		}
		out.flush();
		out.close(); 
	}

}

