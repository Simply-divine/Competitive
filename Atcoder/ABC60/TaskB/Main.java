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
	public static void go(int a,int b,int c,PrintWriter out){

		for(int i=1;i<=1000;i++){
			if((b*i+c)%a==0){
				out.println("YES");
				return;
			}
		}		
		out.println("NO");
		return;

	}	
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		go(a,b,c,out);
		out.flush();
		out.close();  
	}

}



