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
	public static void solve(int testNumber,FastReader in,PrintWriter out){
		char[] s = in.next().toCharArray();
		for(int i = 0; i < s.length-1;i++){
			if(s[i]==s[i+1]&&s[i]!='?'){
				out.println("-1");
				return;
			}

		}
		if(s[0] == '?'){
			if(s.length>1){
				if(s[1] == 'a'){
					s[0] = 'b';
				}
				else if(s[1]=='b'){
					s[0] = 'c';
				}
				else if(s[1]=='c'){
					s[0] = 'a';
				}
				else s[0]='a';
			}
			else s[0] = 'a';
		}
		for(int i = 1; i < s.length-1; i++){
			if(s[i] == '?'){
				if(s[i+1]=='?'){
					if(s[i-1]=='a'){
						s[i] = 'b';
					}
					else if(s[i-1] == 'b'){
						s[i] = 'c';
					}
					else s[i] = 'a';
				}
				else{
					if(s[i-1]!=s[i+1])
						s[i] = (char)(s[i-1]^s[i+1]^'a'^'b'^'c');
					else{
						if(s[i-1]=='a')s[i] = 'b';
						else if(s[i-1]=='b')s[i] = 'c';
						else s[i] = 'a';
					}
				}
			}
		}
		int len = s.length;
		if(s[len-1]=='?'){
			if(s[len-2]=='a'){
				s[len-1] = 'b';
			}
			else if(s[len-2]=='b'){
				s[len-1] = 'c';
			}
			else s[len-1] = 'a';
		}
		for(int i = 0;i<s.length;i++){
			out.print(s[i]);
		}
		out.println();
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



