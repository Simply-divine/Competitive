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
		int n=in.nextInt();
		int w = in.nextInt();
		int wt[] = new int[n+1];
		int v[] = new int[n+1];
		for(int i=1;i<=n;i++){
			wt[i] = in.nextInt();
			v[i] = in.nextInt();
		}
		int dp[][] = new int[n+1][w+1];
		//for(int i=0;i<n;i++)dp[i][0] = 0;
		for(int i =1 ; i <= n;i++){
			for(int j=1;j<=w;j++){
				if(wt[i]>j){
					//if(i==0)dp[i][j]=0;
					//else
					dp[i][j] = dp[i-1][j];
				}
				else{
					//if(i==0)dp[i][j] = v[i];
					//else
					dp[i][j] = Math.max(dp[i-1][j-wt[i]]+v[i],dp[i-1][j]);
				}
			}
		}
		out.println(dp[n][w]);
		out.flush();
		out.close();  
	}

}



