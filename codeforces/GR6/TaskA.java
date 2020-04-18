import java.io.*;
import java.util.*;

public class TaskA{

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
	public static void solve(char[] s,int n){
		int sum = 0;
		int zero = -1;
		for(int i = 0; i<s.length;i++){
			sum+=s[i]-'0';
			if(s[i]=='0')zero = i;
		}
		if(sum%3!=0||zero==-1){
			System.out.println("cyan");
			return;
		}
		boolean check = false;
		for(int i = 0;i<s.length;i++){
			if(i!=zero){
				if((s[i]-'0')%2==0)check = true;
			}
		} 
		if(!check){
			System.out.println("cyan");
			return;
		}
		System.out.println("red");
		return;
	}
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
			
		for(int i = 0; i< n;i++){
			char[] s = in.next().toCharArray();
			solve(s,n);	
		}
					
		out.flush();
		out.close();  
	}

}



