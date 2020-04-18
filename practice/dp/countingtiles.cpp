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
#define INF std::numeric_limits<int>::max()-1
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
	int n,m;
	cin>>n>>m;
	int blocks = 0;
	int p=0;
	if(n<m){
		int temp = m;
		m = n;
		n = temp;
	}
	int count[n+1][(1<<m)+1];
	int cnt = 0;
	REP(i,0,(1<<m)){
		count[0][i] = 1;
	}
	REP(i,1,n){
		REP(j,0,(1<<m)){
			bitset<10> s((j));
			count[i][j] = count[i-1][j]*(m-s.count());  	
		}	
	}
	int ans = 1;
	REP(i,1,n){
		ans+=count[i][(1<<m)-1];
	}
	cout<<ans;
	return 0;
}




