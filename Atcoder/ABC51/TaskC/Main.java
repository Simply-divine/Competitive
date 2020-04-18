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
		int sx = in.nextInt();
		int sy = in.nextInt();
		int tx = in.nextInt();
		int ty = in.nextInt();
		for(int i = 0 ; i < ty - sy ; i++){
			out.print("U");
		}
		for(int i = 0 ; i < tx - sx;i++){
			out.print("R");
		}
		for(int i = 0; i < ty-sy;i++){
			out.print("D");
		}
		for(int i = 0; i < tx-sx;i++){
			out.print("L");
		}
		out.print("L");
		for(int i = 0;i<=ty-sy;i++){
			out.print("U");
		}
		for(int i = 0; i <= tx - sx ; i++){
			out.print("R");
		}
		out.print("D");	
		out.print("R");
		for(int i = 0; i <=ty-sy;i++){
			out.print("D");
		}
		for(int i = 0; i<=tx-sx;i++){
			out.print("L");
		}
		out.print("U");
		out.flush();
		out.close();  
	}

}



