#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define SQ(a) (a)*(a)
#define DEBUG printf("hello\n")
#define nl "\n"
#define INF std::numeric_limits<int>::max()
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
ll mod=1000000009;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//to calculate the edit distance between two strings a and b
	string a,b;
	cin>>a>>b;
	int n = a.size();
	int m = b.size();
	a =" "+a;
	b = " "+b;
	int distance[n+1][m+1];
	REP(i,0,n){
		REP(j,0,m)
			distance[i][j] = INF-1;
	}
	distance[0][0] = 0;
	REP(i,1,n){
		distance[i][0] = (i);
	//	cout<<distance[i][0];
	}
	REP(i,1,m){
		distance[0][i] = (i);
	}
	REP(i,1,n){
		REP(j,1,m)
		{
			if(a[i] == b[j])		
			distance[i][j] = min(distance[i-1][j]+1,min(distance[i][j-1]+1,distance[i-1][j-1]) );
			else distance[i][j] = min(distance[i-1][j]+1,min(distance[i][j-1]+1,distance[i-1][j-1]+1));
		}
	}
	REP(i,0,n){
		REP(j,0,n)cout<<distance[i][j]<<" ";
		cout<<nl;
	}
	cout<<distance[n][m];
	return 0;
}




