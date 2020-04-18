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
	public static void solve(int n){
		int b0,b1,b2,b3;
		b0 = (n&(0x000000ff))<<24;
		b1 = (n&(0x0000ff00))<<8;
		b2 = (n&(0x00ff0000))>>>8;
		b3 = (n&(0xff000000))>>>24;
		int sum = b0|b1|b2|b3;
		out.println(n+" converts to "+sum);
		return;

	}
	public static void main(String[] args){
		try{

			while(true){
				String s = in.nextLine();
				if(s.length()>0){
					int n =Integer.parseInt(s);
					solve(n);
				}else break;
			}

		}catch(Exception e){

		}		
		out.flush();
		out.close();  
	}

}



