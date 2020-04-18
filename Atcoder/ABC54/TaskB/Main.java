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
	public static boolean go(char[][] a,char[][] b,int m,int n){
		for(int i = 0 ; i + m <= n;i++){
			for(int j =0;j+m<=n;j++){
				boolean ok = true;
				for(int k = 0; k < m;k++){
					for(int l = 0; l < m;l++){
						if(a[i+k][j+l]!=b[k][l]) ok = false;
					}
				}
				if(ok){
					return true;	
				}	
			}
		}
		return false;	
	}	
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int  m = in.nextInt();
		char[][] a = new char[n][n];
		char[][] b = new char[m][m];
		for(int i = 0; i < n ; i++){
			a[i] = in.next().toCharArray();
		}
		for(int i = 0 ; i < m ; i++){
			b[i] = in.next().toCharArray();
		}
		boolean check = go(a,b,m,n);
		if(check){
			out.println("Yes");
		}
		else{
			out.println("No");
		}
		out.flush();
		out.close();  
	}

}



