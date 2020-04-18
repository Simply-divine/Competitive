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
	
	public static void main(String[] args){
		String s;
	//	List<Integer> li = new ArrayList<>();
	
		while(true){
			int n = in.nextInt();
			if(n==0)break;
			int a[] = new int[n];
			for(int i=0;i<n;i++)a[i] = in.nextInt();
			cnt=0;
			sort(a,0,a.length-1);	
			out.println(cnt);
		}
//		li.toArray(a);
		out.flush();
		out.close();  
	}
	static int cnt=0;
	public static void sort(int[] a,int lo,int hi){
		if(hi<=lo)return;
		
		int mid = lo+(hi-lo)/2;
		
		sort(a,lo,mid);
		sort(a,mid+1,hi);
		merge(a,lo,mid,hi);
	}

	public static void merge(int[] a,int lo,int mid,int hi){
		int[] aux = new int[a.length];
		int i=lo,j=mid+1,k = lo;
		while(i<=mid&&j<=hi){
			if(a[i]>a[j])aux[k++] = a[i++];
			else {
				aux[k++] = a[j++];
				cnt+=mid-i;
			}
		}
		while(i<=mid){
			aux[k++] = a[i++];
		}
		while(j<=hi){
			aux[k++] = a[j++];
		}
		for(int l =lo;l<=hi;l++)
			a[l] = aux[l];
		
	}

}



