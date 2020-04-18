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
		int n= in.nextInt();
		long[] a = new long[n];
		long[] pre = new long[n];
		for(int i =0;i<n;i++){
			a[i]= in.nextLong();
		}
		long[]total =new long[2];
		long[] cnt =new long[2];

		for(int i=0;i<2;i++){
			for(int j=0;j<n;j++){
				total[i]+=a[j];
				if((i+j)%2==0){
					if(total[i]>=0){
						cnt[i]+=(total[i]+1);
						total[i]=-1;
					}
				}else{
					if(total[i]<=0){
						cnt[i]+=-(total[i]-1);
						total[i]=1;
					}
				
				}
				
			}
		}
		long min = Math.min(cnt[0],cnt[1]);

		out.println(min);
		out.flush();
		out.close();  
	}

}



