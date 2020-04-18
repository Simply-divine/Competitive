import java.io.*;
import java.util.*;

public class TaskC{

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
		int r = in.nextInt();
		int c = in.nextInt();
		int ans =  0;
		int a[][] = new int[r][c];
		boolean check = true;
		if(r>=2&&c>=2)
		for(int i = 0; i< r ;i++){
			for(int j = 0; j <c;j++){
				a[i][j] = (i+1)*(r+j+1);			
			} 
			
		}
		else{
			if(r>=2||c>=2){
				for(int i = 0 ; i < Math.max(r,c);i++){
					if(c>=2)a[0][i] = i + 2;
					else a[i][0] = i + 2;
				}
			}
			else{
				out.println("0");
				check = false;
			}
		
		}
		if(check)
		for(int i = 0;i<r;i++){
			for(int j = 0;j<c;j++){
				out.print(a[i][j]+" ");
			}
			out.println();
		}	
		out.flush();
		out.close();  
	}

}



