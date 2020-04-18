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
	public class BIT{
		int size;
		int table[];
		BIT(int size){
			table = new int[size+1];
			this.size = size;
			Arrays.fill(table,0);
		}
		//update the position pos by delta
		void update(int pos,int delta){
			while(pos < size){
				table[pos]	+= delta;
				pos += Integer.lowestOneBit(pos);
			}
		}

		//calculate the sum of prefix [1,i]
		int add(int sum){
				int sum=0;	
				while ( i > 0){
						sum+=table[pos];
						pos-=Integer.lowestOneBit(pos);
				}
				return sum;
		}
		
		//the sum of values from l to r
		int rangesum(int l,int r){
			return sum(r) - sum(l-1);
		}
	
	}
	public static void solve(int testNumber,FastReader in,PrintWriter out){
			int n;
			Scanner n = in.nextInt();
			int a[] = new int[n];
			BIT bit = new BIT(n);
			for(int i = 0; i < n; i++){
				a[i] = in.nextInt();
				bit.update(i,a[i]);
			}	
			
	}
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		int t = in.nextInt();
		for(int i = 0; i < t;i++){
			solve(i,in,out);
		}
		out.flush();
		out.close();  
	}

}





