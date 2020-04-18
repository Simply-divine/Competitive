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
	public static void seive(boolean[] dp,int n){
		for(int i = 1; i <= n; i++){
			dp[i] = true;
		}
		dp[1] = false;
		for(int i = 2; i*i <= n; i++){
			for(int j = i*i; j <=n ; j+=i){
				dp[j] = false;
			}
		}
	}
	public static int exp(int x,int n){
		int exp = 0;
		int p = x;
		while(n/p>0){
			exp+= n/p;
			p = p*x;
		}
		return exp;
	}
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		boolean div[] = new boolean[n+1];
		int sum = 0;
		int mod=(int)(1e9)+7;
		boolean dp[] = new boolean[n+1];
		seive(dp,n);
		int tmp = 0;
		long ans = 1;
		for(int i = 1; i <= n ; i++){
			if(dp[i])
			{	
				tmp = exp(i,n);
				ans = (ans*(tmp+1)%mod);
			}
		}
		out.println(ans);
		out.flush();
		out.close();  
	}

}



