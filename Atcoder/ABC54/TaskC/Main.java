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
	static ArrayList<Node> nodes = new ArrayList<>();
	static int count = 0;
	static int n;
	static class Node{
		ArrayList<Node> adj = new ArrayList<>();
		int i;
		Node(int i ){
			this.i = i;
		}
		
	}
	static void dfs(int src,boolean[] visited,int size){
		if(size==n)count++;
		for(Node adj :nodes.get(src).adj){
			if(!visited[adj.i]){
				visited[adj.i] = true;
				dfs(adj.i,visited,size+1);
				visited[adj.i] = false;
			}
		} 
	}
	public static void main(String[] args){
		FastReader in = new FastReader();
		PrintWriter out = new PrintWriter(System.out);
		n = in.nextInt();
		int m = in.nextInt();
		for(int i = 0 ; i < n; i++)nodes.add(new Node(i));
		for(int i = 0 ; i<m;i++){
			int v1 = in.nextInt()-1;
			int v2 = in.nextInt()-1;
			nodes.get(v1).adj.add(nodes.get(v2));
			nodes.get(v2).adj.add(nodes.get(v1));

		}
		int size = 1;
		boolean visited[] = new boolean[n];
		visited[0] = true;
		dfs(0,visited,size);
		out.println(count);
		out.flush();
		out.close();  
	}

}



